#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <optional>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

std::string server; int port; std::string message; int connection_id;

establish_connection(std::string server, int port);
send_message(std::string message, int connection_id);
receive_message(int connection_id);
close_connection(int connection_id);

int establish_connection(std::string server, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        return -1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, server.c_str(), &serv_addr.sin_addr) <= 0) {
        return -1;
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        return -1;
    }

    return sockfd;
}

int send_message(std::string message, int connection_id) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        return -1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, server.c_str(), &serv_addr.sin_addr) <= 0) {
        return -1;
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        return -1;
    }

    // Send the message
    int message_length = message.size();
    char header[sizeof(int) + message.size()];
    memcpy(header, &message_length, sizeof(int));
    memcpy(header + sizeof(int), message.c_str(), message.size());
    send(sockfd, header, sizeof(header), 0);

    return sockfd;
}

int receive_message(int connection_id) {
    int sockfd = connection_id;
    char header[sizeof(int)];
    recv(sockfd, header, sizeof(header), 0);
    int message_length = *((int*)header);
    char* message = (char*)malloc(message_length);
    recv(sockfd, message, message_length, 0);
    return message;
}

int close_connection(int connection_id) {
    close(connection_id);
    return 0;
}

