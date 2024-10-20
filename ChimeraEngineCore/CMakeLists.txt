cmake_minimum_required(VERSION 3.12)

set(ENGINE_PROJECT_NAME ChimeraEngineCore)

set(ENGINE_PUBLIC_INCLUDES
    include/Application.hpp
    include/Window.hpp
    include/APIContextPicker.hpp
    include/APIContext.hpp
)

set(ENGINE_PRIVATE_INCLUDES
    
)

set(ENGINE_PRIVATE_SOURCES
    src/Application.cpp
    src/Window.cpp
    src/WindowImpl.cpp
    src/WindowImpl.hpp

    src/APIContext/APIContext.cpp
    src/APIContext/APIContextPicker.cpp
    src/APIContext/OpenGLContext.hpp
    src/APIContext/OpenGLContext.cpp
    src/APIContext/VulkanContext.hpp
    src/APIContext/VulkanContext.cpp
    src/APIContext/DirectXContext.hpp
    src/APIContext/DirectXContext.cpp
)

set(ENGINE_ALL_SOURCES
    ${ENGINE_PUBLIC_INCLUDES}
    ${ENGINE_PRIVATE_INCLUDES}
    ${ENGINE_PRIVATE_SOURCES}
)

add_library(${ENGINE_PROJECT_NAME} STATIC
    ${ENGINE_ALL_SOURCES}
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES
    ${ENGINE_ALL_SOURCES}
)

add_subdirectory(../Submodules/SDL ${CMAKE_CURRENT_BINARY_DIR}/SDL)

target_include_directories(${ENGINE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../Submodules/SDL/include)

target_include_directories(${ENGINE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${ENGINE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE SDL3::SDL3)

target_compile_features(${ENGINE_PROJECT_NAME} PUBLIC cxx_std_17)
