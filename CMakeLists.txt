
CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(elte-cpp-examples)

SET( VERSION_MAJOR   0   CACHE STRING "Project major version number." )
SET( VERSION_MINOR   1   CACHE STRING "Project minor version number." )
SET( VERSION_PATCH   0   CACHE STRING "Project patch version number." )
MARK_AS_ADVANCED( VERSION_MAJOR VERSION_MINOR VERSION_PATCH )

SET ( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
SET ( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

SET( CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules ${CMAKE_MODULE_PATH} )
INCLUDE( GroupInVisualStudio )
INCLUDE( BuildHelpers )
INCLUDE( CompilerFlags )

# boost
SET(Boost_USE_STATIC_LIBS ON)
SET ( BOOST_ROOT ${CMAKE_SOURCE_DIR}/vendor/boost-install/ )
FIND_PACKAGE(Boost 1.60.0 REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})


ADD_DEFINITIONS( -DSFML_STATIC )
set( gtest_force_shared_crt ON CACHE BOOL "Always use msvcrt.dll" FORCE )

ADD_SUBDIRECTORY( vendor )
INCLUDE_DIRECTORIES(vendor/SFML/include/)
INCLUDE_DIRECTORIES(vendor/googletest/include/)
SET( SFML_DEPENDENCIES sfml-graphics )

# common assets
INSTALL( DIRECTORY "assets/" DESTINATION "." )
FILE( COPY "assets/" DESTINATION "${CMAKE_BINARY_DIR}" )

ADD_SUBDIRECTORY(lesson-01)
ADD_SUBDIRECTORY(lesson-02)
ADD_SUBDIRECTORY(lesson-03)
ADD_SUBDIRECTORY(lesson-04)
ADD_SUBDIRECTORY(lesson-05)
ADD_SUBDIRECTORY(lesson-06)
ADD_SUBDIRECTORY(lesson-07)
ADD_SUBDIRECTORY(lesson-08)
ADD_SUBDIRECTORY(lesson-09)


SET(CPACK_GENERATOR "ZIP")
INCLUDE( CPack )

