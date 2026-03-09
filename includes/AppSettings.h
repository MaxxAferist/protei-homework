#ifndef _APPSETTINGS_H_
#define _APPSETTINGS_H_


#include <iostream>
#include <map>
#include <vector>
#include <string>

#include "define.h"
#include "some_structures.h"
#include "IPAddress.h"

#include "mytools.h"
#include "mylogger.h"


struct AppSettings
{
    IPAddress ip_address;
    string client_role;
    int i;
    string lib;

    string nickname;
    ERROR_INFO error_info;

    AppSettings() = default;
    ERROR_INFO init(int argc, char *argv[]);
    AppSettings(string& address, uint8_t& port, string& client_role, int i=0, string lib="", string nickname="");
    ERROR_INFO parse_arguments(map<string, string> &args, int argc, char *argv []);
    bool check_arguments(map<string, string> *args) const;
    ERROR_INFO get_user_info_from_arguments(map<string, string>& args);

    IPAddress get_ip_address() const;
    string get_client_role() const;
    int get_i() const;
    string get_lib() const;

    void set_nickname(string& new_nickname);
};


#endif