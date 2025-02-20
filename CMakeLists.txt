# 指定最低的CMake版本
cmake_minimum_required(VERSION 2.8)

# 项目名称
project(ReactorServer)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)

# 查找源文件
aux_source_directory(src src_list)

# 包含头文件目录
include_directories(${PROJECT_SOURCE_DIR}/include)

#设置链接路径
link_directories(${PROJECT_SOURCE_DIR}/lib)

# 添加可执行文件
add_executable(Reactor ${src_list})

#设置可执行文件输出路径
set_target_properties(Reactor PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)