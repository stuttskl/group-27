###
### File: makefile
### Authors: April Castaneda, Victoria Fisher, Katie Stutts 
### Description: Makefile for Group 27 Hackathon project
###

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

LDFLAGS = -lboost_date_time

SRCS = *.cpp
EXEC = Group_27

build:
	${CXX} ${CXXFLAGS} ${SRCS} -o edit

zip:
	zip $(EXEC).zip *.cpp *.hpp *.* makefile

clean:
	rm -rf *o *.dSYM ${EXEC}
