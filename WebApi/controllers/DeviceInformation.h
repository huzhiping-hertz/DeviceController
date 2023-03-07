#pragma once
#include <drogon/HttpSimpleController.h>
using namespace drogon;
class DeviceInformation:public drogon::HttpSimpleController<DeviceInformation>
{
public:
    void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;

    PATH_LIST_BEGIN
    //PATH_ADD("/info");
    PATH_LIST_END
};