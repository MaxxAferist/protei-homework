#include "Menu.h"


void Menu::print() const
{
    cout << endl;
    for (auto const &elem: key_commands)
    {
        cout << descriptions.at(elem) << endl;
    }
}


void Menu::add_item(const string &command_name, shared_ptr<MenuItem> item, string description)
{
    items[command_name] = item;
    descriptions[command_name] = description;
    key_commands.push_back(command_name);
}


ERROR_INFO Menu::process_command(string &command_name)
{
    ERROR_INFO error_info;
    auto item = items.find(command_name);
    if (item != items.end())
    {
        error_info = item->second->action();
    }
    else
    {
        return ERROR_INFO(ERROR_CODE, "command not found");
    }
    return error_info;
}


ERROR_INFO MenuItemName::action()
{
    app_settings->nickname = join(*args_vector);
    cout << "================================" << endl;
    cout << "New nickname: " << app_settings->nickname << endl;
    cout << "================================" << endl;
    return ERROR_INFO(S_OK, "success");
}


ERROR_INFO MenuItemType::action()
{
    string arg_type = join(*args_vector);
    if (arg_type == "int" ||
        arg_type == "float"||
        arg_type == "double" ||
        arg_type == "bool" ||
        arg_type == "char" ||
        arg_type == "string")
        {
            cout << "================================" << endl;
            cout << "New type: " << arg_type << endl;
            cout << "================================" << endl;
            *type = arg_type;
        }
    else {
        *type = "int";
        return ERROR_INFO(WARNING_CODE_VALUE, "error type: \"" + arg_type + "\"");
    }
    return ERROR_INFO(S_OK, "success");
}


ERROR_INFO MenuItemVector::action()
{
    ERROR_INFO code(S_OK, "succes");
    if (args_vector->size() != 4)
    {
        return ERROR_INFO(WARNING_CODE_VECTOR, "expected 4 arguments, not" + int(args_vector->size()));
    }

    vector<any> result_any_vec;

    if (*type == "int")
    {
        code = get_int_vector(*vectors->int_vector, *args_vector);
        if (code.code == S_OK)
        {
            data_pool->insert(get_any_vector<int>(*vectors->int_vector));
            print<int>(*vectors->int_vector, *type);
        }
    }
    else if (*type == "float")
    {
        code = get_float_vector(*vectors->float_vector, *args_vector);
        if (code.code == S_OK)
        {
            data_pool->insert(get_any_vector<float>(*vectors->float_vector));
            print<float>(*vectors->float_vector, *type);
        }
    }
    else if (*type == "double")
    {
        code = get_double_vector(*vectors->double_vector, *args_vector);
        if (code.code == S_OK)
        {
            data_pool->insert(get_any_vector<double>(*vectors->double_vector));
            print<double>(*vectors->double_vector, *type);
        }
    }
    else if (*type == "bool")
    {
        code = get_bool_vector(*vectors->bool_vector, *args_vector);
        if (code.code == S_OK)
        {
            data_pool->insert(get_any_vector<bool>(*vectors->bool_vector));
            print<bool>(*vectors->bool_vector, *type);
        }
    }
    else if (*type == "char")
    {
        code = get_char_vector(*vectors->char_vector, *args_vector);
        if (code.code == S_OK)
        {
            data_pool->insert(get_any_vector<char>(*vectors->char_vector));
            print<char>(*vectors->char_vector, *type);
        }
    }
    else if (*type == "string")
    {
        data_pool->insert(get_any_vector<string>(*vectors->string_vector));
        *vectors->string_vector = *args_vector;
        print<string>(*vectors->string_vector, *type);
    }    

    return code;
}


ERROR_INFO MenuItemShow::action()
{
    cout << "=============INFO===============" << endl;
    cout << "User nickname: " << app_settings->nickname << endl;
    cout << "Current type: " << *type << endl;
    cout << "Length vector: " << data_pool->length() << endl;
    cout << "================================" << endl;
    return ERROR_INFO(S_OK, "success");
}

ERROR_INFO MenuItemTest::action()
{
    if (args_vector->size() == 0)
    {
        log("Empty arguments", WARNING);
        return ERROR_INFO(S_OK, "success");
    }
    string test_name = args_vector->at(0);
    shared_ptr<Test> test;
    vector<string> args = *args_vector;
    args.erase(args.begin(), args.begin() + 1);
    if (test_name == "conn")
    {
        test = make_shared<ConnectionTest>(args);
        bool result = test->test();
        if (result)
        {
            log("PASSED", INFO);
        }
        else
        {
            log("FAILED", INFO);
        }
    }
    else if (test_name == "res")
    {
        test = make_shared<ResourceTest>(args);
        bool result = test->test();
        if (result)
        {
            log("PASSED", INFO);
        }
        else
        {
            log("FAILED", INFO);
        }
    }
    else
    {
        log("No test with name \"" + test_name + "\".", ERROR);
    }
    return ERROR_INFO(S_OK, "success");
}


ERROR_INFO MenuItemExit::action()
{
    *exit = true;
    return ERROR_INFO(S_OK, "success");
}
