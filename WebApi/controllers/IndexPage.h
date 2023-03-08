#pragma once
#include <drogon/HttpController.h>
using namespace drogon;
class IndexPage:public drogon::HttpController<IndexPage>
{
public:

    METHOD_LIST_BEGIN
    ADD_METHOD_TO(IndexPage::GetInformation,"/",Get);
    METHOD_LIST_END

    void GetInformation(const HttpRequestPtr &req,std::function<void (const HttpResponsePtr &)> &&callback);

};