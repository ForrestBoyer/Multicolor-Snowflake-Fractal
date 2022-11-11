CC = g++
CFLAGS = --std=c++14 -Wall -Werror -pedantic
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework

all: snowflake lint

snowflake: snowflake.o
	$(CC) $(CFLAGS) snowflake.o -o snowflake $(LIB)

snowflake.o: snowflake.cpp
	$(CC) $(CFLAGS) -c snowflake.cpp

lint:
	cpplint --filter=-whitespace/line_length,-build/c++11 --root=. *

clean:
	rm *.o snowflake