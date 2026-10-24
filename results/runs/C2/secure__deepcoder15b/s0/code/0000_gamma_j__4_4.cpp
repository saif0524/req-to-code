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

{\n#include <string>\n#include <vector>\n#include <utility>\n#include <sstream>\n#include <algorithm>\n#include <email>\n\nusing namespace std;\n\nstruct Message {
  string text;
  vector<string> messages;
}\n

std::pair<std::string, std::vector<std::string>> send_email_confirmation(int customer_id, int tracking_number, std::string email_address, std::string subject);
std::pair<std::string, std::vector<std::string>> send_email_to_system_admin(int system_admin_id, std::pair<int, std::string>> query_data);

pair<string, vector<string>> send_email_confirmation(int customer_id, int tracking_number, string email_address, string subject) {
message m;
message::set_string(text);
message::set_header(subject);
message::append_to(text);
message::finish(m);
return {m.text(), vector<string>{m.messages}};
return make_pair(m.text(), vector<string>{m.messages});
}

pair<string, vector<string>> send_email_to_system_admin(int system_admin_id, std::pair<int, std::string>> query_data {
  auto msg = email::message();
  msg.setSubject(

