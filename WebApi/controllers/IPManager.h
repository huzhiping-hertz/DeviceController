#pragma once
#include <drogon/HttpController.h>
#include <string>
#include <iostream>

using namespace drogon;
using namespace std; 
class IpManager:public drogon::HttpController<IpManager>
{
public:

    METHOD_LIST_BEGIN
    ADD_METHOD_TO(IpManager::GetIpAddress,"/ip/get",Get);
    ADD_METHOD_TO(IpManager::UpdateAddress,"/ip/update",Post);
    METHOD_LIST_END

    void GetIpAddress(const HttpRequestPtr &req,std::function<void (const HttpResponsePtr &)> &&callback);
    void UpdateAddress(const HttpRequestPtr &req,std::function<void (const HttpResponsePtr &)> &&callback);
};