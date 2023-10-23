#include <iostream>
#include "exec_app_2_version.h"
#include "exec_app_2.h"
#include "subdir/subfile.h"
#include <lib_header/lib_header.h>

int main (int, char **) {
    std::cout << "Version: " << PROJECT_VERSION_PATCH << std::endl;
    std::cout << THIS_NAME << std::endl;
    std::cout << THIS_LIB_HEADER << std::endl;
    return 0;
}