# 
# Helper functions for the cmake build process to build executables or static libraries
#
# Usage:
#
# MODIFY_SCOPE( name ) in source directories
#
# BUILD_EXECUTABLE( dep1 dep2 dep3 ) for an executable
# BUILD_STATIC_LIB() to build a static lib
#

MACRO( MODIFY_SCOPE addto )
  IF( NOT BUILD_SCOPE )
    SET ( BUILD_SCOPE ${addto} )
    SET ( BUILD_SCOPEDIR ${addto} )
  ELSE( NOT BUILD_SCOPE )
    SET( BUILD_SCOPE "${BUILD_SCOPE}-${addto}" )
    SET( BUILD_SCOPEDIR "${BUILD_SCOPEDIR}/${addto}" )
  ENDIF( NOT BUILD_SCOPE )
ENDMACRO( MODIFY_SCOPE )

MACRO( BUILD_EXECUTABLE )

  SET( MYLIBS ${LIBS} ${ARGV} )

  FILE( GLOB_RECURSE ${BUILD_SCOPE}-sources *.cpp )
  FILE( GLOB_RECURSE ${BUILD_SCOPE}-headers *.hpp "${CMAKE_CURRENT_BINARY_DIR}/*.hpp" "${PROJECT_SOURCE_DIR}/assets/${BUILD_SCOPEDIR}/*.glsl" )

  ADD_EXECUTABLE( ${BUILD_SCOPE} ${${BUILD_SCOPE}-sources} ${${BUILD_SCOPE}-headers} )
  TARGET_LINK_LIBRARIES(${BUILD_SCOPE} ${MYLIBS})
  GroupInVisualStudio()
  
  # INSTALLING
  INSTALL( TARGETS "${BUILD_SCOPE}" RUNTIME DESTINATION bin)
  #INSTALL( DIRECTORY "${PROJECT_SOURCE_DIR}/assets/${BUILD_SCOPEDIR}/" DESTINATION "${BUILD_SCOPEDIR}/assets" )
ENDMACRO( BUILD_EXECUTABLE )

MACRO( BUILD_STATIC_LIB )
  FILE( GLOB_RECURSE ${BUILD_SCOPE}-sources *.cpp )
  FILE( GLOB_RECURSE ${BUILD_SCOPE}-headers *.hpp "${CMAKE_CURRENT_BINARY_DIR}/*.hpp" "${CMAKE_PROJECT_SOURCE_DIR}/assets/${BUILD_SCOPEDIR}*.glsl" )
  ADD_LIBRARY( ${BUILD_SCOPE} ${${BUILD_SCOPE}-sources} ${${BUILD_SCOPE}-headers} )

  GroupInVisualStudio()
ENDMACRO( BUILD_STATIC_LIB )
