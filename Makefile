CC=g++
CROSS_COMPILE?=
COMPILER=$(CROSS_COMPILE)$(CC)
CFLAGS=-I./include -I. -Wall -O3 -g
LFLAGS=
MAKE_TEST=test
MAKE_LIB=lib
SRC_DIR=src/
OUT_LIB=lib/
LIBFLAGS= -shared -Wl,--out-implib=$(OUT_LIB)libPriorityQueue.a -Wl,--output-def=$(OUT_LIB)PriorityQueue.def
OUT_OBJ=obj/
OUT_BIN=bin/

$(MAKE_LIB): library.o
	$(shell mkdir lib)
	$(COMPILER) $(LFLAGS) $(LIBFLAGS) $(OUT_OBJ)library.o  -o $(OUT_LIB)PriorityQueue.dll

$(MAKE_TEST): main.o PriorityQueueInstances.o
	$(shell mkdir bin)
	$(COMPILER) $(LFLAGS) $(OUT_OBJ)main.o $(OUT_OBJ)PriorityQueueInstances.o -o $(OUT_BIN)$(MAKE_TEST)

All: $(MAKE_LIB) $(MAKE_TEST)

library.o:
	$(shell mkdir obj)
	$(COMPILER) $(CFLAGS) $(SRC_DIR)library.cpp -c -o $(OUT_OBJ)library.o
	
PriorityQueueInstances.o:
	$(shell mkdir obj)
	$(COMPILER) $(CFLAGS) $(SRC_DIR)PriorityQueueInstances.cpp -c -o $(OUT_OBJ)PriorityQueueInstances.o
	
main.o: PriorityQueueInstances.o
	$(shell mkdir obj)
	$(COMPILER) $(CFLAGS) -c $(SRC_DIR)main.cpp -o $(OUT_OBJ)main.o
