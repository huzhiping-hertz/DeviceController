#include "CommonUtility/NetUtility.h"
#include "catch2/catch_all.hpp"
#include "nlohmann/json.hpp"
#include "trantor/utils/Logger.h"
#include "trantor/utils/AsyncFileLogger.h"
#include <iostream>
#include <string>

using namespace std;
using namespace RS;
using namespace nlohmann;

TEST_CASE("IPManager", "[IPManager]")
{

    // SECTION("Get")
    // {
    //     nlohmann::json paramObj;
    //     paramObj["device"]="localhost";
    //     std::string url="http://127.0.0.1:8080/ip/get";
    //     std::map<std::string,std::string> headers;
    //     NetUtility::PostRequest(url,paramObj.dump(),headers);
    // }

    SECTION("Post")
    {
        nlohmann::json paramObj;
        paramObj["ipAddress"]="172.25.64.232";
        paramObj["subnetMask"]="255.255.252.0";
        std::string url="http://127.0.0.1:8080/ip/update";
        std::map<std::string,std::string> headers;
        string rs=NetUtility::PostRequest(url,paramObj.dump(),headers);
        LOG_INFO<<rs;
    }

}
