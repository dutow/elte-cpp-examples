# Basic compiler flags: warning levels, treat warnings as errors, c++11

IF ((CMAKE_COMPILER_IS_GNUCXX) OR ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang"))
  SET (CMAKE_CXX_FLAGS "-std=c++14 -Wall -pedantic")
ENDIF ()

IF (MSVC)
	SET( CMAKE_CXX_FLAGS "/W3 /EHsc" )
	SET( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd" )
	SET( CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD" )
	SET( CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /MD" )
ENDIF ()
