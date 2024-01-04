cmake_minimum_required(VERSION 3.10)

project(gtk_app)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)


add_executable(${PROJECT_NAME} src/main.cpp ${PROJECT_EMBED_OBJ_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ${GTKMM_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${GTKMM_LIBRARIES})


add_custom_target(copy_assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/assets
)
add_dependencies(${PROJECT_NAME} copy_assets)