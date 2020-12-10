CXX=g++ -g

all: evaluation input0 input00 input01 input1 input2 input3 input4 input5 input6 input7 input8

evaluation: evaluation.cpp generateRPN.o
	$(CXX) evaluation.cpp generateRPN.o -o evaluation

clean: 
	rm -f evaluation
