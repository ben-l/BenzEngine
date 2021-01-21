INC += -Ibens-engine/include \
	   -Ibens-engine/vendor/spdlog/include \
	   -Ibens-engine/vendor/glfw/include
SRC=bens-engine/src
BIN=bens-engine/bin
LIB=bens-engine/lib
CPPFLAGS += -DBE_PLATFORM_LINUX \
			BE_BUILD_SO
output: $(SRC)/Application.cpp
	# if there are any changes to the above file(s), recompile and execute:
	g++ -L$(LIB) $(INC) $(SRC)/*.cpp -o $(BIN)/Application
	# g++ $(INC) -fPIC -shared $(SRC)/Application.cpp -o $(LIB)/libtest.so
