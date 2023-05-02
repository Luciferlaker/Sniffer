sniffer:main.o sniffer.o  rawsocket.o
	g++ main.o sniffer.o rawsocket.o -o sniffer

rawsocket.o:rawsocket.cpp
	g++ rawsocket.cpp -c -Wall -g -o rawsocket.o

sniffer.o:sniffer.cpp
	g++ sniffer.cpp -c -Wall -g -o sniffer.o

main.o:main.cpp
	g++ main.cpp -c -Wall -g -o main.o

clean:
	rm main.o sniffer.o rawsocket.o sniffer
