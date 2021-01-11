#BINARY--------------------------------------------------------------
APP := main

#COMPILERS
CC := g++
C  := gcc

#COMMANDS
MKDIR := mkdir -p

#DIRS
OBJ := obj
SRC := src
SUBDIRS := $(shell findgnu src -type d) 
OBJSUBDIRS := $(patsubst src%,obj%,$(SUBDIRS))


#FILES
CFILES := $(shell findgnu src/ -type f -iname *.c)
OBJFILESC := $(patsubst $(SRC)%,$(OBJ)%,$(patsubst %.c,%.o,$(CFILES)))
CPPFILES := $(shell findgnu src/ -type f -iname *.cpp)
OBJFILESCPP := $(patsubst $(SRC)%,$(OBJ)%,$(patsubst %.cpp,%.o,$(CPPFILES)))

#LIBS
INCLUDE_PATHS   := -Isrc/ -Isrc/vendor/ -Ilibs/SDL2/include/
LIBRARY_PATHS   := -Llibs/SDL2/lib/

#FLAGS
COMPILER_CFLAGS := -std=c++17 -w -Wl,-subsystem,windows
LINKER_CFLAGS   := -lmingw32 -llibSDL2main -llibSDL2

#PHONY---------------------------------------------------------------
.PHONY: info

#DEPENDENCIES--------------------------------------------------------
$(APP): $(OBJSUBDIRS) $(OBJFILESC) $(OBJFILESCPP)
	$(CC) -o $(APP) $(OBJFILESC) $(OBJFILESCPP) $(LIBRARY_PATHS) $(LINKER_CFLAGS)

$(OBJSUBDIRS): $(SUBDIRS)
	mkdir -p $(OBJSUBDIRS)

obj/%.o: src/%.C
	$(CC) -o $@ -c $^ $(INCLUDE_PATHS) $(COMPILER_CFLAGS)

obj/%.o: src/%.CPP
	$(C) -o $@ -c $^ $(INCLUDE_PATHS) $(COMPILER_CFLAGS)

clean:
	rm -f -r obj/ $(APP)

cleansrc:
	rm -f -r src/
	mkdir -p src/