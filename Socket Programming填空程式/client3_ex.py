import encodings
from http import client, server
import socket

HOST = "127.0.0.1"
PORT = 4200

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)#ipv4 , 串流式socket
client.connect((HOST,PORT))

message = input("(Press q to exit)Welcome to 1A2B game! , make your guess: ")
while True:
    client.sendall(message.encode())
    if message == "q":
        break #What command can end the program loop?
    serverMessage = str(client.recv(1024), encoding="utf-8")
    message = input(serverMessage)
client.close()