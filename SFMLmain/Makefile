CXXC=g++ -g -fsanitize=address -lsfml-graphics -lsfml-window -lsfml-system
CXXFLAGS= -std=c++14 -W -Wall -Wextra -Wfatal-errors # -Werror #-Weffc++
LDFLAGS=
EXEC=main
SRC= $(wildcard *.cpp)
OBJ=$(SRC:.cpp=.oo)

all: $(EXEC)

main: $(OBJ)
	$(CXXC) -o $@ $^ $(LDFLAGS)

%.oo: %.cpp
	$(CXXC) -o $@ -c $< $(CXXFLAGS)

.PHONY: clean


clean: 
	rm -rf *.oo $(EXEC)
