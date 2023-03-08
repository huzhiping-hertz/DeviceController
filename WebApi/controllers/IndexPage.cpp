#include "IndexPage.h"

void IndexPage::GetInformation(const HttpRequestPtr &req,std::function<void (const HttpResponsePtr &)> &&callback)
{
    auto para=req->getParameters();
    HttpViewData data;
    data.insert("title","Device Information");
    auto resp=HttpResponse::newHttpViewResponse("IndexPage.csp",data);
    callback(resp);
}
