COMP     = g++
EDL      = g++
RM       = rm
RMFLAGS  = -f
OUTPUT   = -o
CPPFLAGS = -Wall -Dmap #-DMAP
INTPATH  = # src/
INT      = $(INTPATH)Log.h $(INTPATH)Read.h $(INTPATH)GraphVizConverter.h
REAL     = $(INT:.h=.cpp)
OBJ      = $(INT:.h=.o) main.o
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

%.o : %.cpp
	$(ECHO) "compilation de <$<>"
	$(COMP) $(CPPFLAGS) $(INCPATH) -c $<

Read.o : Read.h Log.h
Log.o  : Log.h





Clean : 
	$(ECHO) "Nettoyage du repertoire..."
	$(RM) $(RMFLAGS) $(EXE) $(OBJ) core
