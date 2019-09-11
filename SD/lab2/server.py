#server.py
#!/usr/bin/python                               # This is server.py file

import socket                                   # Import socket module

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
host = socket.gethostname()               # Get local machine name
port = 12352                                    # Reserve a port for your service.
s.bind((host, port))                            # Bind to the port

while True:
    print('Esperando mensagem.')
    data, address = s.recvfrom(4096)

    print('received {} bytes from {}'.format(
        len(data), address))
    print(data)

    if data:
        sent = s.sendto(data, address)
        print('sent {} bytes back to {}'.format(sent, address))
