#include "main.h"


UserInfo::UserInfo(string address, int port, string client_role, int i, string lib)
                      : address(address),
                        port(port),
                        client_role(client_role),
                        i(i),
                        lib(lib){}


void print_user_info(UserInfo user_info)
{
    cout << "Client data:" << endl;
    cout << "IP Address: " << user_info.address << endl;
    cout << "Port: " << user_info.port << endl;
    cout << "Role: " << user_info.client_role << endl;
    cout << "I: " << user_info.i << endl;
    cout << "Lib: " << user_info.lib << endl;
}


void print_menu()
{
    cout << endl;
    cout << "Accessible commands:" << endl;
    cout << "- name <nickname>" << endl;
    cout << "- type <type (int, string, double, float, bool, char)>" << endl;
    cout << "- vector <value_1> <value_2> <value_3> <value_4>" << endl;
    cout << "- exit" << endl;
}


template <typename T>
void print(vector<T> vec, string type)
{
    cout << "================================" << endl;
    cout << "Vector<" << type << "> = { ";
    for (const auto &elem: vec) {
        cout << elem << " ";
    }
    cout << "}" << endl;
    cout << "================================" << endl;
}


ERR_CODE get_nickname(string &nickname, vector<string> command_vector)
{
    nickname = join(command_vector);
    cout << "================================" << endl;
    cout << "New nickname: " << nickname << endl;
    cout << "================================" << endl;
    return S_OK;
}


ERR_CODE get_type(string &type, vector<string> command_vector)
{
    string arg_type = join(command_vector);
    if (arg_type == "int" ||
        arg_type == "float"||
        arg_type == "double" ||
        arg_type == "bool" ||
        arg_type == "char" ||
        arg_type == "string")
        {
            cout << "================================" << endl;
            cout << "New type: " << arg_type << endl;
            cout << "================================" << endl;
            type = arg_type;
        }
    else {
        cout << "Type \"" << arg_type << "\" not suitable for this program" << endl;
        log("error type: \"" + arg_type + "\"", WARNING);
        type = "int";
        return WARNING_CODE_VALUE;
    }
    return S_OK;
}


ERR_CODE process_vector(vector<string> command_vector, string type,
    vector<int> &int_vector, vector<float> &float_vector,
    vector<double> &double_vector, vector<string> &string_vector,
    vector<char> &char_vector, vector<bool> &bool_vector)
{
    ERR_CODE code = S_OK;
    if (command_vector.size() != 4)
    {
        cout << "Expected 4 arguments, not " << command_vector.size() << endl;
        return WARNING_CODE_VECTOR;
    }

    if (type == "int")
    {
        code = get_int_vector(int_vector, command_vector);
        if (code == S_OK)
        {
            print<int>(int_vector, type);
        }
    }
    else if (type == "float")
    {
        code = get_float_vector(float_vector, command_vector);
        if (code == S_OK)
        {
            print<float>(float_vector, type);
        }
    }
    else if (type == "double")
    {
        code = get_double_vector(double_vector, command_vector);
        if (code == S_OK)
        {
            print<double>(double_vector, type);
        }
    }
    else if (type == "bool")
    {
        code = get_bool_vector(bool_vector, command_vector);
        if (code == S_OK)
        {
            print<bool>(bool_vector, type);
        }
    }
    else if (type == "char")
    {
        code = get_char_vector(char_vector, command_vector);
        if (code == S_OK)
        {
            print<char>(char_vector, type);
        }
    }
    else if (type == "string")
    {
        string_vector = command_vector;
        print<string>(string_vector, type);
    }    

    return code;
}


ERR_CODE parse_arguments(map<string, string> &args, int argc, char *argv [])
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
    return S_OK;
}


bool check_arguments(map<string, string> *args)
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


