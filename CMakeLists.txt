cmake_minimum_required(VERSION 3.12)
project(ChimeraEngine)

set(PROJECT_NAME ChimeraEngine)

add_subdirectory(ChimeraEngineCore)
add_subdirectory(ChimeraEngineEditor)
#add_subdirectory(Tests)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
