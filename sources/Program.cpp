#include "Program.h"


Program::Program(shared_ptr<AppSettings> app_settings)
{
    this->app_settings = app_settings;
    data_pool = make_shared<DataPool>();
    vectors = make_shared<AnyVectors>();
    
    command_vector = make_shared<vector<string>>();
    type = make_shared<string>("int");
    vectors = make_shared<AnyVectors>();
    exit = make_shared<bool>(false);

    menu = make_shared<Menu>();
    menu->add_item("name", make_shared<MenuItemName>(command_vector, app_settings), " - name <nickname>");
    menu->add_item("type", make_shared<MenuItemType>(command_vector, type), " - type <type>(int, string, double, float, bool, char)>");
    menu->add_item("vector", make_shared<MenuItemVector>(command_vector, vectors, type, data_pool), " - vector <value_1> <value_2> <value_3> <value_4>");
    menu->add_item("show", make_shared<MenuItemShow>(app_settings, type, data_pool), " - show (show actual information)");
    menu->add_item("test", make_shared<MenuItemTest>(command_vector), " - test <name_test(\"conn\" or \"res\")> <param1> <param2>");
    menu->add_item("exit", make_shared<MenuItemExit>(exit), " - exit");
}


int Program::start()
{
    print_user_info();
    while (!(*exit)) {
        menu->print();

        get_command();
        if (command_vector->size() == 0)
        {
            continue;
        }

        string command_name = command_vector->at(0);
        command_vector->erase(command_vector->begin(), command_vector->begin() + 1);

        log("user command: " + command_name + " " + join(*command_vector, " "), INFO);
        error_info = menu->process_command(command_name);
        if (error_info.code != S_OK)
        {
            log(error_info.info, ERROR);
            cout << "Error of entering values" << endl;
        }
    }

    return 0;
}


void Program::print_user_info()
{
    cout << "Client data:" << endl;
    cout << "IP Address: " << app_settings->ip_address << endl;
    cout << "Role: " << app_settings->client_role << endl;
    cout << "I: " << app_settings->i << endl;
    cout << "Lib: " << app_settings->lib << endl;
}


void Program::get_command()
{
    cout << "command: ";
    string command;
    getline(cin, command); cout << endl;
    command = tolower(command);
    *command_vector = split_string(command);
}
