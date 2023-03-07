#include "DeviceInformation.h"


void DeviceInformation::asyncHandleHttpRequest(const HttpRequestPtr &req,
                                           std::function<void(const HttpResponsePtr &)> &&callback)
{
    auto para=req->getParameters();
    HttpViewData data;
    data.insert("title","ListParameters");
    auto resp=HttpResponse::newHttpViewResponse("BasicInfo.csp",data);
    callback(resp);
}