project(ExpermentalCode)
	cmake_minimum_required(VERSION 2.6)
	add_subdirectory(SourceCode)
# This set command might not be used, (Still learning cmake at time of writting)
set(
    CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_HOME_DIRECTORY}/Build
    )
	
	
