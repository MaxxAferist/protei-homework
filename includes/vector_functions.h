#ifndef _VECTOR_FUNCTIONS_H_
#define _VECTOR_FUNCTIONS_H_

#include <vector>
#include <string>
#include <iostream>
#include "define.h"
#include "mytools.h"
#include "some_structures.h"
#include <any>

using namespace std;


ERROR_INFO get_int_vector(vector<int> &result, vector<string> &arguments);
ERROR_INFO get_float_vector(vector<float> &result, vector<string> &arguments);
ERROR_INFO get_double_vector(vector<double> &result, vector<string> &arguments);
ERROR_INFO get_char_vector(vector<char> &result, vector<string> &arguments);
ERROR_INFO get_bool_vector(vector<bool> &result, vector<string> &arguments);


template <typename T>
void print(vector<T> &vec, string type)
{
    cout << "================================" << endl;
    cout << "Vector<" << type << "> = { ";
    for (const auto &elem: vec) {
        cout << elem << " ";
    }
    cout << "}" << endl;
    cout << "================================" << endl;
}


template <typename T>
vector<any> get_any_vector(vector<T> &vec)
{
    vector<any> result;
    result.reserve(vec.size());
    for (const auto &elem: vec) {
        result.push_back(elem);
    }
    return result;
}


#endif