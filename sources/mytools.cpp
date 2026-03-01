#include "mytools.h"


string tolower(const string str_)
{
    string str = str_;
    for (size_t i = 0;i < str.length();i++) {
        char cur_char = str.at(i);
        if (cur_char >= 'A' && cur_char <= 'Z') {
            str.at(i) = cur_char - ('Z' - 'z');
        }
    }
    return str;
}


vector<string> split_string(const string str_, const string delimiter)
{
    string str = str_;
    vector<string> result;
    
    auto delimiter_pos = str.find(delimiter);
    while (delimiter_pos != string::npos) {
        string first = str.substr(0, delimiter_pos);
        str = str.substr(delimiter_pos + delimiter.length());
        result.push_back(first);
        delimiter_pos = str.find(" ");
    }
    result.push_back(str);
    return result;
}


vector<string> split_string(const string str_)
{
    string str = str_ + " "; 

    vector<string> result;
    string noprint_symbols = " \e\r\t\a\f\v\b\n";

    size_t first_pos = 0;
    size_t length_word = 0;

    for (size_t i = 0;i < str.length();i++)
    {
        auto delimiter_pos = noprint_symbols.find(str[i]);
        if (delimiter_pos != string::npos)
        {
            if (length_word != 0)
            {
                string word = str.substr(first_pos, length_word);
                result.push_back(word);
            }
            first_pos = i + 1;
            length_word = -1;
        }
        length_word++;
    }

    return result;
}


string join(const vector<string> str_vector, const string delimiter)
{
    string result = "";
    for (auto const &elem: str_vector)
    {
        result = result + elem + delimiter;
    }
    if (str_vector.size() != 0) {
        result.erase(result.end() - delimiter.length(), result.end());
    }
    return result;
}


bool isdigit(const string str_)
{
    string str = str_;
    if (str[0] == '-')
    {
        str.erase(str.begin(), str.begin() + 1);
    }

    while (str.length() > 1 && (str[0] == '0' && str[1] == '0'))
    {
        str.erase(0, 1);
    }

    auto dot_pos = str.find(".");
    if (dot_pos != string::npos)
    {
        if (dot_pos == 0 || dot_pos == str.length() - 1) {
            return false;
        }
        str.erase(str.begin() + dot_pos, str.begin() + dot_pos + 1);
    }

    for (char &elem: str)
    {
        if (elem < '0' || elem > '9')
        {
            return false;
        }
    }
    return true;
}


bool isoverflow_int(const string str_)
{
    string max_int = "2147483647";
    size_t max_int_length = max_int.length();
    size_t str_length = str_.length();
    if (max_int_length > str_length)
    {
        return false;
    }
    else if (max_int_length < str_length)
    {
        return true;
    }
    else
    {
        for (size_t i = 0;i < str_length;i++)
        {
            if (max_int[i] > str_[i])
            {
                return false;
            }
            else if (max_int[i] < str_[i])
            {
                return true;
            }
        }
    }
    return false;
}


int string_count(const string str_, const string substr_)
{
    string str = str_;
    size_t substr_length = substr_.length();
    auto substr_pos = str.find(substr_);
    int count = 0;
    while (str.length() >= substr_length && substr_pos != string::npos)
    {
        str = str.substr(substr_pos + substr_length);
        substr_pos = str.find(substr_);
        count++;
    }
    return count;
}
