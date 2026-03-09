#ifndef _MENU_H_
#define _MENU_H_


#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>

#include "define.h"
#include "DataPool.h"
#include "AppSettings.h"
#include "Tests.h"

#include "vector_functions.h"
#include "mytools.h"
#include "mylogger.h"


class MenuItem {
public:
    virtual ERROR_INFO action() = 0;
    virtual ~MenuItem() = default;
};


class Menu {
public:
    void print() const;
    void add_item(const string &command_name, shared_ptr<MenuItem> item, string description);
    ERROR_INFO process_command(string &command_name);

private:
    map<string, shared_ptr<MenuItem>> items;
    map<string, string> descriptions;
    vector<string> key_commands;
};


class MenuItemName : public MenuItem {
public:
    MenuItemName(shared_ptr<vector<string>> args_vector, shared_ptr<AppSettings> app_settings)
              : args_vector(args_vector),
                app_settings(app_settings) {};
    ERROR_INFO action() override;

private:
    shared_ptr<vector<string>> args_vector;
    shared_ptr<AppSettings> app_settings;
};


class MenuItemType : public MenuItem {
public:
    MenuItemType(shared_ptr<vector<string>> args_vector, shared_ptr<string> type)
              : args_vector(args_vector),
                type(type) {};
    ERROR_INFO action() override;

private:
    shared_ptr<vector<string>> args_vector;
    shared_ptr<string> type;
};


class MenuItemVector : public MenuItem {
public:
    MenuItemVector(shared_ptr<vector<string>> args_vector, shared_ptr<AnyVectors> vectors, shared_ptr<string> type, shared_ptr<DataPool> data_pool)
              : args_vector(args_vector),
                vectors(vectors),
                type(type),
                data_pool(data_pool) {};
    ERROR_INFO action() override;

private:
    shared_ptr<vector<string>> args_vector;
    shared_ptr<AnyVectors> vectors;
    shared_ptr<string> const type;
    shared_ptr<DataPool> data_pool;
};


class MenuItemShow : public MenuItem {
public:
    MenuItemShow(shared_ptr<AppSettings> app_settings, shared_ptr<string> type, shared_ptr<DataPool> data_pool)
              : app_settings(app_settings),
                type(type),
                data_pool(data_pool) {};
    ERROR_INFO action() override;

private:
    shared_ptr<AppSettings> app_settings;
    shared_ptr<string> const type;
    shared_ptr<DataPool> data_pool;
};


class MenuItemTest : public MenuItem {
public:
    MenuItemTest(shared_ptr<vector<string>> args_vector) : args_vector(args_vector) {};
    ERROR_INFO action() override;

private:
    shared_ptr<vector<string>> args_vector;
};


class MenuItemExit : public MenuItem {
public:
    MenuItemExit(shared_ptr<bool> exit)
              : exit(exit) {};
    ERROR_INFO action() override;

private:
    shared_ptr<bool> exit;
};


#endif