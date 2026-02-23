#include "main.h"
#include "vector_functions.h"


string tolower(string str)
{
    for (size_t i = 0;i < str.length();i++) {
        char cur_char = str.at(i);
        if (cur_char >= 'A' && cur_char <= 'Z') {
            str.at(i) = cur_char - ('Z' - 'z');
        }
    }
    return str;
}


vector<string> split_string(string str, string delimiter)
{
    vector<string> result;
    
    auto delimiter_pos = str.find(" ");
    while (delimiter_pos != string::npos) {
        string first = str.substr(0, delimiter_pos);
        str = str.substr(delimiter_pos + 1);
        result.push_back(first);
        delimiter_pos = str.find(" ");
    }
    result.push_back(str);
    return result;
}


void print_user_info(UserInfo user_info)
{
    cout << "Client data:" << endl;
    cout << "IP Address: " << user_info.address << endl;
    cout << "Port: " << user_info.port << endl;
    cout << "Role: " << user_info.client_role << endl;
    cout << "I: " << user_info.i << endl;
    cout << "Lib: " << user_info.lib << endl;
}


void print_commands()
{
    cout << endl;
    cout << "Accessible commands:" << endl;
    cout << "- name <nickname>" << endl;
    cout << "- type <type (int, string, double, float, bool, char)>" << endl;
    cout << "- vector <value_1> <value_2> <value_3> <value_4>" << endl;
    cout << "- exit" << endl;
}


template <typename T>
void print(vector<T> vec, string type) {
    cout << "================================" << endl;
    cout << "Vector<" << type << "> = { ";
    for (const auto &elem: vec) {
        cout << elem << " ";
    }
    cout << "}" << endl;
    cout << "================================" << endl;
}


string get_nickname(string command_arguments)
{
    return command_arguments;
}


string get_type(string command_arguments)
{
    if (command_arguments == "int" ||
        command_arguments == "float"||
        command_arguments == "double" ||
        command_arguments == "bool" ||
        command_arguments == "char" ||
        command_arguments == "string") {
            return command_arguments;
        }
    else {
        cout << "Type \"" << command_arguments << "\" not suitable for this program" << endl;
        return "int";
    }
}


map<string, string> parse_arguments(int argc, char *argv [])
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
    return result_args;
}


UserInfo get_user_info_from_arguments(map<string, string> args)
{
    UserInfo user_info;

    auto it = args.find("-a");
    if (it != args.end()) {
        user_info.address = args["-a"];
    }

    it = args.find("-p");
    if (it != args.end()) {
        user_info.port = stoi(args["-p"]);
    }

    it = args.find("-r");
    if (it != args.end()) {
        user_info.client_role = args["-r"];
    }

    it = args.find("-i");
    if (it != args.end()) {
        user_info.i = stoi(args["-i"]);
    }

    it = args.find("-l");
    if (it != args.end()) {
        user_info.lib = args["-l"];
    }

    return user_info;
}


int program(UserInfo user_info)
{
    print_user_info(user_info);
    string current_command = "";

    string nickname = "Noname";
    string type = "int";

    vector<int> int_vector;
    vector<float> float_vector;
    vector<double> double_vector;
    vector<string> string_vector;
    vector<char> char_vector;
    vector<bool> bool_vector;

    while (current_command != "exit") {
        print_commands();
        cout << "command: ";
        getline(cin, current_command); cout << endl;
        current_command = tolower(current_command);

        string command_name = current_command;
        string command_arguments = "";
        
        auto delimiter_pos = current_command.find(" ");
        if (delimiter_pos != string::npos)
        {
            command_name = current_command.substr(0, delimiter_pos);
            command_arguments = current_command.substr(delimiter_pos + 1);
        }

        if (command_name == "name")
        {
            nickname = get_nickname(command_arguments);
            cout << "================================" << endl;
            cout << "New nickname: " << nickname << endl;
            cout << "================================" << endl;
        }
        else if (command_name == "type")
        {
            type = get_type(command_arguments);
            cout << "================================" << endl;
            cout << "New type: " << type << endl;
            cout << "================================" << endl;
        }
        else if (command_name == "vector")
        {
            vector<string> spliting_arguments = split_string(command_arguments, " ");
            if (spliting_arguments.size() != 4)
            {
                cout << "Expected 4 arguments, not " << spliting_arguments.size() << endl;
                continue;
            }

            if (type == "int")
            {
                int_vector = get_int_vector(spliting_arguments);
                print<int>(int_vector, type);
            } else if (type == "float")
            {
                float_vector = get_float_vector(spliting_arguments);
                print<float>(float_vector, type);
            } else if (type == "double")
            {
                double_vector = get_double_vector(spliting_arguments);
                print<double>(double_vector, type);
            } else if (type == "bool")
            {
                bool_vector = get_bool_vector(spliting_arguments);
                print<bool>(bool_vector, type);
            } else if (type == "char")
            {
                char_vector = get_char_vector(spliting_arguments);
                print<char>(char_vector, type);
            } else if (type == "string")
            {
                string_vector = spliting_arguments;
                print<string>(string_vector, type);
            }
        }
        else if (command_name != "exit")
        {
            cout << "Command \"" << command_name << "\" not found" << endl;
        }
    }

    return 0;
}


int main(int argc, char* argv []) {
    map<string, string> args = parse_arguments(argc, argv);
    UserInfo user_info = get_user_info_from_arguments(args);
    
    int exit_code = program(user_info);
    return exit_code;
}
