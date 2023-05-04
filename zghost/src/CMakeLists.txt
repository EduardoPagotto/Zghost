cmake_minimum_required(VERSION 3.16.3)

PROJECT(zghostApi)

#define objetos a compilar
set (SourcesCore z80/Z80.cpp
                 z80/OpCode.cpp
                 z80/OpCodeCB.cpp
                 z80/OpCodeED.cpp
                 z80/OpCodeDD.cpp
                 z80/OpCodeFD.cpp
                 z80/OpCodeDDCBFDCB.cpp
                 bus/Bus.cpp
                 bus/Latch.cpp
                 bus/PPI8255.cpp)

# #define os includes
set (IncludeCore ${CMAKE_SOURCE_DIR})
# set (IncludeCoreAux ${OPENGL_INCLUDE_DIR}
#                                         ${SDL2_INCLUDE_DIR}
#                                         ${GLEW_INCLUDE_DIRS})

# Define o Target
add_library (zghostApi STATIC ${SourcesCore})

# Define os includes privados para este target
target_include_directories (zghostApi PUBLIC ${IncludeCore})
                                      #PRIVATE ${IncludeCoreAux})

# Lista os Includes
# get_property(dirs DIRECTORY ${IncludeCore}/chimera/core PROPERTY INCLUDE_DIRECTORIES)
# foreach(dir ${dirs})
#       message(STATUS "Include dir='${dir}'")
# endforeach()

INSTALL(FILES ${zghostApi_BINARY_DIR}/libzghostApi.a DESTINATION lib)
INSTALL(DIRECTORY ${IncludeCore}/zghost DESTINATION ${CMAKE_INSTALL_PREFIX}/include/zghost FILES_MATCHING PATTERN "*.h*")
