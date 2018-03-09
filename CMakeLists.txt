
function(init_cmake)
	cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
	cmake_policy(VERSION 2.8)
	set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
endfunction(init_cmake)
init_cmake()

set(NAME NetRelay)

project(${NAME})

include_directories(externals)
include_directories(externals/boost_1_66_0)
include_directories(src)


#Preprocessor
IF(WIN32)
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -W3")
ENDIF()

IF(MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc")
	add_compile_options("/std:c++latest")
	link_directories(${CMAKE_SOURCE_DIR}/externals/boost_1_66_0/stage_x64/lib)
ENDIF(MSVC)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")

add_subdirectory(src)
