# Megan Conley
# 1/26/2014
# Makefile for Lab1

CXX = g++
CXXFLAGS = -std=c++0x

OBJS = lab1_func.o conleyme_lab1.o

SRCS = lab1_func.cpp conleyme_lab1.cpp

HEADERS = lab1_header.h

conleyme_lab1: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} ${HEADERS} -o lab1

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

