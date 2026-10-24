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

std::string parse_service_info(const std::string& service_info);
void register_service(const std::string& service_info);
void deallocate_resource(const std::string& resource_id);
void reserve_resource(const std::string& resource_id);
void report_resource_failure(const std::string& resource_id);

std::regex service_regex(R"(\{[^\n\}\]*)\")\nstd::smatch match;\nif (std::regex_search(service_info, match, service_regex)) {\nreturn match.str(1);
}
return "Invalid service information format";

void register_service(const std::string& service_info) {
  std::string service_details = parse_service_info(service_info);

  sr_mediator.deallocate_resource(service_details);
  sr_mediator.reserve_resource(service_details);
  sr_mediator.report_resource_failure(service_details);
}

void deallocate_resource(const std::string& resource_id, sr_mediator& sr_mediator) {
sr_mediator.deallocate_resource(resource_id);
}

void reserve_resource(const std::string& resource_id, sr_mediator& sr_mediator) {
sr_mediator.reserve_resource(resource_id);
}

void report_resource_failure(const std::string& resource_id) {
  sr_mediator.report_resource_failure(resource_id);
}

