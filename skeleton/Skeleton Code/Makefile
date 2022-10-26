all: test01.exe test02.exe test03.exe test04.exe test05.exe test06.exe test07.exe test08.exe test09.exe test10.exe test11.exe test12.exe test13.exe test14.exe test15.exe test16.exe test17.exe test18.exe test19.exe test20.exe test21.exe


test%.exe: main%.o Library.o Book.o LibraryItem.o
	g++ -std=c++11 -o $@ $^


#Book.o: LibraryItem.o Book.cpp
#	g++ -std=c++11 -c $< -o $@
#
#LibraryItem.o: LibraryItem.cpp
#	g++ -std=c++11 -c $< -o $@

%.o: %.cpp
	g++ -std=c++11 -c $< -o $@

clean:
	rm *.o *.exe
# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe

