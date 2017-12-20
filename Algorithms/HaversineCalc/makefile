LOCOBJECTS = HaversineWVector.o Location.o
LOCHEADERS = Location.h
LLOBJECTS = NESW.o LinkedList.o
LLHEADERS = LinkedList.h
PA1VEC: $(LOCOBJECTS)
	g++ -o PA1VEC $^
PA1LIST: $(LLOBJECTS)
	g++ -o PA1LIST $^
%.o: %.cpp $(LOCHEADERS)
	g++ -c $< -o $@
clean:
	rm -f *.o PA1LIST PA1VEC
