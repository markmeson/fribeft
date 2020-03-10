all:
	g++ -o freft main.cpp eft.cpp mainframe.cpp eftpanel.cpp `wx-config --cxxflags` `wx-config --libs`

install:
	cp -v freft /usr/sbin
