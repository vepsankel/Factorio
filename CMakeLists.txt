cmake_minimum_required(VERSION 3.24)
project(Factorio C)

set(CMAKE_C_STANDARD 23)

add_executable(Factorio main.c util/list/src/listinc.c resources/src/rscmain.c resources/src/rsccmd.c cli/inc/climain.h cli/src/climain.c resources/inc/rscinc.h cli/inc/cliinc.h resources/inc/rscglobal.h global.h util/list/inc/list.h)
target_include_directories(Factorio PUBLIC resources/inc util/list/inc)