all: exchange
.PHONY: clean all test

exchange: exchange.cpp
	@echo "[ + ] compiling"
	g++ exchange.cpp -o exchange

test: exchange
	./exchange  -585 -2

clean:
	rm -rf exchange