cmake_minimum_required(VERSION 3.20)
project(GrapE)
find_program(GLSLC glslc)

#macro(print_all_variables)
#    message(SEND_ERROR "print_all_variables------------------------------------------{")
#    get_cmake_property(_variableNames VARIABLES)
#    foreach (_variableName ${_variableNames})
#        message(STATUS "${_variableName}=${${_variableName}}")
#    endforeach()
#    message(STATUS "print_all_variables------------------------------------------}")
#endmacro()

set(CMAKE_CXX_STANDARD 17)
set(GLFW_LIBRARY C:\\Libraries\\glfw-3.3.4.bin.WIN64\\lib-vc2019\\glfw3.lib)
set(GLFW_INCLUDE_DIR C:\\Libraries\\glfw-3.3.4.bin.WIN64\\include)
set(glm_DIR C:\\Libraries\\glm-0.9.9.8\\cmake\\glm)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

add_executable(GrapE main.cpp grp_window.hpp grp_window.cpp App.cpp App.hpp grp_pipeline.hpp grp_pipeline.cpp grp_device.hpp grp_device.cpp grp_swap_chain.cpp grp_swap_chain.hpp grp_model.cpp grp_model.hpp grp_game_object.cpp grp_game_object.hpp grp_renderer.cpp grp_renderer.hpp simple_render_system.cpp simple_render_system.hpp grp_camera.cpp grp_camera.hpp keyboard_movement_controller.cpp keyboard_movement_controller.hpp grp_utils.hpp grp_buffer.cpp grp_buffer.hpp grp_frame_info.hpp grp_descriptors.hpp grp_descriptors.cpp)
include_directories(libs/tinyObjLoader/)
include_directories($ENV{VULKAN_SDK}/Include)
include_directories(C:\\Libraries\\glm-0.9.9.8)
find_package(Vulkan REQUIRED)
find_package(glm REQUIRED)
find_package(GLFW REQUIRED)
target_sources(GrapE PRIVATE main.cpp)

#==============================================================================
# COMPILE SHADERS
#
#

if (${CMAKE_HOST_SYSTEM_PROCESSOR} STREQUAL "AMD64")
    set(GLSL_VALIDATOR "$ENV{VULKAN_SDK}/Bin/glslangValidator.exe")
else()
    set(GLSL_VALIDATOR "$ENV{VULKAN_SDK}/Bin32/glslangValidator.exe")
endif()

file(GLOB_RECURSE GLSL_SOURCE_FILES
        "shaders/*.frag"
        "shaders/*.vert"
        )

foreach(GLSL ${GLSL_SOURCE_FILES})
    get_filename_component(FILE_NAME ${GLSL} NAME)
    set(SPIRV "${CMAKE_HOME_DIRECTORY}/shaders/${FILE_NAME}.spv")
    add_custom_command(
            OUTPUT ${SPIRV}
            COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_HOME_DIRECTORY}/shaders/"
            COMMAND ${GLSL_VALIDATOR} -V ${GLSL} -o ${SPIRV}
            DEPENDS ${GLSL})
    list(APPEND SPIRV_BINARY_FILES ${SPIRV})
endforeach(GLSL)

add_custom_target(
        Shaders
        DEPENDS ${SPIRV_BINARY_FILES}
)

add_dependencies(GrapE Shaders)

add_custom_command(TARGET GrapE POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:GrapE>/shaders/"
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_HOME_DIRECTORY}/shaders"
        "$<TARGET_FILE_DIR:GrapE>/shaders"
        )

target_link_libraries(GrapE PRIVATE Vulkan::Vulkan)
target_link_libraries(GrapE PRIVATE glm::glm)
target_link_libraries(GrapE PRIVATE GLFW::GLFW)
target_link_libraries(GrapE INTERFACE tinyobj)
target_include_directories(GrapE INTERFACE libs/tinyObjLoader/tiny_obj_loader.h)
