#ifndef _PROGRAM_H_
#define _PROGRAM_H_


#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>

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
    Program(shared_ptr<AppSettings> app_settings);
    int start();
    
private:
    shared_ptr<AppSettings> app_settings;
    shared_ptr<Menu> menu;
    shared_ptr<DataPool> data_pool;
    shared_ptr<vector<string>> command_vector;
    shared_ptr<string> type;
    shared_ptr<AnyVectors> vectors;
    shared_ptr<bool> exit;
    ERROR_INFO error_info;

    void print_user_info();
    void get_command();
};


#endif