ERR_CODE get_user_info_from_arguments(UserInfo &user_info, map<string, string> args)
{
    string address;
    int port;
    string client_role;
    int i = 0;
    string lib = "";

    address = args["-a"];


    if (!isdigit(args["-p"])) {
        cout << "flag -p must be <int>" << endl;
        return ERROR_CODE_VALUE;
    }
    if (isoverflow_int(args["-p"]))
    {
        cout << "Overflow int error" << endl;
        return ERROR_CODE_OVERFLOW;
    }
    port = stoi(args["-p"]);
    
    client_role = args["-r"];

    auto it = args.find("-i");
    if (it != args.end()) {
        if (!isdigit(args["-i"])) {
            cout << "flag -i must be <int>" << endl;
            return ERROR_CODE_VALUE;
        }
        if (isoverflow_int(args["-i"]))
        {
            cout << "Overflow int error" << endl;
            return ERROR_CODE_OVERFLOW;
        }
        i = stoi(args["-i"]);
    }

    it = args.find("-l");
    if (it != args.end()) {
        lib = args["-l"];
    }

    user_info = UserInfo(address, port, client_role, i, lib);
    return S_OK;
}


vector<string> get_command()
{
    cout << "command: ";
    string command;
    getline(cin, command); cout << endl;
    command = tolower(command);
    vector<string> vector_command = split_string(command);
    return vector_command;
}


int program(UserInfo user_info)
{
    print_user_info(user_info);
    vector<string> command_vector = {"pass"};

    string nickname = "Noname";
    string type = "int";

    vector<int> int_vector;
    vector<float> float_vector;
    vector<double> double_vector;
    vector<string> string_vector;
    vector<char> char_vector;
    vector<bool> bool_vector;
    string command_name = "";
    int code;


    while (command_name != "exit") {
        print_menu();
        command_vector = get_command();
        
        if (command_vector.size() == 0)
        {
            continue;
        }

        command_name = command_vector[0];
        command_vector.erase(command_vector.begin(), command_vector.begin() + 1);

        log("user command: " + command_name + " " + join(command_vector, " "), INFO);

        if (command_name == "name")
        {
            get_nickname(nickname, command_vector);
        }
        else if (command_name == "type")
        {
            get_type(type, command_vector);
        }
        else if (command_name == "vector")
        {
            code = process_vector(command_vector, type, int_vector, float_vector, double_vector, string_vector, char_vector, bool_vector);
            if (code != S_OK)
            {
                cout << "Error of entering values" << endl;
                log("Error of entering values", ERROR);
                if (code == WARNING_CODE_FOURTH_ELEMENT_IS_NULL)
                {
                    cout << "Last element of vector<" << type << "> should not be equal to 0" << endl;
                    log("last element of vector<" + type + "> = 0", ERROR);
                }
                else if (code == WARNING_CODE_VALUE)
                {
                    log("value error by entering vector", ERROR);
                }
                else if (code == WARNING_CODE_FOURTH_ELEMENT_IS_NULL)
                {
                    log("fourth vector's element is 0", ERROR);
                }
                else
                {
                    log("no found error", ERROR);
                }
            }
        }
        else if (command_name != "exit")
        {
            cout << "Command \"" << command_name << "\" not found" << endl;
            log("command no found", WARNING);
        }
    }

    return 0;
}


int main(int argc, char* argv []) {
    map<string, string> args;
    ERR_CODE code = parse_arguments(args, argc, argv);
    if (code != S_OK)
    {
        log("error during function \"parse_arguments\"", ERROR);
        return code;
    }

    if (!check_arguments(&args))
    {
        cout << "Flags \"-a\", \"-p\", \"-r\" should not be empty" << endl;
        log("not enough arguments for start program", ERROR);
        return ERROR_CODE_COMMAND_LINE_ARGS;
    }

    UserInfo user_info;
    code = get_user_info_from_arguments(user_info, args);
    if (code != 0)
    {
        if (code == ERROR_CODE_VALUE)
        {
            log("value error in command line", ERROR);
        }
        else if (code == ERROR_CODE_OVERFLOW)
        {
            log("overflow error in command line", ERROR);
        }
        return code;
    }
    
    int exit_code = program(user_info);
    return exit_code;
}
