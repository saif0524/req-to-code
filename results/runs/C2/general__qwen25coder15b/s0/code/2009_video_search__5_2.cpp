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

struct logging { void error(const std::string& message); };
struct alerting { void send(const std::string& message); }; struct alert { std::string reason(); };

void check_website(const std::string& url);
void update_database(const std::vector<std::string>& urls);
void log_error(const std::string& error_message);
void send_alert(const std::string& alert_message);

void check_website(const std::string& url) {
  http_client client;
  std::string content = client.get(url);
  html_parser parser(content);
  content_filter filter(parser);
  database_manager db;
  db.update_database(url, filter.is_harmful());
  logging log;
  log.error(filter.reason());
  alerting alert;
  alert.send(filter.alert_message());
}

void update_database(const std::vector<std::string>& urls) {
  for (const auto& url : urls) {
    bool is_harmful = check_website(url);
    database_manager db;
    db.update_database(url, is_harmful);
    logging log;
    log.error(is_harmful ? check_website(url).reason() : "No illegal content found");
    alerting alert;
    alert.send(is_harmful ? check_website(url).alert_message() : "No illegal content found");
  }
}

struct logging { void error(const std::string& message); };

void send_alert(const std::string& alert_message) {
  logging log;
  log.error(alert_message);
  alerting alert;
  alert.send(alert_message);
}

