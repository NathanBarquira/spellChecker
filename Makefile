CXXFLAGS=-ggdb -std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant

all: main testCases

main: main.cpp
	g++ $(CXXFLAGS) hashFunctions.cpp loadFileFunctions.cpp helperFunctions.cpp linkedList.cpp hashSet.cpp main.cpp -o main
testCases: testCases.cpp
	g++ $(CXXFLAGS) hashFunctions.cpp helperFunctions.cpp linkedList.cpp hashSet.cpp testCases.cpp -o testCases
clean:
	rm main testCases