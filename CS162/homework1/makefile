# Megan Conley
# 1/10/2014
# Makefile for assignment 1, #1
# Comments: While it seems almost pointless for a simple program like this
# that won't require a lot of editing, I can think of several programs
# from the last class that this would have been useful for. Being able
# to edit the functions in their own implementation file and compile
# just what I need to compile with a makefile would have simplified
# many assignments.

CXX = g++
CXXFLAGS = -std=c++0x

OBJS = f.o g.o main.o

SRCS = f.cpp g.cpp main.cpp

HEADERS = f.h g.h

main: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} ${HEADERS} -o main

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
