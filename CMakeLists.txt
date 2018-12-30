cmake_minimum_required(VERSION 3.9)
project(untitled2)

set(CMAKE_CXX_STANDARD 14)

link_libraries(-lGL)

link_libraries(-lGLU)

link_libraries(-lglut)

link_libraries(-lpthread)

add_executable(untitled2 main.cpp Interface/Drawer.h Implementation/BaseDrawer.h Interface/Point.h Implementation/BasePoint1.h Implementation/BasePoint2.h Implementation/BasePoint3.h Interface/Plotter.h Implementation/XYPlotter.h Interface/Line.h Interface/Color.h)