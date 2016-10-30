# This is a comment

# set cmake flags for all warnings & enable debuging
set (CMAKE_C_FLAGS "-Wall -g")

file(GLOB SourceFiles *.cpp *.h)

# now the exercutable (kind of a VS project for the solution)
add_executable(ExpermentalCode ${SourceFiles})
