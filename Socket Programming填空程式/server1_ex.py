import socket
import re
import random
import time

HOST = "127.0.0.1"
PORT = 4200
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)#ipv4 , 串流式socket
server.bind((HOST, PORT))#綁定ip和port
server.listen(1)
conn, addr = server.accept()
print("connection start")

messageFromClient = str(conn.recv(1024), encoding="utf-8")
print(messageFromClient)
reply = "received!!"
conn.sendall(reply.encode())

time.sleep(3)

server.close()
print("connection close")