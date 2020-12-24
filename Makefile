INC=bens-engine/include
SRC=bens-engine/src
BIN=bens-engine/bin
LIB=bens-engine/lib
CPPFLAGS += -DBE_PLATFORM_LINUX \
			BE_BUILD_SO
output: $(SRC)/Application.cpp
	# if there are any changes to the above file(s), recompile and execute:
	g++ -I$(INC) $(SRC)/Application.cpp -o $(BIN)/Application
	g++ -I$(INC) -fPIC -shared $(SRC)/Application.cpp -o $(LIB)/libtest.so
