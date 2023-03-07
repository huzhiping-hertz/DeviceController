#include <iostream>
#include <string>
#include "nlohmann/json.hpp"
#include "drogon/drogon.h"

using namespace drogon;
using namespace std;

int main(int argc, char **argv)
{
    LOG_INFO << "config file is web.json";
    app().loadConfigFile("./web.json").run();
    return 0;
}