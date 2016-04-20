OBJS =  main.o RandomCollector.o RandomCollectorClassifier.o FileCollector.o LanguageCollector.o
CPP = g++
DEBUG = -g
CPPFLAGS = -Wall -c $(DEBUG)
LNKFLAGS = -Wall $(DEBUG)

main: $(OBJS)
	$(CPP) $(LNKFLAGS) -o $@ $^

%.o: %.cpp
	$(CPP) -c $(CPPFLAGS) -o $*.o $*.cpp

clean:
	$(RM) *.o main

.PHONY: depends

depends:
	$(CPP) -M *.cpp > Makefile.depends

include Makefile.depends

