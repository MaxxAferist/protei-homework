#include "vector_functions.h"


vector<int> get_int_vector(vector<string> arguments)
{
    vector<int> result_vector;
    for (const string &elem: arguments) {
        result_vector.push_back(stoi(elem));
    }
    return result_vector;
}


vector<float> get_float_vector(vector<string> arguments)
{
    vector<float> result_vector;
    for (const string &elem: arguments) {
        result_vector.push_back(stof(elem));
    }
    return result_vector;
}

vector<double> get_double_vector(vector<string> arguments)
{
    vector<double> result_vector;
    for (const string &elem: arguments) {
        result_vector.push_back(stod(elem));
    }
    return result_vector;
}

vector<char> get_char_vector(vector<string> arguments)
{
    vector<char> result_vector;
    for (const string &elem: arguments) {
        result_vector.push_back(elem.at(0));
    }
    return result_vector;
}

vector<bool> get_bool_vector(vector<string> arguments)
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
            return vector<bool>{false, false, false, false};
        }
    }
    return result_vector;
}

