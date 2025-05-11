cmake_minimum_required(VERSION 3.28)
project(Command)
# Set target name
set(TARGET_NAME Command)
set(CMAKE_CXX_STANDARD 17)

# SeaMiddle 根目录
set(SEA_ROOT_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/../out)
# SeaMiddle 库根目录
set(SEA_LIBRARY_OUTPUT_PATH  ${SEA_ROOT_OUTPUT_PATH}/lib)

add_library(${TARGET_NAME} SHARED Command.cpp
        TaskManager.cpp
        TaskManager.h
        Task.cpp
        Task.h
        CommandImpl.cpp
        CommandImpl.h)

# 定义导出宏
target_compile_definitions(${TARGET_NAME} PRIVATE COMMAND_BUILDING_DLL)
# 添加 Logger 的包含目录
target_include_directories(${TARGET_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}   # 包含当前目录的头文件（如CommandExport.h）
        ../Logger                     # 包含Logger的头文件
)

# 指定Logger的库文件路径并链接
target_link_directories(${TARGET_NAME} PRIVATE ../Logger)  # 假设Logger.lib和Logger.dll在此目录
target_link_libraries(${TARGET_NAME} PRIVATE Logger)      # 链接Logger库

# set output path
if ( MSVC )
    set_target_properties( ${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${SEA_ROOT_OUTPUT_PATH} )
    set_target_properties( ${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${SEA_ROOT_OUTPUT_PATH} )
    set_target_properties( ${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${SEA_ROOT_OUTPUT_PATH} )
else()
    set_target_properties(${TARGET_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${SEA_ROOT_OUTPUT_PATH})
endif()