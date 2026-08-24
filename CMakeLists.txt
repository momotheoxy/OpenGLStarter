cmake_minimum_required(VERSION 3.20)
project(OpenGLStarter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glew CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

add_executable(OpenGLStarter
  src/main.cpp
  src/Libs/Mesh.cpp
  src/Libs/Shader.cpp
  src/Libs/Window.cpp
)

target_include_directories(OpenGLStarter PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Libs
)

target_link_libraries(OpenGLStarter PRIVATE
  OpenGL::GL
  glfw
  GLEW::GLEW
  glm::glm
)

if(APPLE)
  # OpenGL is deprecated by Apple but remains available (up to OpenGL 4.1).
  target_compile_definitions(OpenGLStarter PRIVATE GL_SILENCE_DEPRECATION)
endif()

# Keep shader paths the same on every OS by copying them beside the executable.
add_custom_command(TARGET OpenGLStarter POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
          ${CMAKE_CURRENT_SOURCE_DIR}/Shaders
          $<TARGET_FILE_DIR:OpenGLStarter>/Shaders
  COMMENT "Copying shaders"
)
