CC=g++
CFLAGS= -Wall 
OBJS = BTreeTest.o
INCDIR=./include
LIBDIR=./lib
DIRS = buf fixed var recfile index student courseregistration btindex

.PHONY: all clean

all: BTreeTest
%.o: %.cpp
	$(CC) -c -I$(INCDIR) $(CFLAGS) -o $@ $<

BTreeTest: $(OBJS)
	@for d in $(DIRS); \
	do \
		$(MAKE) -C $$d; \
	done
	$(CC) -o BTreeTest $(OBJS) -L$(LIBDIR) -lmybtree -lmybuffer -lmyfixed -lmystudent -lmycourse -lmyvar -lrecfile -lmyindex 
	export LD_LIBRARY_PATH=$(LIBDIR)

clean:
	@for d in $(DIRS); \
	do \
		$(MAKE) -C $$d clean; \
	done
	-rm -rf BTreeTest $(OBJS) *.dat *.ind
