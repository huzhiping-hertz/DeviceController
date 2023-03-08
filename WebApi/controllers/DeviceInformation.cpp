#include "DeviceInformation.h"
#include "OSMonitor/system.h"

void DeviceInformation::GetInformation(const HttpRequestPtr &req,std::function<void (const HttpResponsePtr &)> &&callback)
{

    System system;
    Json::Value json;
    json["cpu"] = system.Cpu().Utilization();
    json["mem"] = system.MemoryUtilization();
    json["disk"]=0;
    json["os"]=system.OperatingSystem();
    json["kernel"]=system.Kernel();

    auto resp = HttpResponse::newHttpJsonResponse(json);
    callback(resp);
}

void DeviceInformation::DeviceReboot(const HttpRequestPtr &req,std::function<void (const HttpResponsePtr &)> &&callback)
{

}