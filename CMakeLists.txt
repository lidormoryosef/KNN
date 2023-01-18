cmake_minimum_required(VERSION 3.24)
project(ex_4)

set(CMAKE_CXX_STANDARD 11)

add_executable(ex_4
        server/CanberraDistance.cpp
        server/ChebyshevDistance.cpp
        server/ClassifiedArray.cpp
        server/EuclideanDistance.cpp
        server/run_main.cpp
        server/Distance.h
        server/ManhattanDistance.cpp
        server/MinkowskiDistance.cpp
        server/NameVector.cpp
        server/Tools.cpp
        server/server.cpp
        server/CanberraDistance.h command/upload_unclassified.cpp IO/DefaultIO.h IO/SocketIO.cpp global_data.cpp global_data.h global_data.h command/CLI.cpp global_data.cpp command/classify_data.cpp)
