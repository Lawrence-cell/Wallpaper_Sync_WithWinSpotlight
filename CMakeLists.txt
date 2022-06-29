cmake_minimum_required(VERSION 3.0.0)
project(Wallpaper_Sync VERSION 0.1.0)

include(CTest)
enable_testing()

aux_source_directory(. APP_DIR)
aux_source_directory(src/yg APP_DIR)
add_executable(Wallpaper_Sync ${APP_DIR})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
