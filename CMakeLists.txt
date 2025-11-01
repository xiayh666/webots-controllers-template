cmake_minimum_required(VERSION 3.10.0)
project(Project VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(LIB_WEBOTS_DIR ${PROJECT_SOURCE_DIR}/libwebots)

include_directories(${LIB_WEBOTS_DIR}/include/controller/cpp)
include_directories(${LIB_WEBOTS_DIR}/include/controller/c)
include_directories(./include)

file(GLOB LIB_WEBOTS_CPP
  "${LIB_WEBOTS_DIR}/src/*.cpp"
  "${LIB_WEBOTS_DIR}/src/controller/cpp/*.cpp"
)

file(GLOB LIB_WEBOTS_SO
  "${LIB_WEBOTS_DIR}/lib/controller/*.so"
)

file(GLOB SRC 
  "./src/*.cpp"
  "./src/**/*.cpp"
)

link_libraries(${LIB_WEBOTS_SO})



add_executable(main main.cpp ${LIB_WEBOTS_CPP} ${SRC}) 

add_executable(my_controller my_controller/my_controller.cpp ${LIB_WEBOTS_CPP} ${SRC})
set_target_properties(my_controller  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/my_controller
)

add_executable(supervisor supervisor/supervisor.cpp ${LIB_WEBOTS_CPP} ${SRC})
set_target_properties(supervisor  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/supervisor
)


