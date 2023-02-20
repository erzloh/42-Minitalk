# 42-Minitalk
Minitalk is a client-server program developed as part of the curriculum for School 42. The objective of this project is to implement a simple communication protocol between a client and a server using only two signals: SIGUSR1 and SIGUSR2.
## Usage
To use Minitalk, follow these steps:

1. Clone the repository to your local machine:
``` bash
git clone https://github.com/erzloh/42-Minitalk.git
```
2. Compile the server and client programs separately:
``` bash
make server
make client
```
3. Start the server:
``` bash
./server
```
4. Start the client and specify the server's process id:
``` bash
./client [process id] [message]
```
5. The server will receive the message and display it in its terminal.
