CC = g++
CFLAGS = -Werror -Wall -Iincludes -I/usr/include/SDL2/
LFLAGS = -lSDL2
OBJDIR = obj/
SRCDIR = src/
BINDIR = bin/
TARGET = casse_brique
SOURCES = $(wildcard $(SRCDIR)*.cpp)
OBJECTS = $(patsubst $(SRCDIR)%.cpp, $(OBJDIR)%.o, $(SOURCES))

all: $(BINDIR)$(TARGET)

$(BINDIR)$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $^ -o $@ $(LFLAGS) -lSDL2 -lSDL2_ttf

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)$(TARGET)

.PHONY: all clean
