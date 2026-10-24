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

string database_url = 'sqlite:///';

string createDatabaseConnection(string host, string port);
bool handleUserLogin;
void handleDatabaseAdd(string key, string value);
void restartDatabaseConnection;

string createDatabaseConnection(string host, string port) 
    { 
        return "sqlite:///" + host + ":" + port + ";" \n}

string handleUserLogin() 
    string connection = createDatabaseConnection(host, port) 
    if (connection.empty() || connection.size() == 0) 
    return false 
    else 
    return true

string handleDatabaseAdd(string key, string value) 
    { 
        string connection = createDatabaseConnection(key, value); 
        try 
        { 
            connection->insert('key', key, value); 
            return 1; 
        } 
        catch (const sqlite3::Exception& e) 
        { 
            return 0; 
        }
    }

bool restartDatabaseConnection(string connection) {
    if (!connection.is_closed()) {
        connection->restart();
        return true;
    }
    return false;
    }

