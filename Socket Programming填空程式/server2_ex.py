import socket
import re
import random


HOST = "127.0.0.1"
PORT = 4200

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST, PORT))
server.listen(1)
conn, addr = server.accept()
print("connection start")

while True:
    messageFromClient = str(conn.recv(1024), encoding="utf-8")
    if messageFromClient =="q":
        break
    print("received from client: "+messageFromClient)
    reply = messageFromClient
    conn.sendall(reply.encode())
    
server.close()
print("connection close")    
