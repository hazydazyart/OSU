# Megan Conley
# Assignment 5 Makefile
# Enter 'make all' to compile all programs

CXX = g++
CXXFLAGS = -std=c++0x

OBJS = list.o
OBJS2 = extract.o
OBJS3 = median.o

SRCS = list.cpp
SRCS2 = extract.cpp
SRCS3 = median.cpp

PROGS = list extract median

all: ${PROGS}

list: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o list

extract: ${OBJS2}
	${CXX} ${CXXFLAGS} ${OBJS2} -o extract

median: ${OBJS3}
	${CXX} ${CXXFLAGS} ${OBJS3} -o median

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

${OBJS2}: ${SRCS2}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

${OBJS3}: ${SRCS3}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
