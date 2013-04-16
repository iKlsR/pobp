EXEC = grid
OBJS = src/obp.o

CC = g++

CFLAGS  = -W -Wall
LIBS    = -lSOIL -lglew32 -lglfw -lopengl32
LDFLAGS =

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)

clean:
	rm -f $(EXEC) $(OBJS) *~