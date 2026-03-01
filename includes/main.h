#ifndef _MAIN_H_
#define _MAIN_H_


#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "define.h"
#include "vector_functions.h"
#include "mytools.h"
#include "mylogger.h"


using namespace std;


struct UserInfo
{
    string address = "0.0.0.0";
    int port = 5500;
    string client_role = "client";
    int i = 0;
    string lib = "";

    UserInfo() = default;
    UserInfo(string address, int port, string client_role, int i=0, string lib="");
};


void print_user_info(UserInfo user_info);
void print_menu();

template <typename T>
void print(vector<T> vec, string type);

ERR_CODE get_nickname(string &nickname, vector<string> command_vector);
ERR_CODE get_type(string &type, vector<string> command_vector);

ERR_CODE process_vector(vector<string> command_vector, string type,
    vector<int> &int_vector, vector<float> &float_vector,
    vector<double> &double_vector, vector<string> &string_vector,
    vector<char> &char_vector, vector<bool> &bool_vector);

ERR_CODE parse_arguments(map<string, string> &args, int argc, char *argv []);
bool check_arguments(map<string, string> *args);
ERR_CODE get_user_info_from_arguments(UserInfo &user_info_, map<string, string> args);
vector<string> get_command();

int program(UserInfo user_info);


#endif