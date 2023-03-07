#include "DeviceInformation.h"

void DeviceInformation::GetInformation(const HttpRequestPtr &req,std::function<void (const HttpResponsePtr &)> &&callback)
{
    auto para=req->getParameters();
    HttpViewData data;
    data.insert("title","Device Information");
    auto resp=HttpResponse::newHttpViewResponse("DeviceInfo.csp",data);
    callback(resp);
}

void DeviceInformation::DeviceReboot(const HttpRequestPtr &req,std::function<void (const HttpResponsePtr &)> &&callback)
{

}