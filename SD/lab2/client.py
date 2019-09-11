#client.py
#!/usr/bin/python                               # This is client.py file

import socket                                   # Import socket module
import sys

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host = socket.gethostname()                # Get local machine name
port = 12352                                    # Reserve a port for your service.


while True:
    message = input('Digite mensagem: ')

    if message == 'SAIR':
        break

    try:
        print('sending {!r}'.format(message))
        sent = s.sendto(bytes(message, encoding='utf8'), (host, port))

        # Receive response
        print('waiting to receive')
        data, server = s.recvfrom(4096)
        print('received {!r}'.format(data))
    except:
        break

s.close()
