cmake_minimum_required(VERSION 3.28)
project(Logger)
# Set target name
set(TARGET_NAME Logger)
set(CMAKE_CXX_STANDARD 17)

add_library(${TARGET_NAME} SHARED Logger.cpp)

# SeaMiddle 根目录
set(SEA_ROOT_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/../out)
# SeaMiddle 库根目录
set(SEA_LIBRARY_OUTPUT_PATH  ${SEA_ROOT_OUTPUT_PATH}/lib)

target_compile_definitions(${TARGET_NAME} PRIVATE LOGGER_BUILDING_DLL)

# set output path
if ( MSVC )
    set_target_properties( ${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${SEA_ROOT_OUTPUT_PATH} )
    set_target_properties( ${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${SEA_ROOT_OUTPUT_PATH} )
    set_target_properties( ${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${SEA_ROOT_OUTPUT_PATH} )
else()
    set_target_properties(${TARGET_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${SEA_ROOT_OUTPUT_PATH})
endif()