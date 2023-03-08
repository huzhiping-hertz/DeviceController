include(DrogonUtilities.cmake)
set(APP_NAME "WebApi")
file(GLOB_RECURSE cpp_files "*.cpp")

add_executable(${APP_NAME} main.cpp)
target_link_libraries(${APP_NAME} nlohmann_json::nlohmann_json Drogon::Drogon Poco::Net OSMonitor)

aux_source_directory(controllers CTL_SRC)
aux_source_directory(filters FILTER_SRC)
aux_source_directory(plugins PLUGIN_SRC)
aux_source_directory(models MODEL_SRC)


drogon_create_views(${APP_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/views ${CMAKE_CURRENT_BINARY_DIR})

target_include_directories(${APP_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/models)
target_sources(${APP_NAME} PRIVATE
               ${SRC_DIR}
               ${CTL_SRC}
               ${FILTER_SRC}
               ${PLUGIN_SRC}
               ${MODEL_SRC})

file(COPY ./web.json DESTINATION ${PROJECT_SOURCE_DIR}/bin/)
file(COPY resources DESTINATION ${PROJECT_SOURCE_DIR}/bin/)