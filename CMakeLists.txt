cmake_minimum_required(VERSION 3.28)
project(Run)

set(CMAKE_CXX_STANDARD 17)

add_executable(Run main.cpp)

# 添加 Logger 的包含目录
target_include_directories(Run PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Logger
        ${CMAKE_CURRENT_SOURCE_DIR}/Command
)

# 指定Logger的库文件路径并链接
target_link_directories(Run PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Logger
        ${CMAKE_CURRENT_SOURCE_DIR}/Command
)

target_link_libraries(Run PRIVATE
        Logger
        Command
)
# 链接Logger库
# Set output path
#if (MSVC)
#    set_target_properties( ${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${SEA_ROOT_OUTPUT_PATH} )
#    set_target_properties( ${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${SEA_ROOT_OUTPUT_PATH} )
#    set_target_properties( ${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${SEA_ROOT_OUTPUT_PATH} )
#else()
#    set_target_properties(${TARGET_NAME} PROPERTIES EXECUTABLE_OUTPUT_PATH ${SEA_ROOT_OUTPUT_PATH})
#endif()
# build all
add_subdirectory(Logger)
add_subdirectory(Command)