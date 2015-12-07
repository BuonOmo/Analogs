COMP     = g++
EDL      = g++
RM       = rm
RMFLAGS  = -f
OUTPUT   = -o
CPPFLAGS = -Wall -Dmap #-DMAP
INTPATH  = ../src/
INT      = Log.h Read.h GraphVizConverter.h Graph.h
INTPATH  =../src/
REAL     = $(REALPATH)$(INT:.h=.cpp)
REALPATH =../src/
OBJ      = $(OBJPATH)$(INT:.h=.o) main.o
OBJPATH  =
LIBPATH  = #-L
INCPATH  = #-I 
LIBS     = #-lm 

ECHO  = @echo
EXE   = EXE
CLEAN = Clean
#.SILENT:
.PHONY: $(CLEAN)

$(EXE) : $(OBJ)
	$(EDL) $(OUTPUT) $(EXE) $(OBJ)

%.o : $(INTPATH)%.cpp
	$(ECHO) "compilation de <$<>"
	$(COMP) $(CPPFLAGS) $(INCPATH) -c $<

Log.o  : $(INTPATH)Log.h
Read.o : $(INTPATH)Read.h $(INTPATH)Log.h
Graph.o : $(INTPATH)Graph.h $(INTPATH)Read.h $(INTPATH)Log.h






Clean : 
	$(ECHO) "Nettoyage du repertoire..."
	$(RM) $(RMFLAGS) $(EXE) $(OBJ) core
