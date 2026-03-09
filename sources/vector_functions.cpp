#include "vector_functions.h"


ERROR_INFO get_int_vector(vector<int> &result, vector<string> &arguments)
{
    vector<int> result_vector;
    for (const string &elem: arguments)
    {
        if (!isdigit(elem))
        {
            cout << "Expected <int>, but something strange was passed" << endl;
            return ERROR_INFO(WARNING_CODE_VALUE, "xpected <int>, but something strange was passed");
        }
        if (isoverflow_int(elem))
        {
            cout << "Overflow int error" << endl;
            return ERROR_INFO(WARNING_CODE_OVERFLOW, "overflow int");
        }
        result_vector.push_back(stoi(elem));
    }
    if (result_vector.back() == 0)
    {
        return ERROR_INFO(WARNING_CODE_FOURTH_ELEMENT_IS_NULL, "fourth element is 0");
    }
    result = result_vector;
    return ERROR_INFO(S_OK, "success");
}


ERROR_INFO get_float_vector(vector<float> &result, vector<string> &arguments)
{
    vector<float> result_vector;
    for (const string &elem: arguments)
    {
        if (!isdigit(elem))
        {
            cout << "Expected <float>, but something strange was passed" << endl;
            return ERROR_INFO(WARNING_CODE_VALUE, "expected <float>, but something strange was passed");
        }
        if (isoverflow_int(elem))
        {
            cout << "Overflow float error" << endl;
            return ERROR_INFO(WARNING_CODE_OVERFLOW, "overflow float");
        }
        result_vector.push_back(stof(elem));
    }
    if (result_vector.back() == 0)
    {
        return ERROR_INFO(WARNING_CODE_FOURTH_ELEMENT_IS_NULL, "fourth element is 0");
    }
    result = result_vector;
    return ERROR_INFO(S_OK, "success");
}


ERROR_INFO get_double_vector(vector<double> &result, vector<string> &arguments)
{
    vector<double> result_vector;
    for (const string &elem: arguments)
    {
        if (!isdigit(elem))
        {
            cout << "Expected <double>, but something strange was passed" << endl;
            return ERROR_INFO(WARNING_CODE_VALUE, "expected <double>, but something strange was passed");
        }
        if (isoverflow_int(elem))
        {
            cout << "Overflow double error" << endl;
            return ERROR_INFO(WARNING_CODE_OVERFLOW, "overflow double");
        }
        result_vector.push_back(stod(elem));
    }
    if (result_vector.back() == 0)
    {
        return ERROR_INFO(WARNING_CODE_FOURTH_ELEMENT_IS_NULL, "fourth element is 0");
    }
    result = result_vector;
    return ERROR_INFO(S_OK, "success");
}


ERROR_INFO get_char_vector(vector<char> &result, vector<string> &arguments)
{
    vector<char> result_vector;
    for (const string &elem: arguments) {
        result_vector.push_back(elem.at(0));
    }
    if (result_vector.back() == 0)
    {
        return ERROR_INFO(WARNING_CODE_FOURTH_ELEMENT_IS_NULL, "fourth element is 0");
    }
    result = result_vector;
    return ERROR_INFO(S_OK, "success");
}


ERROR_INFO get_bool_vector(vector<bool> &result, vector<string> &arguments)
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
            return ERROR_INFO(WARNING_CODE_VALUE, "expected <bool>, but something strange was passed");
        }
    }
    result = result_vector;
    return ERROR_INFO(S_OK, "success");
}
