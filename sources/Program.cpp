#include "Program.h"


Program::Program(AppSettings *app_settings)
{
    this->app_settings = app_settings;
    data_pool = new DataPool();
    vectors = new AnyVectors();

    menu = new Menu();
    menu->add_item("name", new MenuItemName(&command_vector, app_settings), " - name <nickname>");
    menu->add_item("type", new MenuItemType(&command_vector, &type), " - type <type (int, string, double, float, bool, char)>");
    menu->add_item("vector", new MenuItemVector(&command_vector, vectors, &type, data_pool), " - vector <value_1> <value_2> <value_3> <value_4>");
    menu->add_item("show", new MenuItemShow(app_settings, &type, data_pool), " - show (show actual information)");
    menu->add_item("test", new MenuItemTest(&command_vector), " - test <name_test(\"conn\" or \"res\")> <param1> <param2>");
    menu->add_item("exit", new MenuItemExit(&exit), " - exit");
}


Program::~Program()
{
    delete app_settings;
    delete data_pool;
    delete menu;
    delete vectors;
}


int Program::start()
{
    print_user_info();
    while (!exit) {
        menu->print();

        get_command();
        if (command_vector.size() == 0)
        {
            continue;
        }

        string command_name = command_vector[0];
        command_vector.erase(command_vector.begin(), command_vector.begin() + 1);

        log("user command: " + command_name + " " + join(command_vector, " "), INFO);
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
    cout << "IP Address: " << app_settings->address << endl;
    cout << "Port: " << app_settings->port << endl;
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
    command_vector = split_string(command);
}
