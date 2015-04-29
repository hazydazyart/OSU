# Megan Conley
# 1/26/2014
# Makefile to compile all 3 programs
# for assignment 3

CXX = g++
CXXFLAGS = -std=c++0x

OBJS = security.o security_f.cpp
OBJS2 = suitors.o suitors_f.cpp
OBJS3 = inventory.o

SRCS = security.cpp 
SRCS2 = suitors.cpp 
SRCS3 = inventory.cpp

HEADER = security_h.h
HEADER2 = suitors_h.h

PROGS = security suitors inventory

all: ${PROGS}

security: ${OBJS} ${HEADER}
	${CXX} ${CXXFLAGS} ${OBJS} ${HEADER} -o security

suitors: ${OBJS2} ${HEADER2}
	${CXX} ${CXXFLAGS} ${OBJS2} ${HEADER2} -o suitors

inventory: ${OBJS3}
	${CXX} ${CXXFLAGS} ${OBJS3} -o inventory


${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

${OBJS2}: ${SRCS2}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

${OBJS3}: ${SRCS3}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

