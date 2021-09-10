cmake_minimum_required(VERSION 3.5)

project(DBSCAN)

set(SOURCES
	DBSCAN.cpp
	Main.cpp
	Point.cpp
	DataManager.cpp
	Commander.cpp
)

add_executable(startDBSCAN ${SOURCES} ${HEADERS})

set(HEADERS
	DBSCAN.h
	Point.h
	DataManager.h
	Commander.h
)


set_target_properties(
	startDBSCAN PROPERTIES
	CXX_STANDARD 14
	CXX_STANDAED_REQUIRED ON
)