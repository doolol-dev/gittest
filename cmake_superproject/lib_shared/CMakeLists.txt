# Задать имя проекта и версию
project(lib_shared VERSION ${PROJECT_VERSION})

# Указываем файл для конфигурации при помощи CMake
configure_file(version.h.in "${CMAKE_BINARY_DIR}/${PROJECT_NAME}/include/${PROJECT_NAME}_version.h")

# Добавить в проект цель - заголовочная библиотека
add_library(${PROJECT_NAME} SHARED
    src/lib_shared.cpp
)

# Добавить алиас для текущей цели
add_library(superproject::lib_shared ALIAS ${PROJECT_NAME})

# Установить свойства для цели
set_target_properties(${PROJECT_NAME}  PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

# Установить директории заголовочных файлов
target_include_directories(${PROJECT_NAME} 
    PUBLIC "${PROJECT_SOURCE_DIR}/include"
)

# Правила установки для проекта
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION lib)