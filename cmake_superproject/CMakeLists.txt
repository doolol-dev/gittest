##############################################
# Конфигурационный файл суперпроекта         #
##############################################

# Устанавливаем минимально необходимую версию cmake для проекта
cmake_minimum_required(VERSION 3.10)

# Установить запись в кэше с номером патча
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")

# Установить переменную с номером версии
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

# Задать имя проекта и версию
project(superproject VERSION ${PROJECT_VERSION})

# Добавить в суперпроект подпроекты
add_subdirectory(exec_app_1)
add_subdirectory(exec_app_2)
add_subdirectory(lib_header)
add_subdirectory(lib_shared)


# # Правила установки для проекта
# install(TARGETS cmake_simple_prj RUNTIME DESTINATION bin)

# Правила генерации пакета
set(CPACK_GENERATOR DEB STGZ ZIP)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT efrdoo@gmail.com)
include(CPack)