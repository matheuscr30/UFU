#client.py

#!/usr/bin/python                               # This is client.py file

import socket                                   # Import socket module

s = socket.socket()                             # Create a socket object
host = socket.gethostname()                # Get local machine name
port = 12352                                    # Reserve a port for your service.

s.connect((host, port))

while True:
    message = input('Digite mensagem: ')
    s.send(bytes(message, encoding='utf8'))

    if message == 'SAIR':
        breaks

    print('Mensagem enviada.')
    print('Esperando resposta.')
    answer = s.recv(1024).decode('utf8')
    print('Resposta recebida: ' + answer)

print('Desconectando.')
s.close()
