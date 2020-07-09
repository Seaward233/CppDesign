cmake_minimum_required(VERSION 3.0.0)
project(cppDesign)

include(CTest)
enable_testing()

aux_source_directory(. DIR_SRCS)

add_executable(cppDesign ${DIR_SRCS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
