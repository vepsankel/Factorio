cmake_minimum_required(VERSION 3.24)
project(Factorio C)

set(CMAKE_C_STANDARD 23)

add_executable(Factorio main.c util/src/list.c resources/src/rscmain.c resources/src/rsccmd.c cli/inc/climain.h cli/src/climain.c)
target_include_directories(Factorio PUBLIC resources/inc util/inc)