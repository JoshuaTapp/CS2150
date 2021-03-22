CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall  # Enable all warnings and Optimize
DEBUG=-g
OFILES=BSTPathTest.o BinaryNode.o BinarySearchTree.o

a.out: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES) -o a.out

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h
BinaryNode.o: BinaryNode.cpp BinaryNode.h
BinarySearchTree.o: BinarySearchTree.cpp BinaryNode.h BinarySearchTree.h

.PHONY: clean
clean:
	-rm -f *.o a.out