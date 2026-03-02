#include "Tests.h"


bool ConnectionTest::test()
{
    string ip = "";
    int port = -1;
    for (auto const &param:params)
    {
        vector<string> spliting_param = split_string(param, ":");
        if (spliting_param.size() == 2)
        {
            string param_name = spliting_param[0];
            string param_value = spliting_param[1];
            if (param_name == "ip")
            {
                ip = param_value;
            }
            else if (param_name == "port" && isdigit(param_value) && !isoverflow_int(param_value))
            {
                int port_ = stoi(param_value);
                if (0 < port_ && port_ < 65536)
                {
                    port = port_;
                }
            }
        }
    }
    if (ip == "" || port == -1) {
        return false;
    }
    return true;
}


bool ResourceTest::test()
{
    if (params.size() == 0)
    {
        return false;
    }

    filesystem::path folder = params[0];
    bool flag = true;

    params.erase(params.begin(), params.begin() + 1);

    for (auto const &param:params)
    {
        filesystem::path fullpath = folder / param;
        if (filesystem::exists(fullpath))
        {
            log("file " + string(fullpath) + " is exists", INFO);
        }
        else
        {
            log("file " + string(fullpath) + " does not exists", ERROR);
            flag = false;
        }
    }
    return flag;
}