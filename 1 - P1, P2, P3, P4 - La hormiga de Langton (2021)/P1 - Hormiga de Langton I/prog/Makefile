# Variables.
HDIR = ../include
SDIR = ../src
ODIR = ../tmp
PROG = ../prog

# Macros
CFLAGS = -std=c++11 -std=gnu++11 -I$(HDIR) -L/usr/local/lib # Flags para el compilador.
CC     = g++ -Ofast # Definición del compilador.

#_OBJ = hormiga.o mundo.o
#OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

OUTPUT = main # Nombre del fichero ejecutable.
SRC    = $(SDIR)/main.cpp  $(SDIR)/mundo.cpp  $(SDIR)/hormiga.cpp  # Definición de ficheros fuente.

# Orden por defecto
all: clean $(OUTPUT)

# Regla de compilación.
$(OUTPUT):
	clear && $(CC) -o $(PROG)/$@.elf $(CFLAGS) $(SRC)

# Regla para limpiar ficheros.
.PHONY: clean
clean:
	@rm -f $(PROG)/*.elf
	@rm -f $(ODIR)/*.o *~ 