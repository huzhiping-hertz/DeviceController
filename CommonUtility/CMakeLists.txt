set(library_name "CommonUtility")
file(GLOB cpp_files "*.cpp")
add_library(${library_name} STATIC ${cpp_files})
target_link_libraries(${library_name}  Poco::Poco Poco::Foundation Poco::Net gflags::gflags)