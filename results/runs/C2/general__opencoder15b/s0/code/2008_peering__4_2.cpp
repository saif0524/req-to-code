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

enum MyEnum;
using MyUsingAlias = int;
const int MyConstant = 42;

connect(std::string server_address, int server_port);
send_message(std::string message);
receive_message(std::string& message);
close_connection();
get_server_address();

void send_message(std::string message) {
     boost::asio::io_service io_service;
     boost::asio::ip::tcp::socket socket(io_service);
     boost::asio::connect(socket, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(get_server_address()), get_server_port()));

     boost::asio::write(socket, boost::asio::buffer(message));
}

void receive_message(std::string& message) {
     boost::asio::io_service io_service;
     boost::asio::ip::tcp::socket socket(io_service);
     boost::asio::connect(socket, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(get_server_address()), get_server_port()));

     boost::asio::streambuf streambuf;
     boost::asio::read(socket, boost::asio::buffer(streambuf), boost::asio::transfer_all());

     std::istream stream(&streambuf);
     std::getline(stream, message);
}

void close_connection() {
     boost::asio::io_service io_service;
     boost::asio::ip::tcp::socket socket(io_service);
     boost::asio::connect(socket, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(get_server_address()), get_server_port()));

     std::string message = "CLOSE_CONNECTION";
     boost::asio::write(socket, boost::asio::buffer(message));
}

std::string get_server_address() {
     return server_address;
}

void send_message(std::string message) {
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::socket socket(io_service);
    boost::asio::connect(socket, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(get_server_address()), get_server_port()));

    boost::asio::write(socket, boost::asio::buffer(message));
}

std::string get_server_address() {
     return server_address;
}

void receive_message(std::string& message) {
     boost::asio::io_service io_service;
     boost::asio::ip::tcp::socket socket(io_service);
     boost::asio::connect(socket, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(get_server_address()), get_server_port()));

     boost::asio::streambuf streambuf;
     boost::asio::read(socket, boost::asio::buffer(streambuf), boost::asio::transfer_all());

     std::istream stream(&streambuf);
     std::getline(stream, message);
}

void close_connection() {
     boost::asio::io_service io_service;
     boost::asio::ip::tcp::socket socket(io_service);
     boost::asio::connect(socket, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(get_server_address()), get_server_port()));

     std::string message = "CLOSE_CONNECTION";
     boost::asio::write(socket, boost::asio::buffer(message));
}

std::string get_server_address() {
     return server_address;
}

void send_message(std::string message) {
     boost::asio::io_service io_service;
     boost::asio::ip::tcp::socket socket(io_service);
     boost::asio::connect(socket, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(get_server_address()), get_server_port()));

     boost::asio::write(socket, boost::asio::buffer(message));
}

std::string get_server_address() {
     return server_address;
}

void receive_message(std::string& message) {
     boost::asio::io_service io_service;
     boost::asio::ip::tcp::socket socket(io_service);
     boost::asio::connect(socket, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(get_server_address()), get_server_port()));

     boost::asio::streambuf streambuf;
     boost::asio::read(socket, boost::asio::buffer(streambuf), boost::asio::transfer_all());

     std::istream stream(&streambuf);
     std::getline(stream, message);
}

void close_connection() {
     boost::asio::io_service io_service;
     boost::asio::ip::tcp::socket socket(io_service);
     boost::asio::connect(socket, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(get_server_address()), get_server_port()));

     std::string message = "CLOSE_CONNECTION";
     boost::asio::write(socket, boost::asio::buffer(message));
}

std::string get_server_address() {
     return server_address;
}

void send_message(std::string message) {
     boost::asio::io_service io_service;
     boost::asio::ip::tcp::socket socket(io_service);
     boost::asio::connect(socket, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(get_server_address()), get_server_port()));

     boost::asio::write(socket, boost::asio::buffer(message));
}

void receive_message(std::string& message) {
     boost::asio::io_service io_service;
     boost::asio::ip::tcp::socket socket(io_service);
     boost::asio::connect(socket, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(get_server_address()), get_server_port()));

     boost::asio::streambuf streambuf;
     boost::asio::read(socket, boost::asio::buffer(streambuf), boost::asio::transfer_all());

     std::istream stream(&streambuf);
     std::getline(stream, message);
}

void receive_message(std::string& message) {
     boost::asio::io_service io_service;
     boost::asio::ip::tcp::socket socket(io_service);
     boost::asio::connect(socket, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(get_server_address()), get_server_port()));

     boost::asio::streambuf streambuf;
     boost::asio::read(socket, boost::asio::buffer(streambuf), boost::asio::transfer_all());

     std::istream stream(&streambuf);
     std::getline(stream, message);
}

void close_connection() {
     boost::asio::io_service io_service;
     boost::asio::ip::tcp::socket socket(io_service);
     boost::asio::connect(socket, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(get_server_address()), get_server_port()));

     std::string message = "CLOSE_CONNECTION";
     boost::asio::write(socket, boost::asio::buffer(message));
}

std::string get_server_address() {
     return server_address;
}

std::string get_server_address() {
     return server_address;
}

