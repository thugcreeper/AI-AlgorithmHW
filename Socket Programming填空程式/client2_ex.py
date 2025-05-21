from email import message
from http import client
from pydoc import cli
import socket

HOST = "127.0.0.1"
PORT = 4200

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)#ipv4 , 串流式socket
client.connect((HOST,PORT))#連結server

while True:
    message = input("send message to server(press q to quit):")
    client.sendall(message.encode())
    if message == "q":
        break
    serverMessage = str(client.recv(1024), encoding="utf-8")
    print("server's reply: "+serverMessage)
    
client.close()
print("connection close")
    
