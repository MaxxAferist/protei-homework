#ifndef _TESTS_H_
#define _TESTS_H_


#include <vector>
#include <string>
#include <filesystem>
#include <memory>

#include "define.h"
#include "mytools.h"
#include "mylogger.h"


using namespace std;


class Test
{
public:
    virtual ~Test() = default;
    virtual bool test() = 0;
};


class ConnectionTest : public Test
{
public:
    ConnectionTest(vector<string> &params) : params(params) {};
    bool test() override;

private:
    vector<string> params;
};


class ResourceTest : public Test
{
public:
    ResourceTest(vector<string> &params) : params(params) {};
    bool test() override;

private:
    vector<string> params;
};


#endif