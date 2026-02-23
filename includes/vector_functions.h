#ifndef _VECTOR_FUNCTIONS_H_
#define _VECTOR_FUNCTIONS_H_

#include <vector>
#include <string>
#include <iostream>

using namespace std;


vector<int> get_int_vector(vector<string> arguments);
vector<float> get_float_vector(vector<string> arguments);
vector<double> get_double_vector(vector<string> arguments);
vector<char> get_char_vector(vector<string> arguments);
vector<bool> get_bool_vector(vector<string> arguments);


#endif