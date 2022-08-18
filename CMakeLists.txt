cmake_minimum_required(VERSION 3.23)
project(PortScanner)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS} -static")
link_libraries(ws2_32 wsock32)

add_executable(PortScanner
        sources/main.cpp
        headers/WinSockErrorInfo.h
        sources/WinSockErrorInfo.cpp)

