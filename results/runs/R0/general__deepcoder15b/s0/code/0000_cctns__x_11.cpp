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

[std::pair<std::tuple<std::shared_ptr[user]], std::string>>]

std::pair<std::tuple<std::shared_ptr[user]], std::string>> handle_user_context(std::shared_ptr[user> user, std::string action]) -> std::pair<std::tuple<std::shared_ptr[user]], std::string>>;
std::pair<std::tuple<std::shared_ptr[user]], std::string>> handle_action_context(std::string action) -> std::pair<std::tuple<std::shared_ptr[user]], std::string>>;
std::pair<std::tuple<std::shared_ptr[user]], std::string>> handle_user_action(std::shared_ptr[user> user, std::string action]) -> std::pair<std::tuple<std::shared_ptr[user]], std::string>>;
std::pair<std::tuple<std::shared_ptr[user]], std::string>> handle_user_action_context(std::shared_ptr[user> user, std::string action) -> std::pair<std::tuple<std::shared_ptr[user]], std::string>>;
std::pair<std::tuple<std::shared_ptr[user]], std::string>> handle_user_action_context(std::shared_ptr[user> user, std::string action) -> std::pair<std::tuple<std::shared_ptr[user]], std::string>>;

pair<tuple<shared_ptr[user>, string>> handle_user_context(std::shared_ptr[user> user, string action)> {
    pair<tuple<shared_ptr[user>, string>> result;
    if (action == "start") {
        result = make_pair<shared_ptr[user>, string">{user, "start"};\n} else if (action == "log") {\nresult = make_pair<tuple<shared_ptr[user>, string>>{user, "log"};\n} else if (action == "end") {
        result = make_pair<tuple<shared_ptr[user>, string>>{user, "end"};
    } else if (action == "help") {
        result = make_pair<tuple<shared_ptr[user>, string>>{user, "help"};
    }
    return result;
}
} // End of function
} // End of file

pair<tuple<shared_ptr[user>, string>> handle_action_context(std::string action) -> pair<tuple<shared_ptr[user>, string>> {
    pair<tuple<shared_ptr[user>, string>> result;
    if (action == 

pair<tuple<shared_ptr[user>, string>> handle_user_action(std::shared_ptr[user> user, std::string action) -> pair<tuple<shared_ptr[user>, string>> {
    pair<tuple<shared_ptr[user>, string>> result;
    switch (action) {
        case 

pair<tuple<shared_ptr[user>, string>> handle_user_action_context(std::shared_ptr[user> user, std::string action)) -> pair<tuple<shared_ptr[user>, string>> {
    pair<tuple<shared_ptr[user>, string>> action_result = handle_action_context(action);
    pair<tuple<shared_ptr[user>, string>> user_result = handle_user_context(user, action_result);
    return make_pair(user_result, action_result);
}

pair<tuple<shared_ptr[user>, string>> handle_user_action_context(std::shared_ptr[user> user, std::string action) -> pair<tuple<shared_ptr[user>, string>> {
    pair<tuple<shared_ptr[user>, string>> action_context = handle_action_context(action);
    pair<tuple<shared_ptr[user>, string>> user_context = handle_user_context(user, action_context);
    return user_context;
}

