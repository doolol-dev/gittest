# Устанавливаем минимально необходимую версию cmake для проекта
cmake_minimum_required(VERSION 3.10)

# Установить запись в кэше с номером патча
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")

# Установить переменную с номером версии
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

# Задать имя проекта и версию
project(cmake_simple_prj VERSION ${PROJECT_VESRION})

# Указываем файл для конфигурации при помощи CMake
configure_file(version.h.in version.h)

# Добавить в проект цель - исполняемый файл
add_executable(cmake_simple_prj main.cpp)

# Установить свойства для цели
set_target_properties(cmake_simple_prj PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

# Установить директории заголовочных файлов
target_include_directories(cmake_simple_prj
    PRIVATE "${CMAKE_BINARY_DIR}"
)

# Установить параметры компиляции
target_compile_options(cmake_simple_prj PRIVATE
    -Wall -Wextra -pedantic -Werror
)

# Правила установки для проекта
install(TARGETS cmake_simple_prj RUNTIME DESTINATION bin)

# Правила генерации пакета
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT efrdoo@gmail.com)
include(CPack)