#client.py

#!/usr/bin/python                               # This is client.py file

import socket                                   # Import socket module

s = socket.socket()                             # Create a socket object
host = socket.gethostname()                # Get local machine name
port = 12346                                    # Reserve a port for your service.

s.connect((host, port))

while True:
    message = input('Digite mensagem: ')
    if message == 'SAIR':
        break
    s.send(bytes(message))

data = s.recv(1024)
print(data)
s.close()
