CXXFLAGS += -std=c++17
GTKFLAGS = `pkg-config gtkmm-3.0 --cflags --libs`

ex: main.o money.o
	$(CXX) $(CXXFLAGS) -o money main.o money.o $(GTKFLAGS)
	
main.o: main.cpp money.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS)
	
money.o: money.h money.cpp
	$(CXX) $(CXXFLAGS) -c money.cpp $(GTKFLAGS)
	
cleanup:
	echo "Cleaning up object files and executable!"
	rm *.o
	rm money