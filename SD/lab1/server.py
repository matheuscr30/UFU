#server.py
#!/usr/bin/python                               # This is server.py file

import socket                                   # Import socket module

s = socket.socket()          # Create a socket object
host = socket.gethostname()               # Get local machine name
port = 12352                                    # Reserve a port for your service.
s.bind((host, port))                            # Bind to the port

print('Esperando conexão.')
s.listen(5)                                     # Now wait for client connections.
while True:
   c, addr = s.accept()
   while True:
       print('Esperando mensagem.')                         # Establish connection with client.
       message = c.recv(1024).decode('utf8')

       if message == 'SAIR':
           print('Conexão encerrada.')
           break

       print('Mensagem recebida: ' + message)
       reply = input('Digite resposta: ')
       c.send(bytes(reply, encoding='utf8'))
       print('Resposta enviada.')
   c.close()                                    # Close the connection
