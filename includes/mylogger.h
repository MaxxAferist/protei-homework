#ifndef _MYLOGGER_H_
#define _MYLOGGER_H_

#include <ctime>
#include <string>
#include <iostream>
#include <thread>


using namespace std;


#define INFO 0
#define WARNING 1
#define ERROR 2
#define DEBUG 3
#define TRACE 4


string get_string_level(int level);

void log(string info, int level=INFO);

#endif