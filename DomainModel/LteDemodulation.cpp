#include "LteDemodulation.h"

#include "LteUlDll.h"
#include "SystemUtility.h"

LteDemodulation::LteDemodulation(string params) : BaseTask(params, "LteUl") {}
LteDemodulation::~LteDemodulation() {}

void LteDemodulation::runTask() {
  json paramObj = json::parse(this->m_params);

  int nReturn = LTE_UL_STATUS_OK;

  int logToMode = LOG_TO_CONSOLE | LOG_TO_FILE;
  int logLevel = LOG_LEVEL_DEBUG;

  LteUlInputParam* pInputParam = new LteUlInputParam();
  LteUlOutputParam* pOutputParam = new LteUlOutputParam();

  string logPath = paramObj["log"].get<string>();
  string iqData = paramObj["data"].get<string>();
  int DutIndex = 0;

  LogInitByDutIndex(DutIndex, logToMode, logLevel, (char*)logPath.c_str(),
                    "LteUlDemodLogFile", true);

  DllLteUlLibEnter(DutIndex);
  DllLteUlInitDemodInputParamDefaul(DutIndex, pInputParam);

  pInputParam->BinFileLogFolder = (char*)logPath.c_str();
  pInputParam->DutIndex = DutIndex;
  pInputParam->IqDataPath = (char*)iqData.c_str();
  pInputParam->SampleRate = paramObj["SampleRate"].get<float>();
  pInputParam->SampleTime = paramObj["SampleTime"].get<float>();
  pInputParam->UserCellID = paramObj["UserCellID"].get<int>();
  pInputParam->UserRBOffset = paramObj["UserRBOffset"].get<int>();
  pInputParam->UserRBNumber = paramObj["UserRBNumber"].get<int>();
  pInputParam->UserDelta_ss = paramObj["UserDelta_ss"].get<int>();
  pInputParam->Usern_1_DMRS = paramObj["Usern_1_DMRS"].get<int>();
  pInputParam->Usern_2_DMRS = paramObj["Usern_2_DMRS"].get<int>();
  pInputParam->Userseq_hop_enabled =
      static_cast<SeqHopEnabled>(paramObj["Userseq_hop_enabled"].get<int>());
  pInputParam->Usergroup_hop_enabled = static_cast<GroupHopEnabled>(
      paramObj["Usergroup_hop_enabled"].get<int>());
  pInputParam->UserBW = paramObj["UserBW"].get<int>();
  pInputParam->UserDMRSBoostdB = paramObj["UserDMRSBoostdB"].get<int>();
  pInputParam->UserModulation =
      static_cast<LteModulationMode>(paramObj["UserModulation"].get<int>());

  DllLteUlDemod(DutIndex, pInputParam, pOutputParam);
  DllLteUlLibExit(DutIndex);

  LogCleaupByDutIndex(DutIndex);

  delete pInputParam;
  delete pOutputParam;
}
