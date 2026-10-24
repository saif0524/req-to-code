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
      // Create a new plugin with the given name, description, and version
      std::string pluginId = createPluginId(pluginName);
      std::string pluginJson = json{{"name": pluginName, "description": pluginDescription, "version": pluginVersion}};
      // Save the plugin to the database
      savePlugin(pluginId, pluginJson);
      return json{{"pluginId": pluginId}};
}

json addCustomField(std::string pluginName, std::string fieldName, std::string fieldType) {
     // Retrieve the current fields of the plugin
     std::vector<json> currentFields = getCustomFields(pluginName);

     // Check if the plugin already has a field with the same name
     bool fieldExists = false;
     for (json field : currentFields) {
         if (field.at("name") == fieldName) {
             fieldExists = true;
             break;
         }
     }

     // If the field already exists, remove it first
     if (fieldExists) {
         removeCustomField(pluginName, fieldName);
     }

     // Add the new field with the given field type
     std::string fieldId = createFieldId(pluginName, fieldName);
     json fieldJson = json{{"name": fieldName, "type": fieldType}};
     addField(pluginName, fieldId, fieldJson);

     // Save the changes to the plugin in the database
     savePlugin(pluginName, getPluginJson(pluginName));

     // Return the updated information
     return json{{"fieldName": fieldName, "fieldType": fieldType}};
}

json updateCustomField(std::string pluginName, std::string fieldName, std::string newFieldType) {
     // Retrieve the current type of the custom field
     std::string currentFieldType = getCustomFieldType(pluginName, fieldName);

     // Update the custom field with the new type
     setCustomFieldType(pluginName, fieldName, newFieldType);

     // Return the updated information
     return json{{"fieldName": fieldName, "fieldType": newFieldType}};
}

json removeCustomField(std::string pluginName, std::string fieldName) {
     // Retrieve the current fields of the plugin
     std::vector<json> currentFields = getCustomFields(pluginName);

     // Check if the plugin already has a field with the same name
     bool fieldExists = false;
     for (json field : currentFields) {
         if (field.at("name") == fieldName) {
             fieldExists = true;
             break;
         }
     }

     // If the field already exists, remove it first
     if (fieldExists) {
         removeCustomField(pluginName, fieldName);
     }

     // Save the changes to the plugin in the database
     savePlugin(pluginName, getPluginJson(pluginName));

     // Return the updated information
     return json{{"fieldName": fieldName}};
}

json removeCustomField(std::string pluginName, std::string fieldName) {
  // Retrieve the current fields of the plugin
  std::vector<json> currentFields = getCustomFields(pluginName);

  // Check if the plugin already has a field with the same name
  bool fieldExists = false;
  for (json field : currentFields) {
    if (field.at("name") == fieldName) {
      fieldExists = true;
      break;
    }
  }

  // If the field already exists, remove it first
  if (fieldExists) {
    removeCustomField(pluginName, fieldName);
  }

  // Save the changes to the plugin in the database
  savePlugin(pluginName, getPluginJson(pluginName));

  // Return the updated information
  return json{{"fieldName": fieldName}};
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

