all: clean

clean: run
	@rm parser

run: build
	@./parser $(arg)

build:
	@gcc -o ./parser parser.cpp -lstdc++ -std=c++14 -lm



