cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(cmake_simple_prj VERSION ${PROJECT_VESRION})

configure_file(version.h.in version.h)

add_executable(cmake_simple_prj main.cpp)

set_target_properties(cmake_simple_prj PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(cmake_simple_prj
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_compile_options(cmake_simple_prj PRIVATE
    -Wall -Wextra -pedantic -Werror
)

install(TARGETS cmake_simple_prj RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT efrdoo@gmail.com)
include(CPack)