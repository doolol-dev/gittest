#include <iostream>
#include "version.h"
#include "exec_app_2.h"
#include "subdir/subfile.h"

int main (int, char **) {
    std::cout << "Version: " << PROJECT_VERSION_PATCH << std::endl;
    std::cout << THIS_NAME << std::endl;
    std::cout << THIS_SUBFILE << std::endl;
    return 0;
}