execute_process(COMMAND cppcheck
   --enable=warning,performance,portability,information,missingInclude
   --std=c++11
   --template="[{severity}][{id}]{message}{callstack}\(On{file}:{line}\)"
   --verbose
   --quiet
   ./
   WORKING_DIRECTORY
   ${CMAKE_CURRENT_SOURCE_DIR}
   OUTPUT_QUIET
   COMMAND_ERROR_IS_FATAL ANY
)
