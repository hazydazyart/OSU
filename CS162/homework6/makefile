# Megan Conley
# Makefile for Assignment 6
# Type make all to compile both programs

CXX = g++
CXXFLAGS = -std=c++0x

OBJS = admin.o
OBJS2 = game.o

SRCS = administrator.cpp salariedemployee.cpp employee.cpp admin.cpp
SRCS2 = creature.cpp game.cpp

HEADER = administator.h salariedemployee.h employee.h
HEADER2 = creature.h

all: admin game

admin: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} ${HEADER} -o admin

game: ${OBJS2}
	${CXX} ${CXXFLAGS} ${OBJS2} ${HEADER2} -o game

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

${OBJS2}: ${SRCS2}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
