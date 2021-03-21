CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g

prelab: TreeCalc.o TreeCalcTest.o TreeNode.o
	$(CXX) $(DEBUG) TreeCalc.o TreeCalcTest.o TreeNode.o -o prelab
	@echo "DONE!"

TreeCalc.o: TreeCalc.cpp TreeCalc.h TreeNode.h

TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.h TreeNode.h

TreeNode.o: TreeNode.cpp TreeNode.h

.PHONY: clean
clean:
	-rm -f *.o prelab
