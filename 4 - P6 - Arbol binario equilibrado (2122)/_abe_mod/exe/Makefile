########################################################
#               FICHEROS Y DIRECTORIOS                 #
########################################################

EDIR = ../exe
ODIR = ../obj
SDIR = ../src

OUTDEF = main # Nombre del fichero ejecutable.	
									   
SOURCE = $(SDIR)/main.cpp \

#INC = \
#-I$(SDIR)/DispersionFunction \
#-I$(SDIR)/ExplorationFunction \

########################################################
#                       MACROS                         #           
########################################################

FLG = -std=c++17 -std=gnu++17 -L/usr/local/lib # Flags que acmpañan a la orden de compilación
GCC = g++ -Ofast # Orden de compilación


########################################################
#                  REGLAS EXPLÍCITAS                   #           
########################################################

.PHONY: clean all fast gpp									   

defult: # Orden por defecto
	clear
	@rm -f $(EDIR)/*.elf
	@rm -f $(ODIR)/*.o *~ 
	$(GCC) -o $(EDIR)/dev.elf $(FLG) $(SOURCE)

#alumno: # Regla para compilar el alumno.
#	clear
#	@rm -f $(EDIR)/*.elf
#	@rm -f $(ODIR)/*.o *~ 
#	$(GCC) -o $(EDIR)/alumno.elf $(FLG) $(SDIR)/main-alumno.cpp

exec: 
	./dev.elf

clean: # Regla para limpiar ficheros.
	@rm -f $(EDIR)/*.elf
	@rm -f $(ODIR)/*.o *~ 

gpp: # Sin las reglas implicitas (sin usar .o)
	$(GCC) -o $(EDIR)/dev.elf $(FLG) $(SOURCE)

#fast: $(OUTDEF) # Con las reglas implicitas (usando .o)
#	clear && ./main.elf

########################################################
#                  REGLAS IMPLÍCITAS                   #           
########################################################

#OBJS = grid.object.o cell.object.o state.object.o
#OPAT = $(patsubst %,$(ODIR)/%,$(OBJS))

#$(OUTDEF): $(OPAT)
#	$(GCC) -o $(EDIR)/$@.elf $(FLG) $(SOURCE)

#$(ODIR)/cell.object.o: $(SDIR)/Cell/cell.class.hpp
#	$(GCC) -c -o $@ $< $(FLG) -I$(SDIR)/Cell

#$(ODIR)/grid.object.o: $(SDIR)/Grid/grid.class.hpp
#	$(GCC) -c -o $@ $< $(FLG) -I$(SDIR)/Cell

#$(ODIR)/state.object.o: $(SDIR)/State/state.class.hpp
#	$(GCC) -c -o $@ $< $(FLG) -I$(SDIR)/State

