project(tests)
add_definitions(-DEXPMODULE)

file(GLOB SOURCES  ${CMAKE_SOURCE_DIR}/andromeda/tests/*.cpp )
file(GLOB HEADERS ${CMAKE_SOURCE_DIR}/andromeda/inc/libdef.h
			      ${CMAKE_SOURCE_DIR}/andromeda/src/*.h 
				  ${CMAKE_SOURCE_DIR}/andromeda/src/qtime/*.h
				   ${CMAKE_SOURCE_DIR}/andromeda/src/yield/*.h
				   ${CMAKE_SOURCE_DIR}/andromeda/src/instrument/*.h)

message(STATUS "/////////////////////////" ${SOURCES})
message(STATUS "/////////////////////////" ${HEADERS})

if (WIN32)
	message(STATUS "------------------:configuring windows")
	set(BOOST_LIBRARYDIR "C:/Boost/lib")
	set(BOOST_ROOT "C:/Boost/include/boost-1_68")
endif (WIN32)

if (UNIX)
	message(STATUS "------------------:configuring unix")
	set(BOOST_LIBRARYDIR "/opt/dev/lib")
	set(BOOST_ROOT "/opt/dev/include")
endif (UNIX)


set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 

#Setup CMake to run tests
enable_testing()

find_package(Boost 1.68 COMPONENTS system filesystem unit_test_framework date_time REQUIRED)

if(NOT Boost_FOUND)
	error("BOOST LIBS not found")
endif()

message(STATUS "Boost_INCLUDE_DIRS")
message(STATUS ${Boost_INCLUDE_DIRS})

message(STATUS "Boost_LIBRARIES")
message(STATUS ${Boost_LIBRARIES})

message(STATUS "Boost_LIBRARY_DIRS")
message(STATUS ${Boost_LIBRARY_DIRS})

include_directories( ${Boost_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/andromeda/inc)
link_directories(${Boost_LIBRARY_DIRS})

foreach(testSrc ${SOURCES})
        #Extract the filename without an extension (NAME_WE)
        get_filename_component(testName ${testSrc} NAME_WE)
		
        #Add compile target
        add_executable(${testName} ${testSrc})
		
        #link to Boost libraries AND your targets and dependencies
        target_link_libraries(${testName} ${Boost_LIBRARIES} andromeda)

        #Finally add it to test execution - 
        #Notice the WORKING_DIRECTORY and COMMAND
        add_test(NAME ${testName} 
                 WORKING_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}
                 COMMAND ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/${testName} )
		message(STATUS "------------------------------>TEST ADDED")

endforeach(testSrc)
