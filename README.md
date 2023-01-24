# ex_4

First the branch to check is the main branch.

In our fourth assignment we were asked to expend our communucation so we can now work with a number of clients and offer them 6 different 
services, each client was assigned a thread that would be at his service for any of his requests.

 The services our server provides are presented in a menu, where are client needs to choose between 6 choices.
## The choices are:

  - 1. First option is to upload data, both classified and unclassified, and the server recieves it.
  
  - 2. Second option is to give the client the option to change the parameters on which his data would be sorted. He can
  choose not to change the parameters and in that case the distance and K the KNN algorithm will recieve is euclidean distance and 5.
  
  - 3. Third option is to classify the data provided by the client, using the machine learning method:KNN.
  
  - 4. Fourth option is to send the client the classification for each vector he asked us to classify( the vectors that are in the
  unclassified data) for him to print it to his screen.
  
  - 5. Fifth option is similiar to the fourth option, except that now we open a local file for the client and the results will be printed in
  that set file.
  
  ##### Notice that option 3 cant happen if option 1 didnt already occur(what data would we classified?), and option 4,5 cant occur if option 3 didnt occur(we havent       classified are data yet).
  
  ##### Notice that our program works with Unix files so before uploading the files download the program dos2unix and open a terminal in the files folder
  and write "dos2unix file" (where file is the file we want to convert).

## KNN algorithm:
In order to teach the machine about certain data type,for example a cat, we will first need to classify a lot of images "by hand"(i.e by man)
and classify them on weahther their is a cat in the image or not.

We then will upload our classified data to our algorithm ,for it to "learn" certain characters about the images containing a cat ,and the 
ones who dont.And now,if given a new image that doesnt have classification, our algorithm will classify the image based on the characters it 
"learned" from our classify data.

In our project this method classify a certain data, represented by a vector. The method compare the distances between our data vector to its
already classified vectors, and return the most popular classification among the k(an integer) vectors with the smallest distance between ours.

## Input:
##### Input for the server:
The server recieves from the command line a file of classified vectors and a port to bind to in order for the clients to connect to.

##### Input for the client:
The client recieves from the command line an ip that is an identifier that allows information to be sent between devices
and a port that matches to the server port.

After that, the client asks from the user to enter data that is seperated to a vector, a norm and a K to sort by.
Invalid input for the vector contains: vector with a different size than our classified vectors, vector that one of its arguments isnt a valid double,
empty vector and etc, the only valid options for the norm is "AUC"(Euclidean distance)/"MAN"(Manhatten distance)/"CHB"(Chebyshev distance)
/"CAN"(Canberra distance) or "MIN"(Minkowski distance) and for the K is an integer larger then zero and smaller from the number of vectors in the file.


The data need to be seperated by whitespaces, otherwise it is considered invalid input.

## Output:
The server returs the classification to the users vector to the client, and the client then prints it and asks from the user for additional data.
If the user want to end communication he sends "-1" and its connection is terminated, which allows the server to connect to another client.

For more data about KNN algorithm, we recomand to read:https://he.wikipedia.org/wiki/%D7%90%D7%9C%D7%92%D7%95%D7%A8%D7%99%D7%AA%D7%9D_%D7%A9%D7%9B%D7%9F_%D7%A7%D7%A8%D7%95%D7%91

# The flow of the program:

First, we open the server, which after its construction it waits for the client to connect to it and send data for it to classify.
After the server and a client are connected, the client asks from the user to enter the data that he want to classify, and then
the server seperates the data to a vector, a norm and a K. The server then calculate the distance based on the norm he given us to all our classified vectors,
than sort the classified vectors vectors in an ascending order, and from the K(the number the server recieved) vectors with the shortest distance(the users vector neighbors) we find the most popular classification, and the server send it as the classification of the user vector( * if the data was is valid * ).
The client recives the classification and prints it, and waits for the user to send more data.
When the client recieves "-1" it terminates the communication with the server, and the server is free to go to the next client.

( * * )The server starts with a series of checks on the validation of the arguments given by the client:

    1)If the k given is a positive integer number.
    
    2)If the vector is valid.
    
    3)If the Norm(a way to calculate distance between vectors) is valid, i.e "AUC"(Euclidean distance)/"MAN"(Manhatten distance)
    /"CHB"(Chebyshev distance)/"CAN"(Canberra distance) or "MIN"(Minkowski distance).
    
# How to compile and run:

First, clone this repository. Then follow this orders:

##### Using makefile:
       a) Open the project folder in two seperate terminals and type in 'make'(in one of them is sufficient) and start to
       follow the programs orders.
       b)Then write in the first terminal in the command line:
      ./server.out [path(the address of the classified file)] [port(a number that uniquely identify a connection endpoint to direct data to a specific service)].
       c)Then write in the second terminal in the command line:
      ./client.out [ip(the unique address of the servers network that identifies it)] [port(the port number of the server program for the client to initiate contact,
        for it to direct data to the server services)].
       d)Enter data for classification, and when your done send to the server "-1".
       e) In order to clean the exe and o files, type 'make clean' in terminal.        
