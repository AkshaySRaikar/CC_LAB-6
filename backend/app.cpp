#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    while(true) {
        int new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        char response[1024];
        snprintf(response, sizeof(response),
                 "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nServed by backend: %d\n",
                 getpid());
        send(new_socket, response, strlen(response), 0);
        close(new_socket);
    }

    return 0;
}
