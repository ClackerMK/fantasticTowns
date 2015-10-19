# Compiler
CC=g++  
# Flags
CC_FLAGS=-Wall -std=c++11 -g
# Libaries
LIB_FLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lopencv_imgproc -lopencv_core
# Source Path
SRC_PATH=./src
# Output Path
O_PATH=./bin
# Objects
OBJS=$(SRC_PATH)/GenerateHeightMapState.o \
	$(SRC_PATH)/HMMP_Volcanic.o \
	$(SRC_PATH)/HMMP_Erosion.o \
	$(SRC_PATH)/HeightMapGenerator.o \
	$(SRC_PATH)/Heightmap.o \
	$(SRC_PATH)/NodeSampleAlgs.o \
	$(SRC_PATH)/PerlinNoise.o \
	$(SRC_PATH)/SquiglyLine.o \
	$(SRC_PATH)/StateManager.o \
	$(SRC_PATH)/main.o

# Output File
OP=fantasticTowns


all: $(OP)

# Dependents
# pull in dependency info for *existing* .o files
-include $(OBJS:.o=.d)


$(OP): $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -o $(O_PATH)/$(OP) $(LIB_FLAGS)

# compile and generate dependency info;
# more complicated dependency computation, so all prereqs listed
# will also become command-less, prereq-less targets
#   sed:    strip the target (everything before colon)
#   sed:    remove any continuation backslashes
#   fmt -1: list words one per line
#   sed:    strip leading spaces
#   sed:    add trailing colons
%.o: %.cpp 
	$(CC) $(CC_FLAGS) -c $*.cpp -o $*.o
	$(CC) -MM $(CC_FLAGS) $*.cpp > $*.d
	@mv -f $*.d $*.d.tmp
	@sed -e 's|.*:|$*.o:|' < $*.d.tmp > $*.d
	@sed -e 's/.*://' -e 's/\\$$//' < $*.d.tmp | fmt -1 | \
	  sed -e 's/^ *//' -e 's/$$/:/' >> $*.d
	@rm -f $*.d.tmp

# remove compilation products
clean:
	rm -f fantasticTowns $(SRC_PATH)/*.o $(SRC_PATH)/*.d
