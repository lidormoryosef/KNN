# MultiClassifiedServer

First the branch to check is the main branch.

In our fourth assignment we were asked to expend our communucation so we can now work with a number of clients, using parallelism, and offer them 6 different 
services, each client was assigned a thread that would be at his service for any of his requests.

 The services our server provides are presented in a menu, where are client needs to choose between 6 choices.We implemented our project
 with the design pattern Command.
 
## The choices are:

  - 1. First option is to upload data, both classified and unclassified, and the server recieves it.In order to pick the first option we would write 1.
  
  - 2. Second option is to give the client the option to change the parameters on which his data would be sorted. He can
  choose not to change the parameters and in that case the distance and K the KNN algorithm will recieve is euclidean distance and 5.
  In order to pick the second option we would write 2.
  
  - 3. Third option is to classify the data provided by the client, using the machine learning method:KNN.In order to pick the third option we would write 3.
  
  - 4. Fourth option is to send the client the classification for each vector he asked us to classify( the vectors that are in the
  unclassified data) for him to print it to his screen.In order to pick the fourth option we would write 4.
  
  - 5. Fifth option is similiar to the fourth option, except that now we open a local file for the client and the results will be printed in
  that set file.In order to pick the sixth option we would write 5.
  
  -6. Sixth option is for the client to finish communication with the server. In order to pick the sixth option we would write 8.
  
  ##### Notice that option 3 cant happen if option 1 didnt already occur(what data would we classified?), and option 4,5 cant occur if option 3 didnt occur(we havent       classified are data yet).
  
  ##### Notice that our program works with Unix files so before uploading the files download the program dos2unix and open a terminal in the files folder and write "dos2unix file" (where file is the file we want to convert).

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
The server recieves from the command line a port to bind to in order for the clients to connect to.

##### Input for the clients:
The client recieves from the command line an ip that is an identifier that allows information to be sent between devices
and a port that matches to the server port.

After that, the client presents to the user the menu and asks him to pick one of the six options. Any other choice would return the user to the menu.

For more data about KNN algorithm, we recomand to read:https://he.wikipedia.org/wiki/%D7%90%D7%9C%D7%92%D7%95%D7%A8%D7%99%D7%AA%D7%9D_%D7%A9%D7%9B%D7%9F_%D7%A7%D7%A8%D7%95%D7%91

# The flow of the program:

First, we open the server, which after its construction it waits for a client to connect to it and choose an option from the menu.
The client with start by choosing the first or second option(those are the options that doesnt depend on other options).
If he chose the first option,the server would ask the client to first upload a file(by path) of classified data and after that the user will send a path
to a file of unclassified data.If he chose the second option the user will have the opportunity to change the K and the Norm on which
the KNN sorts by. After that the client would press 3 and the vectors from the unclassified data would get their classification.
After that the user can choose option 4 and the results would be displayed on his screen, or press five and the results would be printed
into a file in the users local path. The client can end communication by pressing 8 or continue using the server.

    
# How to compile and run:

First, clone this repository. Then follow this orders:

##### Using makefile:
       a) Open the project folder in the terminal and type in 'make'and start to
       follow the programs orders.
       b)Then write in the terminal in the command line:
      ./server.out [port(a number that uniquely identify a connection endpoint to direct data to a specific service)].
       c)For each client you want to run repeat faze (a) then write in the second terminal in the command line:
      ./client.out [ip(the unique address of the servers network that identifies it)] [port(the port number of the server program for the client to initiate contact,
        for it to direct data to the server services)].
       d)After that follow the menus orders, and when you want to end communication press 8.
       e) In order to clean the exe and o files, type 'make clean' in terminal.        
