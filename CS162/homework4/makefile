# Megan Conley
# Makefile for Assignment 4
# Type 'make all' to compile all programs

CXX = g++
CXXFLAGS = -std=c++0x

OBJS = prime.o 
OBJS2 = operator.o 
OBJS3 = tag.o 
OBJS4 = vector2d.o

SRCS = prime.cpp 
SRCS2 = operator.cpp 
SRCS3 = tag.cpp 
SRCS4 = vector2d.cpp

PROGS = prime operator tag vector2d

all: ${PROGS}

prime: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o prime

operator: ${OBJS2}
	${CXX} ${CXXFLAGS} ${OBJS} -o operator

tag: ${OBJS3}
	${CXX} ${CXXFLAGS} ${OBJS} -o tag

vector2d: ${OBJS4}
	${CXX} ${CXXFLAGS} ${OBJS} -o vector2d

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

${OBJS2}: ${SRCS2}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

${OBJS3}: ${SRCS3}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

${OBJS4}: ${SRCS4}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

