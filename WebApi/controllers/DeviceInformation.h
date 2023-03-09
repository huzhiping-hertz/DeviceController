#pragma once
#include <drogon/HttpController.h>
using namespace drogon;
class DeviceInformation:public drogon::HttpController<DeviceInformation>
{
public:

    METHOD_LIST_BEGIN
    ADD_METHOD_TO(DeviceInformation::GetInformation,"/device/info",Get);
    ADD_METHOD_TO(DeviceInformation::DeviceReboot,"/device/reboot",Post);
    METHOD_LIST_END

    void GetInformation(const HttpRequestPtr &req,std::function<void (const HttpResponsePtr &)> &&callback);

    void DeviceReboot(const HttpRequestPtr &req,std::function<void (const HttpResponsePtr &)> &&callback);
    std::string RunCommand(std::string cmd);
};