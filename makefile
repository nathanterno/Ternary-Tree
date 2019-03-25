Project2:
	g++ -g -std=c++11 Node.cpp Tree.cpp main.cpp -o Project2

OBJECTS = Node.o Tree.o main.o
	  #(listing all of your object files here, separated by space)
HEADERS = Node.h Tree.h
	  #(listing all header files here, separated by spaces)

Project2: $(OBJECTS)
	g++ $^ -o $@

%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@

clean:
	rm -i *.o Project2
