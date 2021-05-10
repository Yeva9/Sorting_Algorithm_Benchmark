
export EXE := benchmark
export CC := g++

export SRCS := $(wildcard src/*.cpp)
export OBJS := $(patsubst src/%.cpp, obj/%.o, $(SRCS))
export DEPS := $(patsubst src/%.cpp, obj/%.dep, $(SRCS))

export LIBS	:= lib/ByArshacid.so 

bin/$(EXE) : $(OBJS) $(LIBS)
	@mkdir -p bin
	$(CC) $^ -o $@

$(LIBS) : obj/Sortings.o
	@mkdir -p lib
	$(CC) -shared $< -o $@

obj/%.o : src/%.cpp
	@mkdir -p obj
	$(CC) -fPIC -c $< -o $@

obj/%.dep : src/%.cpp
	@mkdir -p obj
	$(CC) -MM $^ -o $@

.PHONY : clean
clean :
	rm -rf $(EXE) $(OBJS) $(DEPS) obj bin lib	

-include $(DEPS)
