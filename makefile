TernaryTree:
	g++ -g -std=c++11 Node.cpp Tree.cpp main.cpp -o TernaryTree

OBJECTS = Node.o Tree.o main.o
	  #(listing all of your object files here, separated by space)
HEADERS = Node.h Tree.h
	  #(listing all header files here, separated by spaces)

TernaryTree: $(OBJECTS)
	g++ $^ -o $@

%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@

clean:
	rm -i *.o TernaryTree
