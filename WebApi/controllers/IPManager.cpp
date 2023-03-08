#include "IPManager.h"
#include "Poco/Net/IPAddress.h"
#include "Poco/Net/NetworkInterface.h"

using namespace Poco::Net;
using namespace Poco;
void IpManager::GetIpAddress(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{
    auto all = Poco::Net::NetworkInterface::list();
    auto item = all.begin();
    Json::Value json;
    json["ipAddress"] = "127.0.0.1";
    json["subnetMask"] = "255.255.255.255";
    while (item != all.end())
    {
        Poco::Net::NetworkInterface iface = (*item);
        Poco::Net::IPAddress address = iface.address();
        Poco::Net::IPAddress submask = iface.subnetMask();
        LOG_INFO << address.toString() << "  " << submask.toString();
        if (address.family() == Poco::Net::IPAddress::Family::IPv4)
        {
            json["ipAddress"] = address.toString();
            json["subnetMask"] = submask.toString();
        }
        item++;
    }

    auto resp = HttpResponse::newHttpJsonResponse(json);
    callback(resp);
}

void IpManager::UpdateAddress(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{
    std::string ip = "127.0.0.1";
    std::string netmask = "255.255.255.255";

    auto json = req->getJsonObject();
    if (json)
    {
        ip = (*json)["ipAddress"].asString();
        LOG_INFO << "Post IP ："<<ip;
        netmask = (*json)["subnetMask"].asString();
        LOG_INFO << "Post SubNetMask： "<< netmask;
    }

    auto all = Poco::Net::NetworkInterface::list();
    auto item = all.begin();

    while (item != all.end())
    {
        Poco::Net::NetworkInterface iface = (*item);
        Poco::Net::IPAddress address = iface.address();
        if (address.family() == Poco::Net::IPAddress::Family::IPv4 && !address.isLoopback())
        {
            LOG_INFO << iface.adapterName()<<" "<< address.toString();
            string cmd="ip link set "+iface.adapterName()+" down";
            LOG_INFO<<cmd;
	        system(cmd.c_str()); 
            cmd="ifconfig "+iface.adapterName()+" "+ip+" netmask "+netmask;
            LOG_INFO<<cmd;
            system(cmd.c_str());
            cmd="ip link set "+iface.adapterName()+" up";
            LOG_INFO<<cmd;
            system(cmd.c_str());
        }
        item++;
    }

    Json::Value rsObj;
    rsObj["status"] = "success";
    auto resp = HttpResponse::newHttpJsonResponse(rsObj);
    callback(resp);
}