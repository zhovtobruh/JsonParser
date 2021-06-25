cmake_minimum_required(VERSION 3.5)
project(JsonParser  LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF)


find_package(Boost COMPONENTS system thread  REQUIRED) 

set(CMAKE_SOURCE_DIR src)
set(SOURCE 
    ${CMAKE_SOURCE_DIR}/main.cpp 
    ${CMAKE_SOURCE_DIR}/CmdParser/CmdParser.cpp
    ${CMAKE_SOURCE_DIR}/JsonParser/JsonParser.cpp
    )
set( INCLUDE_DIR ${CMAKE_SOURCE_DIR}/CmdParser ${CMAKE_SOURCE_DIR}/JsonParser)
add_executable(JsonParser ${SOURCE})
target_include_directories(JsonParser  PRIVATE ${Boost_INCLUDE_DIRS}  ${INCLUDE_DIR}) 
target_link_libraries(JsonParser  boost_program_options boost_system boost_thread pthread)

