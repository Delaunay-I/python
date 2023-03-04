CXX = g++
CXXFLAGS = -Wall -std=c++17 $(shell python3-config --cflags --embed) -fPIC 
LDFLAGS = $(shell python3-config --ldflags) -fPIC -lpython3.8
OBJ = embed

example: $(OBJ).o
	$(CXX) $^ -o $@ $(LDFLAGS) 

$(OBJ).o: embed.cxx
	@echo Building $@ from $^...
	$(CXX) $^ $(CXXFLAGS) -c -o $@
	@chmod +x $@

clean:
	@echo cleaning files...
	@rm -f embed.o example


