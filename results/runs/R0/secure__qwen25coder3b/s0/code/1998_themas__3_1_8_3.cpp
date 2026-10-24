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

std::string identifyEventType(const std::string& eventDescription);
std::string formatEventMessage(const std::string& eventType, const std::string& eventDescription, const std::string& currentTime);
void recordEvent(const std::string& eventMessage);
std::shared_ptr<DatabaseConnection> getDatabaseConnection();
void closeDatabaseConnection(const std::shared_ptr<DatabaseConnection>& connection);

std::string identifyEventType(const std::string& eventDescription) {
  if (eventDescription.empty()) {
    return "Unknown Event";
  }

  switch (eventDescription) {
    case "Power Failure":
      return "PowerFailure";
    case "Temperature Alert":
      return "TemperatureAlert";
    case "System Overload":
      return "SystemOverload";
    default:
      return "Unknown Event";
  }
}

std::string formatEventMessage(const std::string& eventType, const std::string& eventDescription, const std::string& currentTime) {
  std::string formattedMessage;
  formattedMessage += "Event Type: " + eventType + "\n";
  formattedMessage += "Event Description: " + eventDescription + "\n";
  formattedMessage += "Current Time: " + currentTime + "\n";
  return formattedMessage;
}

void recordEvent(const std::string& eventMessage) {
  auto connection = getDatabaseConnection();
  if (connection) {
    std::string formattedMessage = formatEventMessage(identifyEventType(eventMessage), eventMessage, getCurrentTime());
    connection->executeQuery("INSERT INTO Events (EventDescription, EventTime) VALUES (?, ?)", eventMessage, getCurrentTime());
    closeDatabaseConnection(connection);
  }
}

std::shared_ptr<DatabaseConnection> getDatabaseConnection() {
  static std::shared_ptr<DatabaseConnection> connection;
  if (!connection) {
    connection = std::make_shared<DatabaseConnection>();
  }
  return connection;
}

void closeDatabaseConnection(const std::shared_ptr<DatabaseConnection>& connection) {
  static std::shared_ptr<DatabaseConnection> connection;
  if (connection) {
    connection->close();
    connection.reset();
  }
}

