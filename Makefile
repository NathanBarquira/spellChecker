all: main testCases

main: main.cpp
	g++ main.cpp -o main
testCases: testCases.cpp
	g++ linkedList.cpp testCases.cpp -o testCases