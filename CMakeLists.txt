cmake_minimum_required(VERSION 3.5.2)
SET(CMAKE_CXX_COMPILER "/usr/bin/g++-13")
project(MyIndex)
set(CMAKE_CXX_FLAGS "-O3") 
# set(CMAKE_CXX_FLAGS "-g -O0")
set(CMAKE_CXX_STANDARD 20)

include_directories(
  ${catkin_INCLUDE_DIRS}
  "./include"
)
link_directories(
  ${catkin_LIB_DIRS}
)
AUX_SOURCE_DIRECTORY ("src" src)

set(libs "-lpthread -lm -ldl -lpthread  -libverbs -lnuma")


# 获取所有子目录
file(GLOB subdirs RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *)

# 遍历每个子目录，如果它包含 .cc 文件，则创建一个对应的可执行文件
foreach(subdir ${subdirs})
    # 检查当前路径是否是一个目录
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${subdir})
        # 获取当前目录下的所有 .cc 文件路径
        file(GLOB subdir_sources ${CMAKE_CURRENT_SOURCE_DIR}/${subdir}/*.cc)
        # 如果存在 .cc 文件，则创建对应的可执行文件
        if(subdir_sources)
            # 添加 add_executable 命令，可执行文件的名称为当前目录名
            add_executable(${subdir} ${subdir_sources} ${src})
            target_link_libraries(${subdir} PUBLIC ${libs})
        endif()
    endif()
endforeach()
