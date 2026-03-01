#include "mylogger.h"


void log(string info, int level)
{
    time_t time_now = time(0);
    tm *ltm = localtime(&time_now);

    string str_level = get_string_level(level);

    cout << this_thread::get_id() << " [" << str_level << "] "
         << ltm->tm_mday << "-" << ltm->tm_mon << "-" << ltm->tm_year << " "
         << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec
         << " : " << info << endl;
}


string get_string_level(int level)
{
    if (level == INFO)
    {
        return "INFO";
    }
    if (level == WARNING)
    {
        return "WARNING";
    }
    if (level == ERROR)
    {
        return "ERROR";
    }
    if (level == DEBUG)
    {
        return "DEBUG";
    }
    if (level == TRACE)
    {
        return "TRACE";
    }
    return "nolevel";
}