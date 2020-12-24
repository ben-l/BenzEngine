INC=../bens-engine/include
LIB=../bens-engine/lib
BIN=bin
SRC=src
CPPFLAGS += -DBE_PLATFORM_LINUX \
			BE_BUILD_SO
output: $(SRC)/SandboxApp.cpp
	# build the .so file from bens-engine first
	g++ -I$(INC) -fPIC -shared ../bens-engine/src/Application.cpp -o $(LIB)/libtest.so
	# if there are any changes to the above file(s), recompile and execute:
	g++ -L$(LIB) -I$(INC) -Wl,-rpath=$(LIB) -ltest $(SRC)/SandboxApp.cpp -o $(BIN)/SandboxApp && ./$(BIN)/SandboxApp
