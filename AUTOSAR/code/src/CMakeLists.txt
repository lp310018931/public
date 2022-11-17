
set (CMAKE_CXX_COMPILER "/usr/bin/g++")
add_compile_options(-std=c++11 -g)


#述生成目标的信息和源文件，并指明要链接哪些库
add_executable(DemoServer DemoServer.cpp VSomeipImpl.cpp)
add_executable(DemoClient DemoClient.cpp VSomeipImpl.cpp)

add_executable(DemoSubscribeClient DemoSubscribeClient.cpp VSomeipImpl.cpp)
add_executable(DemoSubscribeServer DemoSubscribeServer.cpp VSomeipImpl.cpp)

file (GLOB_RECURSE vsomeip_lib_files "${PROJECT_SOURCE_DIR}/lib/lib/vsomeip/*.*")
file (GLOB_RECURSE boost_lib_files "${PROJECT_SOURCE_DIR}/lib/lib/boost/*.*")

target_link_libraries(DemoServer  ${boost_lib_files})
target_link_libraries(DemoServer  ${vsomeip_lib_files})
target_link_libraries(DemoServer  -lpthread -lm)

target_link_libraries(DemoClient  ${boost_lib_files})
target_link_libraries(DemoClient  ${vsomeip_lib_files})
target_link_libraries(DemoClient  -lpthread -lm)

target_link_libraries(DemoSubscribeClient  ${boost_lib_files})
target_link_libraries(DemoSubscribeClient  ${vsomeip_lib_files})
target_link_libraries(DemoSubscribeClient  -lpthread -lm)

target_link_libraries(DemoSubscribeServer  ${boost_lib_files})
target_link_libraries(DemoSubscribeServer  ${vsomeip_lib_files})
target_link_libraries(DemoSubscribeServer  -lpthread -lm)

