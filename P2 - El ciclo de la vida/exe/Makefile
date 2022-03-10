########################################################
#               FICHEROS Y DIRECTORIOS                 #
########################################################

EDIR = ../exe
ODIR = ../obj
SDIR = ../src

OUTDEF = main # Nombre del fichero ejecutable.	
									   
SOURCE = $(SDIR)/main.cpp \
$(SDIR)/State/state.defs.cpp \
$(SDIR)/Cell/cell.defs.cpp \
$(SDIR)/Grid/grid.defs.cpp \




#INC = \
-I$(SDIR)/Grid \
-I$(SDIR)/Cell \
-I$(SDIR)/State \


########################################################
#                       MACROS                         #           
########################################################

FLG = -std=c++17 -std=gnu++17 -L/usr/local/lib # Flags que acmpañan a la orden de compilación
GCC = g++ -Ofast # Orden de compilación

#OBJS = grid.object.o cell.object.o state.object.o
#OPAT = $(patsubst %,$(ODIR)/%,$(OBJS))

########################################################
#                  REGLAS EXPLÍCITAS                   #           
########################################################

.PHONY: clean all fast gpp									   

all: clean gpp # Orden por defecto

#fast: $(OUTDEF) # Con las reglas implicitas (usando .o)
#	clear && ./main.elf

gpp: # Sin las reglas implicitas (sin usar .o)
	$(GCC) -o $(EDIR)/dev.elf $(FLG) $(SOURCE)

clean: # Regla para limpiar ficheros.
	@rm -f $(EDIR)/*.elf
	@rm -f $(ODIR)/*.o *~ 

########################################################
#                  REGLAS IMPLÍCITAS                   #           
########################################################

#$(OUTDEF): $(OPAT)
#	$(GCC) -o $(EDIR)/$@.elf $(FLG) $(SOURCE)

#$(ODIR)/cell.object.o: $(SDIR)/Cell/cell.class.hpp
#	$(GCC) -c -o $@ $< $(FLG) -I$(SDIR)/Cell

#$(ODIR)/grid.object.o: $(SDIR)/Grid/grid.class.hpp
#	$(GCC) -c -o $@ $< $(FLG) -I$(SDIR)/Cell

#$(ODIR)/state.object.o: $(SDIR)/State/state.class.hpp
#	$(GCC) -c -o $@ $< $(FLG) -I$(SDIR)/State