#pragma once
#include <drogon/HttpSimpleController.h>
using namespace drogon;
class IpManager:public drogon::HttpSimpleController<IpManager>
{
public:
    void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    PATH_ADD("/ip/get",Get);
    PATH_ADD("/ip/post",Post);
    PATH_LIST_END
};