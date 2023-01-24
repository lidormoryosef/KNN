run:
	g++ -std=c++11 client/client.cpp IO/*.cpp -o client.out -pthread
	g++ -std=c++11 server/*.cpp IO/*.cpp command/*.cpp -o server.out -pthread
clean:
	rm -rf *.out
