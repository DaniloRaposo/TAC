CC=g++ -std=c++11
CFLAGS= `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf

ODIR=obj

_DEPS = Game.h Music.h Sprite.h State.h SDL_include.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Game.o Music.o Sprite.o State.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


all: Game

$(ODIR)/%.o: %.cpp 
	$(CC) -c -o $@ $< $(CFLAGS)

Game: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(IDIR)/*~ Game *.o
