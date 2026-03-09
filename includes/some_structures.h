#ifndef _SOME_STRUCTURES_H_
#define _SOME_STRUCTURES_H_


#include <string>
#include <vector>
#include <memory>

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
        int_vector = make_shared<vector<int>>();
        float_vector = make_shared<vector<float>>();
        double_vector = make_shared<vector<double>>();
        bool_vector = make_shared<vector<bool>>();
        char_vector = make_shared<vector<char>>();
        string_vector = make_shared<vector<string>>();
    }
    
    shared_ptr<vector<int>> int_vector;
    shared_ptr<vector<float>> float_vector;
    shared_ptr<vector<double>> double_vector;
    shared_ptr<vector<bool>> bool_vector;
    shared_ptr<vector<char>> char_vector;
    shared_ptr<vector<string>> string_vector;
};


#endif