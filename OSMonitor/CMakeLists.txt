set(library_name "OSMonitor")
file(GLOB cpp_files "*.cpp")
add_library(${library_name} STATIC ${cpp_files})
target_link_libraries(${library_name} )