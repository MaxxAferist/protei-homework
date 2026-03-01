#ifndef _VECTOR_FUNCTIONS_H_
#define _VECTOR_FUNCTIONS_H_

#include <vector>
#include <string>
#include <iostream>
#include "define.h"
#include "mytools.h"

using namespace std;


ERR_CODE get_int_vector(vector<int> &result, vector<string> arguments);
ERR_CODE get_float_vector(vector<float> &result, vector<string> arguments);
ERR_CODE get_double_vector(vector<double> &result, vector<string> arguments);
ERR_CODE get_char_vector(vector<char> &result, vector<string> arguments);
ERR_CODE get_bool_vector(vector<bool> &result, vector<string> arguments);


#endif