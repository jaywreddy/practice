cmake_minimum_required (VERSION 2.8.11)
project (Weather)

#add_subdirectory(cpp-netlib)
add_executable(weather weather.cpp)

set ( CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ~/cpp-netlib-build )
find_package ( cppnetlib 0.11.0 REQUIRED )
include_directories ( ${CPPNETLIB_INCLUDE_DIRS} )
target_link_libraries ( weather ${CPPNETLIB_LIBRARIES} )
