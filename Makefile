CC=g++
CROSS_COMPILE?=
COMPILER=$(CROSS_COMPILE)$(CC)
CFLAGS=-I./include -I. -Wall 
LFLAGS=
TARGET=testqueue
SRC_DIR=src/

	
$(TARGET): main.o PriorityQueueInstances.o
	$(COMPILER) $(LFLAGS) main.o PriorityQueueInstances.o -o $(TARGET)
	
PriorityQueueInstances.o:
	$(COMPILER) $(CFLAGS) PriorityQueueInstances.cpp -c
	
main.o: PriorityQueueInstances.o
	$(COMPILER) $(CFLAGS) -c main.cpp
