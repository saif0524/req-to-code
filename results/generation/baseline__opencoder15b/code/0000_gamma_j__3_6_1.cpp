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

createPlugin(std::string pluginName, std::string pluginDescription, std::string pluginVersion);
addCustomField(std::string pluginName, std::string fieldName, std::string fieldType);
removeCustomField(std::string pluginName, std::string fieldName);
updateCustomField(std::string pluginName, std::string fieldName, std::string newFieldType);
getCustomFieldInfo(std::string pluginName, std::string fieldName);

json createPlugin(std::string pluginName, std::string pluginDescription, std::string pluginVersion) {
  // Implementation goes here
}

json addCustomField(std::string pluginName, std::string fieldName, std::string fieldType) {
  // Implementation goes here
}

json removeCustomField(std::string pluginName, std::string fieldName) {
   // Implementation goes here
}

json updateCustomField(std::string pluginName, std::string fieldName, std::string newFieldType) {
    // Retrieve the current type of the custom field
    std::string currentFieldType = getCustomFieldType(pluginName, fieldName);

    // Update the custom field with the new type
    setCustomFieldType(pluginName, fieldName, newFieldType);

    // Return the updated information
    return json{{"fieldName": fieldName, "fieldType": newFieldType}};
}

json getCustomFieldInfo(std::string pluginName, std::string fieldName) {
    // Retrieve the current type of the custom field
    std::string currentFieldType = getCustomFieldType(pluginName, fieldName);

    // Return the information about the custom field
    return json{{"fieldName": fieldName, "fieldType": currentFieldType}};
}

