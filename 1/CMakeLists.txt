cmake_minimum_required(VERSION 3.16)
project(HistorianHysteria CXX)

# 使用 C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 生成可执行文件 HistorianHysteria.exe
add_executable(HistorianHysteria
    main.cpp
    HistorianHysteria.cpp
)

# 指定头文件目录（当前目录即可）
target_include_directories(HistorianHysteria PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
