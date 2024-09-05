cmake_minimum_required(VERSION 3.16)

project(Ejemplo1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Ejemplo1 main.cpp
    usuario.h usuario.cpp)

include(GNUInstallDirs)
install(TARGETS Ejemplo1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
