#include "main.h"



int main(int argc, char *argv[]) {
    shared_ptr<AppSettings> app_settings = make_shared<AppSettings>();
    ERROR_INFO error_info = app_settings->init(argc, argv);
    if (error_info.code != S_OK)
    {
        log(error_info.info, ERROR);
        return error_info.code;
    }
    Program program(app_settings);
    program.start();
    return 0;
}