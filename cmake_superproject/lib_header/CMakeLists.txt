# Задать имя проекта и версию
project(lib_header VERSION ${PROJECT_VERSION})

# Указываем файл для конфигурации при помощи CMake
configure_file(version.h.in "${CMAKE_BINARY_DIR}/${PROJECT_NAME}/include/${PROJECT_NAME}_version.h")

# Добавить в проект цель - заголовочная библиотека
add_library(${PROJECT_NAME} INTERFACE)

# Добавить алиас для текущей цели
add_library(superproject::lib_header ALIAS ${PROJECT_NAME})

# Установить свойства для цели
set_target_properties(${PROJECT_NAME}  PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

message(STATUS "${PROJECT_SOURCE_DIR}")

# Установить директории заголовочных файлов
target_include_directories(${PROJECT_NAME} 
    INTERFACE "${PROJECT_SOURCE_DIR}/include"
)

# Правила установки для проекта
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)