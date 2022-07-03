CXXFLAGS=-ggdb -std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant

all: main testCases

main: main.cpp
	g++ $(CXXFLAGS) main.cpp -o main
testCases: testCases.cpp
	g++ $(CXXFLAGS) helperFunctions.cpp linkedList.cpp testCases.cpp -o testCases
clean:
	rm main testCases