cmake_minimum_required(VERSION 3.12)

set(ENGINE_PROJECT_NAME ChimeraEngineCore)

set(ENGINE_PUBLIC_INCLUDES
    include/test.hpp
)

set(ENGINE_PRIVATE_INCLUDES

)

set(ENGINE_PRIVATE_SOURCES
    src/test.cpp
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

set(IMGUI_INCLUDES
    ../Submodules/imgui/imgui.h
)

set(IMGUI_SOURCES
    ../Submodules/imgui/imgui.cpp
    ../Submodules/imgui/imgui_demo.cpp
    ../Submodules/imgui/imgui_draw.cpp
    ../Submodules/imgui/imgui_tables.cpp
    ../Submodules/imgui/imgui_widgets.cpp
)

set(IMGUI_BACKENDS
    ../Submodules/imgui/backends/imgui_impl_sdl2.h
    ../Submodules/imgui/backends/imgui_impl_sdl2.cpp
    ../Submodules/imgui/backends/imgui_impl_opengl3.h
    ../Submodules/imgui/backends/imgui_impl_opengl3.cpp
    #../Submodules/imgui/backends/imgui_impl_dx12.h
    #../Submodules/imgui/backends/imgui_impl_dx12.cpp
    ../Submodules/imgui/backends/imgui_impl_vulkan.h
    ../Submodules/imgui/backends/imgui_impl_vulkan.cpp
)

add_library(ImGUI STATIC
    ${IMGUI_INCLUDES}
    ${IMGUI_SOURCES}
    ${IMGUI_BACKENDS}
)

target_include_directories(ImGUI PUBLIC ../Submodules)
target_include_directories(ImGUI PUBLIC ../Submodules/imgui)
target_include_directories(ImGUI PUBLIC ../Submodules/imgui/backends)

add_subdirectory(../Submodules/SDL ${CMAKE_CURRENT_BINARY_DIR}/SDL)

target_include_directories(${ENGINE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../Submodules/SDL/include)

target_include_directories(${ENGINE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${ENGINE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

find_package(OpenGL REQUIRED)
find_package(Vulkan REQUIRED)

target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE SDL3::SDL3 ImGUI OpenGL::GL Vulkan::Vulkan)

target_compile_features(${ENGINE_PROJECT_NAME} PUBLIC cxx_std_17)
