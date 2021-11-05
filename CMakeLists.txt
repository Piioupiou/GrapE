cmake_minimum_required(VERSION 3.20)
project(GrapE)
find_program(GLSLC glslc)
#set(shader_path ${CMAKE_HOME_DIRECTORY}/shaders/)
#file(GLOB shaders RELATIVE ${CMAKE_SOURCE_DIR} "${shader_path}*.vert" "${shader_path}*.frag")
#file(GLOB shaders_compiled RELATIVE ${CMAKE_SOURCE_DIR} "${shader_path}*.spv")

#find_package(Vulkan REQUIRED COMPONENTS glslc)
#find_program(glslc_executable NAMES glslc HINTS Vulkan::glslc)

#message(STATUS "COMPILE SHADERS")
#foreach(shader ${shaders})
#    set(input_glsl "${CMAKE_HOME_DIRECTORY}/${shader}")
#    set(output_spv "${input_glsl}.spv")
#    add_custom_command(OUTPUT ${output_spv}
#            COMMAND glslc -V ${input_glsl} -o ${output_spv}
#
#            DEPENDS ${output_spv}
#            COMMENT "Rebuilding ${output_spv}" )
#    list(APPEND spv_files ${output_spv})
#    message(STATUS "Generating build commands for ${output_spv}")
#endforeach(shader)
#
#message(STATUS "COMPILE SHADERS ENDED")
#add_custom_target(
#        Shaders
#        DEPENDS ${spv_files}
#)




#==============================================================================
# COMPILE SHADERS
#
#
#set(SHADER_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/shaders)
#set(SHADER_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/shaders)
#
#file(GLOB SHADERS
#        ${SHADER_SOURCE_DIR}/*.vert
#        ${SHADER_SOURCE_DIR}/*.frag
#        ${SHADER_SOURCE_DIR}/*.comp
#        ${SHADER_SOURCE_DIR}/*.geom
#        ${SHADER_SOURCE_DIR}/*.tesc
#        ${SHADER_SOURCE_DIR}/*.tese
#        ${SHADER_SOURCE_DIR}/*.mesh
#        ${SHADER_SOURCE_DIR}/*.task
#        ${SHADER_SOURCE_DIR}/*.rgen
#        ${SHADER_SOURCE_DIR}/*.rchit
#        ${SHADER_SOURCE_DIR}/*.rmiss)
#
#add_custom_command(
#        COMMAND
#        ${CMAKE_COMMAND} -E make_directory ${SHADER_BINARY_DIR}
#        OUTPUT ${SHADER_BINARY_DIR}
#        COMMENT "Creating ${SHADER_BINARY_DIR}"
#)
#
#foreach(source IN LISTS SHADERS)
#    get_filename_component(FILENAME ${source} NAME)
#    add_custom_command(
#            COMMAND
#            ${glslc_executable}
#                  -MD -MF ${SHADER_BINARY_DIR}/${FILENAME}.d
#            -o ${SHADER_BINARY_DIR}/${FILENAME}.spv
#            ${source}
#            OUTPUT ${SHADER_BINARY_DIR}/${FILENAME}.spv
#            DEPENDS ${source} ${SHADER_BINARY_DIR}
#            COMMENT "Compiling ${FILENAME}"
#    )
#    list(APPEND SPV_SHADERS ${SHADER_BINARY_DIR}/${FILENAME}.spv)
#endforeach()
#
#add_custom_target(shaders ALL DEPENDS ${SPV_SHADERS})

macro(print_all_variables)
    message(SEND_ERROR "print_all_variables------------------------------------------{")
    get_cmake_property(_variableNames VARIABLES)
    foreach (_variableName ${_variableNames})
        message(STATUS "${_variableName}=${${_variableName}}")
    endforeach()
    message(STATUS "print_all_variables------------------------------------------}")
endmacro()

#print_all_variables()
#find_program(GLSLC glslc)
#set(shader_path ${CMAKE_HOME_DIRECTORY}\\..\\shaders\\)
#file(GLOB shaders RELATIVE ${CMAKE_SOURCE_DIR} "${shader_path}*.vert" "${shader_path}*.frag")
#foreach(shader ${shaders})
#    set(input_glsl "${CMAKE_HOME_DIRECTORY}/${shader}")
#    set(output_spv "${input_glsl}.spv")
#    execute_process(COMMAND "glslc" "${input_glsl}" "-o" "${output_spv}")
#endforeach()


set(CMAKE_CXX_STANDARD 17)
set(GLFW_LIBRARY C:\\Libraries\\glfw-3.3.4.bin.WIN64\\lib-vc2019\\glfw3.lib)
set(GLFW_INCLUDE_DIR C:\\Libraries\\glfw-3.3.4.bin.WIN64\\include)
set(glm_DIR C:\\Libraries\\glm-0.9.9.8\\cmake\\glm)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

add_executable(GrapE main.cpp grp_window.hpp grp_window.cpp App.cpp App.hpp grp_pipeline.hpp grp_pipeline.cpp grp_device.hpp grp_device.cpp grp_swap_chain.cpp grp_swap_chain.hpp grp_model.cpp grp_model.hpp)
include_directories($ENV{VULKAN_SDK}/Include)
include_directories(C:\\Libraries\\glm-0.9.9.8)
find_package(Vulkan REQUIRED)
find_package(glm REQUIRED)
find_package(GLFW REQUIRED)
target_sources(GrapE PRIVATE main.cpp)


#add_dependencies(GrapE Shaders)
#
#add_custom_command(TARGET GrapE POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:GrapE>/shaders/"
#        COMMAND ${CMAKE_COMMAND} -E copy_directory
#        "${PROJECT_BINARY_DIR}/shaders"
#        "$<TARGET_FILE_DIR:GrapE>/shaders"
#        )

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