run:
	g++ -std=c++11 client/client.cpp -o client.out
	g++ -std=c++11 server/*.cpp IO/*.cpp command/*.cpp -o server.out
clean:
	rm -rf *.out
