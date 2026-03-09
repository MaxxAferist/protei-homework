#ifndef _SOME_STRUCTURES_H_
#define _SOME_STRUCTURES_H_


#include <string>
#include <vector>
#include "define.h"


using namespace std;


struct ERROR_INFO
{
    ERROR_INFO () = default;
    ERROR_INFO (ERR_CODE code, string info) : code(code), info(info) {};
    ERR_CODE code;
    string info;

    explicit operator bool () const
    {
        return code == S_OK;
    }
};


struct AnyVectors
{
    AnyVectors()
    {
        int_vector = new vector<int>();
        float_vector = new vector<float>();
        double_vector = new vector<double>();
        bool_vector = new vector<bool>();
        char_vector = new vector<char>();
        string_vector = new vector<string>();
    }

    ~AnyVectors()
    {
        delete int_vector;
        delete float_vector;
        delete double_vector;
        delete bool_vector;
        delete char_vector;
        delete string_vector;
    }
    vector<int> *int_vector;
    vector<float> *float_vector;
    vector<double> *double_vector;
    vector<bool> *bool_vector;
    vector<char> *char_vector;
    vector<string> *string_vector;
};


#endif