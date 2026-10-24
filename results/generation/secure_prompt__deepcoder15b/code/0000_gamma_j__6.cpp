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

int* read_from_flash(buffer* buffer, int* pos);
int* write_to_flash(buffer* buffer, int* pos, int count);
int* read_from_db(string query, int* id);
int* write_to_db(string query, int* id, string record);
string handle_flash_error(int errorCode);

int* read_from_flash(buffer* buffer, int* pos) {
  int* data = new int[1024];
  int count = 1024;
  int i;

  if (buffer == NULL || buffer->length < count) {
    return (int*)0;
  }

  for (i = 0; i < count; i++) {
    if (pos + i >= buffer->length) {
      return (int*)0;
    }
    data[i] = *(buffer + pos + i);
    pos += 4;
  }

  return data;
}

int* write_to_flash(buffer* buffer, int* pos, int count) {
  if (buffer == NULL || buffer->length < count) {
    return (int*)0;
  }

  if (pos >= buffer->length - count) {
    return (int*)0;
  }

  int* data = new int[count];
  int current_pos = pos;

  for (int i = 0; i < count; i++) {
    if (current_pos + i >= buffer->length) {
      return (int*)0;
    }
    data[i] = *(buffer + current_pos + i);
    current_pos += 4;
  }

  return data;
}

int* read_from_db(string query, int* id) {
  vector<string> parts = split_query(query);
  string field_name = parts[0];
  string value_for_id;
  if (parts.size() > 1) {
    value_for_id = parts[1];
  } else {
    value_for_id =;
  }
  int id = *id;
  int* result = read_from_flash(buffer, id);
  return result;
}

int* write_to_db(string query, int* id, string record) {
  int* result = new int[1024];
  vector<string> parts = split_query(query);
  if (parts.size() < 2) {
    return (int*)0;
  }
  string field_name = parts[0];
  string value_for_id;
  if (parts.size() > 1) {
    value_for_id = parts[1];
  } else {
    value_for_id =;
  }
  int id = *id;
  int* data = write_to_flash(buffer, id, value_for_id, record);
  return data;
}

string handle_flash_error(int errorCode) {
  if (buffer == NULL || buffer->length < 1024) {
    return (string)

