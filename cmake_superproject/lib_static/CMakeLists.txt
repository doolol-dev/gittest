# Задать имя проекта и версию
project(lib_static VERSION ${PROJECT_VERSION})

# Указываем файл для конфигурации при помощи CMake
configure_file(version.h.in "${CMAKE_BINARY_DIR}/${PROJECT_NAME}/include/${PROJECT_NAME}_version.h")

# Добавить в проект цель - заголовочная библиотека
add_library(${PROJECT_NAME} STATIC
    src/lib_static.cpp
)

# Добавить алиас для текущей цели
add_library(superproject::lib_static ALIAS ${PROJECT_NAME})

# Установить свойства для цели
set_target_properties(${PROJECT_NAME}  PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

# Установить директории заголовочных файлов
target_include_directories(${PROJECT_NAME} 
    PUBLIC "${PROJECT_SOURCE_DIR}/include"
    PRIVATE "${PROJECT_SOURCE_DIR}/src"
)

# Правила установки для проекта
install (TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)