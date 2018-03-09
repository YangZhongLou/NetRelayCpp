
set(test_name client)
file(GLOB source *.cpp)

set(main_cpp client.cpp)

if(WIN32)
	add_executable(${test_name} ${main_cpp} ${source})
else(WIN32)
	add_executable(${test_name} ${main_cpp} ${source})
		target_link_libraries(${test_name} ${boost_libs} pthread)

endif(WIN32)