# Задать имя проекта и версию
project(exec_app_1 VERSION ${PROJECT_VERSION})

# Указываем файл для конфигурации при помощи CMake
configure_file(version.h.in "${CMAKE_BINARY_DIR}/${PROJECT_NAME}/include/version.h")

# Добавить в проект цель - исполняемый файл
add_executable(${PROJECT_NAME}  
    src/main.cpp
)

# Установить свойства для цели
set_target_properties(${PROJECT_NAME}  PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

# Установить директории заголовочных файлов
target_include_directories(${PROJECT_NAME} 
    PRIVATE ./include 
    PRIVATE "${CMAKE_BINARY_DIR}/${PROJECT_NAME}/include"
)

# Установить параметры компиляции
target_compile_options(${PROJECT_NAME}  PRIVATE
    -Wall -Wextra -pedantic -Werror
)

# Правила установки для проекта
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)