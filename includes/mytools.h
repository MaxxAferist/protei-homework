#ifndef _MYTOOLS_H_
#define _MYTOOLS_H_


#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "define.h"


using namespace std;


string tolower(const string &str_);
vector<string> split_string(const string &str_, const string &delimiter);
vector<string> split_string(const string &str_);
void strip(string &str_);
string join(const vector<string> &str_vector, const string &delimiter=" ");
bool isdigit(const string &str_);
bool isdigit_hex(const string &str_);
bool isoverflow_int(const string &str_);
bool isoverflow_hex(const string &str_);
int string_count(const string &str_, const string &substr_);


#endif