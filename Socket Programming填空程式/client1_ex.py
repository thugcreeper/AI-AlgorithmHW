import socket

HOST = "127.0.0.1"
PORT = 4200

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)#ipv4 , 串流式socket
client.connect((HOST,PORT))#連結server

message = input("send message to server：")
client.sendall(message.encode())
serverMessage = str(client.recv(1024), encoding = "utf-8")
print("sever's reply： "+serverMessage)

client.close()
print("connection close")