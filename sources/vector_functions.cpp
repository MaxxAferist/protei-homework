#include "vector_functions.h"


ERR_CODE get_int_vector(vector<int> &result, vector<string> arguments)
{
    vector<int> result_vector;
    for (const string &elem: arguments)
    {
        if (!isdigit(elem))
        {
            cout << "Expected <int>, but something strange was passed" << endl;
            return WARNING_CODE_VALUE;
        }
        if (isoverflow_int(elem))
        {
            cout << "Overflow int error" << endl;
            return WARNING_CODE_OVERFLOW;
        }
        result_vector.push_back(stoi(elem));
    }
    if (result_vector.back() == 0)
    {
        return WARNING_CODE_FOURTH_ELEMENT_IS_NULL;
    }
    result = result_vector;
    return S_OK;
}


ERR_CODE get_float_vector(vector<float> &result, vector<string> arguments)
{
    vector<float> result_vector;
    for (const string &elem: arguments)
    {
        if (!isdigit(elem))
        {
            cout << "Expected <int>, but something strange was passed" << endl;
            return WARNING_CODE_VALUE;
        }
        if (isoverflow_int(elem))
        {
            cout << "Overflow int error" << endl;
            return WARNING_CODE_OVERFLOW;
        }
        result_vector.push_back(stof(elem));
    }
    if (result_vector.back() == 0)
    {
        return WARNING_CODE_FOURTH_ELEMENT_IS_NULL;
    }
    result = result_vector;
    return S_OK;
}


ERR_CODE get_double_vector(vector<double> &result, vector<string> arguments)
{
    vector<double> result_vector;
    for (const string &elem: arguments)
    {
        if (!isdigit(elem))
        {
            cout << "Expected <int>, but something strange was passed" << endl;
            return WARNING_CODE_VALUE;
        }
        if (isoverflow_int(elem))
        {
            cout << "Overflow int error" << endl;
            return WARNING_CODE_OVERFLOW;
        }
        result_vector.push_back(stod(elem));
    }
    if (result_vector.back() == 0)
    {
        return WARNING_CODE_FOURTH_ELEMENT_IS_NULL;
    }
    result = result_vector;
    return S_OK;
}


ERR_CODE get_char_vector(vector<char> &result, vector<string> arguments)
{
    vector<char> result_vector;
    for (const string &elem: arguments) {
        result_vector.push_back(elem.at(0));
    }
    result = result_vector;
    if (result_vector.back() == 0)
    {
        return WARNING_CODE_FOURTH_ELEMENT_IS_NULL;
    }
    return S_OK;
}


ERR_CODE get_bool_vector(vector<bool> &result, vector<string> arguments)
{
    vector<bool> result_vector;
    for (const string &elem: arguments) {
        if (elem == "true")
        {
            result_vector.push_back(true);
        }
        else if (elem == "false")
        {
            result_vector.push_back(false);
        }
        else {
            cout << elem << " not is bool type. Only \"true\" and \"false\"" << endl;
            return WARNING_CODE_VECTOR;
        }
    }
    result = result_vector;
    return S_OK;
}

