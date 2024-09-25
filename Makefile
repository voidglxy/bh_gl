SRCS := $(shell find ./src/ -name '*.c')

OBJS := $(SRCS:%=./bin/%.o)


all: $(OBJS) ./bin/glad.o
	gcc -o ./bin/main $^ -lm -lglfw -lGL -lX11 -lpthread -lXrandr -ldl

./bin/%.c.o: %.c
	mkdir -p $(dir $@)
	gcc -c -o $@ $< -lm -lglfw -lGL -lX11 -lpthread -lXrandr -ldl




#all: ./bin/main.o ./bin/glad.o ./bin/loadShader.o ./bin/loadObj.o
#	gcc -Wall -o ./bin/main ./bin/main.o ./bin/glad.o ./bin/loadShader.o ./bin/loadObj.o -lm -lglfw -lGL -lX11 -lpthread -lXrandr -ldl

#./bin/loadObj.o: ./src/utils/loadObj/loadObj.c
#	gcc -I ./src/utils/loadShader ./src/utils/loadObj/loadObj.c -c -o ./bin/loadObj.o

#./bin/main.o: ./src/main.c
#	gcc -lm -lcglm -I ./lib/glad -o ./bin/main.o -c ./src/main.c

./bin/glad.o: ./lib/glad/src/glad.c
	gcc -I ./lib/glad -o ./bin/glad.o -c ./lib/glad/src/glad.c -lglut -lGLEW -lglfw -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursorc

#./bin/loadShader.o: ./src/utils/loadShader/loadShader.c
#	gcc -I ./src/utils/loadShader ./src/utils/loadShader/loadShader.c -c -o ./bin/loadShader.o

clean:
	rm -rf bin/*
