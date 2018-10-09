
add_definitions(-DEXPMODULE)

file(GLOB SOURCES  ${CMAKE_SOURCE_DIR}/andromeda/tests/*.cpp 
					${CMAKE_SOURCE_DIR}/andromeda/*.cpp 
				   ${CMAKE_SOURCE_DIR}/andromeda/src/qtime/*.cpp
				   ${CMAKE_SOURCE_DIR}/andromeda/src/yield/*.cpp
				   ${CMAKE_SOURCE_DIR}/andromeda/src/instrument/*.cpp)
file(GLOB HEADERS ${CMAKE_SOURCE_DIR}/andromeda/inc/*.h 
			      ${CMAKE_SOURCE_DIR}/andromeda/src/*.h 
				  ${CMAKE_SOURCE_DIR}/andromeda/src/qtime/*.h
				   ${CMAKE_SOURCE_DIR}/andromeda/src/yield/*.h
				   ${CMAKE_SOURCE_DIR}/andromeda/src/instrument/*.h)

message(STATUS "/////////////////////////" ${SOURCES})
message(STATUS "/////////////////////////" ${HEADERS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(BOOST_LIBRARYDIR "/usr/local/lib")
set(BOOST_ROOT "/usr/local/include/boost")

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 

#Setup CMake to run tests
enable_testing()

find_package(Boost 1.67 COMPONENTS system filesystem unit_test_framework date_time REQUIRED)

if(NOT Boost_FOUND)
	error("BOOST LIBS not found")
endif()

message(STATUS "Boost_INCLUDE_DIRS")
message(STATUS ${Boost_INCLUDE_DIRS})

message(STATUS "Boost_LIBRARIES")
message(STATUS ${Boost_LIBRARIES})

message(STATUS "Boost_LIBRARY_DIRS")
message(STATUS ${Boost_LIBRARY_DIRS})

include_directories( ${Boost_INCLUDE_DIRS} )
link_directories(${Boost_LIBRARY_DIRS})

add_executable(
    andromeda
        ${SOURCES} 
        ${HEADERS}
)

target_include_directories(
    andromeda 
        PUBLIC "inc"
)
