cmake_minimum_required(VERSION 3.16.3)

PROJECT(HelloWorld)

#define os Lib's a serem usados
set (LibsHelloWorld ${CMAKE_SOURCE_DIR}/bin/libzghostApi.a)

#define os includes
set (IncludesHelloWorld ${CMAKE_SOURCE_DIR})

add_executable (helloworld main.cpp
                           Console.cpp)

target_link_libraries(helloworld ${LibsHelloWorld})
target_include_directories (helloworld PRIVATE ${IncludesHelloWorld})

add_dependencies(helloworld zghostApi)

INSTALL(FILES ${HelloWorld_BINARY_DIR}/helloworld DESTINATION bin)
