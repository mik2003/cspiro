# Compiler
CC := gcc

# Directories
SRCDIR := src
INCDIR := inc
BUILDDIR := build
BINDIR := bin
LIBDIR := lib

# Targets
TARGET := $(BINDIR)/cspiro.exe

# Source files
SRCEXT := c
SOURCES := $(wildcard $(SRCDIR)/*.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

# Flags
CFLAGS := -Wall -I$(INCDIR) -s

# Libraries
LIBS := -lm

$(TARGET): $(OBJECTS)
	@if not exist $(BINDIR) mkdir $(BINDIR)
	@echo Linking...
	@echo $(CC) $^ -o $(TARGET) $(LIBS) & $(CC) $^ -o $(TARGET) $(LIBS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@if not exist $(BUILDDIR) mkdir $(BUILDDIR)
	@echo CC $<
	@echo $(CC) $(CFLAGS) -c -o $@ $< & $(CC) $(CFLAGS) -c -o $@ $<

clean:
	@echo Cleaning...
	@del /Q $(BUILDDIR)\*.o
	@if exist $(BINDIR) rmdir /Q $(BINDIR)

.PHONY: clean
