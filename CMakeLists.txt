# CMakeLists.txt - 构建 PlayGrid 项目
cmake_minimum_required(VERSION 3.10)
project(PlayGrid)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(PlayGrid
    main.cpp
    src/GomokuGame.cpp
    src/Board.cpp
    src/AI.cpp
    src/BossKey.cpp
)