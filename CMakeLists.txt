cmake_minimum_required(VERSION 3.9)
project(untitled2)

set(CMAKE_CXX_STANDARD 14)

link_libraries(-lGL)

link_libraries(-lGLU)

link_libraries(-lglut)

link_libraries(-lpthread)

add_executable(untitled2 main.cpp Interface/Drawer.h Implementation/Drawer/BaseDrawer.h Interface/Point.h Implementation/Point/BasePoint1.h Implementation/Point/BasePoint2.h Implementation/Point/BasePoint3.h Interface/Plotter.h Implementation/Plotter/XYPlotter.h Interface/Line.h Interface/Color.h Implementation/Line/Line2.h Implementation/Line/Line3.h Interface/Text.h Interface/Axis.h Implementation/Axis/Axis2.h Implementation/Line/LineSeries2.h Interface/LineSeries.h Interface/Renderable.h)