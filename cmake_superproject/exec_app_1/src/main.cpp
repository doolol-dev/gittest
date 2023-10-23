#include <iostream>
#include "exec_app_1_version.h"
#include "exec_app_1.h"
#include "subdir/subfile.h"
#include "lib_header/lib_header.h"
#include "lib_shared/lib_shared.h"

int main (int, char **) {
    std::cout << "Version: " << PROJECT_VERSION_PATCH << std::endl;
    std::cout << THIS_NAME << std::endl;
    std::cout << THIS_SUBFILE << std::endl;
    std::cout << THIS_LIB_HEADER << std::endl;
    std::cout << lib_shared_f() << std::endl;
    return 0;
}