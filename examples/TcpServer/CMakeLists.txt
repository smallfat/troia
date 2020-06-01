
add_executable(TcpServer server.cpp)
set_target_properties(TcpServer PROPERTIES COMPILE_FLAGS "-Wno-error=shadow")
target_link_libraries(TcpServer troia_net)