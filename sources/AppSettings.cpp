#include "AppSettings.h"


ERROR_INFO AppSettings::init(int argc, char *argv[])
{
    map<string, string> args;
    error_info = this->parse_arguments(args, argc, argv);
    if (error_info.code != S_OK)
    {
        return error_info;
    }

    if (!check_arguments(&args))
    {
        error_info = ERROR_INFO(ERROR_CODE_COMMAND_LINE_ARGS, "required flags: -a, -p, -r");
        return error_info;
    }

    error_info = get_user_info_from_arguments(args);
    return error_info;
}


AppSettings::AppSettings(string address, int port, string client_role, int i, string lib, string nickname)
            : address(address),
            port(port),
            client_role(client_role),
            i(i),
            lib(lib),
            nickname(nickname){}


ERROR_INFO AppSettings::parse_arguments(map<string, string> &args, int argc, char *argv [])
{
    string current_flag;
    bool has_current_flag = false;
    map<string, string> result_args;
    for (int i = 0;i < argc;i++) {
        string arg = argv[i];
        if (arg[0] == '-')
        {
            current_flag = arg;
            has_current_flag = true;
        }
        else
        {
            if (has_current_flag)
            {
                result_args.insert(make_pair(current_flag, arg));
                has_current_flag = false;
            }
        }
    }
    args = result_args;
    return ERROR_INFO(S_OK, "success");
}


bool AppSettings::check_arguments (map<string, string> *args) const
{
    vector<string> checking_flags = {"-a", "-p", "-r"};
    for (auto const &elem: checking_flags)
    {
        auto it = args->find(elem);
        if (it == args->end()) {
            return false;
        }
    }
    return true;
}


ERROR_INFO AppSettings::get_user_info_from_arguments(map<string, string> args)
{
    address = args["-a"];

    if (!isdigit(args["-p"])) {
        return ERROR_INFO(ERROR_CODE_VALUE, "flag -p must be <int>");
    }
    if (isoverflow_int(args["-p"]))
    {
        return ERROR_INFO(ERROR_CODE_OVERFLOW, "Overflow int error");
    }
    port = stoi(args["-p"]);
    if (0 > port || port > 65536) {
         return ERROR_INFO(ERROR_CODE_OVERFLOW, "Port must be between 0 and 65536");
    }
    
    client_role = args["-r"];

    auto it = args.find("-i");
    if (it != args.end()) {
        if (!isdigit(args["-i"])) {
            return ERROR_INFO(ERROR_CODE_VALUE, "flag -i must be <int>");
        }
        if (isoverflow_int(args["-i"]))
        {
            return ERROR_INFO(ERROR_CODE_OVERFLOW, "Overflow int error");
        }
        i = stoi(args["-i"]);
    }

    it = args.find("-l");
    if (it != args.end()) {
        lib = args["-l"];
    }

    return ERROR_INFO(S_OK, "success");

}


string AppSettings::get_address() const
{
    return address;
}


int AppSettings::get_port() const
{
    return port;
}


string AppSettings::get_client_role() const
{
    return client_role;
}


int AppSettings::get_i() const
{
    return i;
}


string AppSettings::get_lib() const
{
    return lib;
}


void AppSettings::set_nickname(string new_nickname)
{
    nickname = new_nickname;
}