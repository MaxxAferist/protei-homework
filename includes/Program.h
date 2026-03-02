#ifndef _PROGRAM_H_
#define _PROGRAM_H_


#include <iostream>
#include <map>
#include <vector>
#include <string>

#include "define.h"
#include "AppSettings.h"
#include "Menu.h"
#include "some_structures.h"

#include "vector_functions.h"
#include "mytools.h"
#include "mylogger.h"


using namespace std;


class Program
{
public:
    Program(AppSettings *app_settings);
    ~Program();
    int start();
    
private:
    AppSettings *app_settings;
    Menu *menu;
    DataPool *data_pool;
    vector<string> command_vector;
    string type="int";
    AnyVectors *vectors;
    bool exit = false;
    ERROR_INFO error_info;

    void print_user_info();
    void get_command();
};


#endif
