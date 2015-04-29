# Megan Conley
# Makefile for assignment 8

CXX = g++
CXXFLAGS = -std=c++0x

OBJS = template1.o
OBJS2 = template2.o
OBJS3 = template3.o

SRCS = template1.cpp
SRCS2 = template2.cpp
SRCS3 = template3.cpp

PROGS = template1 template2 template3

all: ${PROGS}

template1: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o template1

template2: ${OBJS2}
	${CXX} ${CXXFLAGS} ${OBJS2} -o template2

template3: ${OBJS3}
	${CXX} ${CXXFLAGS} ${OBJS3} -o template3

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

${OBJS2}: ${SRCS2}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

${OBJS3}: ${SRCS3}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
