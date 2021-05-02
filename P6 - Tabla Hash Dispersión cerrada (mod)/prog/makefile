# Variables.
AUX = ../include/1-auxiliar
GEN = ../include/2-generico
ABS = ../include/3-abstracto
DER = ../include/4-derivado

SDIR = ../src
ODIR = ../tmp
PROG = ../prog

# Macros
CFLAGS = -std=c++11 -std=gnu++11 -I$(AUX) -I$(GEN) -I$(ABS) -I$(DER) -L/usr/local/lib # Flags para el compilador.
CC     = g++ -Ofast # Definición del compilador.

#_OBJ = hormiga.o mundo.o
#OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

OUTPUT = main # Nombre del fichero ejecutable.
SRC    = $(SDIR)/main_producto.cpp 

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