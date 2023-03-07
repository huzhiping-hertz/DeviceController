#pragma once
#include <drogon/HttpSimpleController.h>
using namespace drogon;
class IpManager:public drogon::HttpSimpleController<IpManager>
{
public:
    void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    //PATH_ADD("/ip",Get);
    PATH_LIST_END
};