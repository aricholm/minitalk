# minitalk

Minitalk for 42Wolfsburg

The objective of this project was to make a client that sends text messages to a server to display using SIGUSR1 and SIGUSR2.
The client converts the string to binary using masks, then using SIGUSR1 as 1 and SIGUSR2 as 0 sends to the server which is confirming every bit with a SIGURS1 back.
The client null terminates the string and the server confirms it with a SIGUSR2.
Due to the unreliability of pause() I'm made my own solution for signal collision.
