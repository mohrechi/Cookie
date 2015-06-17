def write_string_to_socket(connection, message):
    connection.send(message)

def read_string_from_socket(connection):
    return connection.recv(1024)

def process_client_connection(connection):
    while True:
        message = read_string_from_socket(connection)
        print "Message received = ", message
        sys.stdout.flush()
        if message == "END":
            break
        write_string_to_socket(connection, message)
