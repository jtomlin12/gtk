cmake_minimum_required(VERSION 3.10)

project(gtk_app)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

# glob is not preferred solution
set(glade_files ${CMAKE_SOURCE_DIR}/assets/app.glade)

foreach(glade_file ${glade_files})
    get_filename_component(filename ${glade_file} NAME)
    configure_file(${glade_file} . COPYONLY)

    get_filename_component(basename ${glade_file} NAME_WE)
    set(glade_obj_file "${basename}.o")

    add_custom_command(
            OUTPUT ${glade_obj_file}
            COMMAND ld -r -b binary -o ${glade_obj_file} ${filename}
            DEPENDS ${glade_file}
            VERBATIM
    )
    list(APPEND glade_obj_files ${glade_obj_file})
endforeach()

add_executable(${PROJECT_NAME} src/main.cpp ${glade_obj_files})
target_include_directories(${PROJECT_NAME} PRIVATE ${GTKMM_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${GTKMM_LIBRARIES})
