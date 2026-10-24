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

void validate_temperature(const TemperatureData& temperature_data, const TemperatureRange& valid_temperature_range, bool& is_temperature_valid);
void process_temperature_setting(const TemperatureSettingData& temperature_setting_data, const TemperatureRange& valid_temperature_range, bool& is_temperature_setting_valid);

void validate_temperature(const TemperatureData& temperature_data, const TemperatureRange& valid_temperature_range, bool& is_temperature_valid) {
    is_temperature_valid = (temperature_data.temperature >= valid_temperature_range.lower && temperature_data.temperature <= valid_temperature_range.upper);
}

void process_temperature_setting(const TemperatureSettingData& temperature_setting_data, const TemperatureRange& valid_temperature_range, bool& is_temperature_setting_valid) {
    is_temperature_setting_valid = (temperature_setting_data.temperature_setting >= valid_temperature_range.lower && temperature_setting_data.temperature_setting <= valid_temperature_range.upper);
}

void validate_temperature(const TemperatureData& temperature_data, const TemperatureRange& valid_temperature_range, bool& is_temperature_valid) {
     is_temperature_valid = (temperature_data.temperature >= valid_temperature_range.lower && temperature_data.temperature <= valid_temperature_range.upper);
}

void process_temperature_setting(const TemperatureSettingData& temperature_setting_data, const TemperatureRange& valid_temperature_range, bool& is_temperature_setting_valid) {
     is_temperature_setting_valid = (temperature_setting_data.temperature_setting >= valid_temperature_range.lower && temperature_setting_data.temperature_setting <= valid_temperature_range.upper);
}

