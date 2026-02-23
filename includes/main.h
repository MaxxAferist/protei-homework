#ifndef _MAIN_H_
#define _MAIN_H_


#include <iostream>
#include <map>
#include <vector>
#include <string>


using namespace std;


struct UserInfo
{
    string address = "0.0.0.0";
    int port = 5500;
    string client_role = "client";
    int i = 0;
    string lib = "";
};

string tolower(string str);
vector<string> split_string(string str, string delimiter);

void print_user_info(UserInfo user_info);
void print_commands();

template <typename T>
void print(vector<T> vec, string type);

string get_nickname(string command_arguments);
string get_type(string command_arguments);

map<string, string> parse_arguments(int argc, char *argv []);
UserInfo get_user_info_from_arguments(map<string, string> args);

int program(UserInfo user_info);


#endif