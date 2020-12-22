INC=include
SRC=src
BIN=bin

output: $(SRC)/main.cpp
	# if there are any changes to the above file(s), recompile and execute:
	g++ -I$(INC) $(SRC)/main.cpp -o $(BIN)/main && ./$(BIN)/main
