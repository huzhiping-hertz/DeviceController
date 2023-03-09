#include "DeviceInformation.h"
#include "OSMonitor/system.h"

void DeviceInformation::GetInformation(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{

    System system;
    Json::Value json;
    json["cpu"] = system.Cpu().Utilization();
    json["mem"] = system.MemoryUtilization();
    json["disk"] =RunCommand("df / -H --output=avail");
    json["os"] = system.OperatingSystem();
    json["kernel"] = system.Kernel();
    auto resp = HttpResponse::newHttpJsonResponse(json);
    callback(resp);
}

void DeviceInformation::DeviceReboot(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{
    Json::Value json;
    system("reboot");
    auto resp = HttpResponse::newHttpJsonResponse(json);
    callback(resp);
}

std::string DeviceInformation::RunCommand(std::string cmd) {
    std::shared_ptr<FILE> pipe(popen(cmd.c_str(), "r"), pclose);
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while (!feof(pipe.get())) {
        if (fgets(buffer, 128, pipe.get()) != NULL)
            result += buffer;
    }
    return result;
}