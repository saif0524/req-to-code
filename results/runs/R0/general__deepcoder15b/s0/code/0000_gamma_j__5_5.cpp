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

pair<string, string> compress_image(string image_path, int threshold);
bool validate_email(email_address);

pair<string, string> compress_image(string image_path, int threshold) {
  string image = read_image(image_path);
  int width = image.size() / width_of_image;
  int height = width / height_of_image;

  if (width > threshold || height > threshold) {
    int new_width = width / 2;
    int new_height = height / 2;
    string new_image;

    string new_image_data = read_image(new_image);
    for (int i = 0; i < new_width; i++) {
      for (int j = 0; j < new_height; j++) {
        new_image += new_image_data[i * width_of_image + j];
      }
    }

    write_image(new_image, new_image_path);
    return {new_image};
  } else {
    return {image};
  }
}

bool validate_email(map<string, string> cards, string email_address) {
  vector<string> parts;
  string current;
  for (char c : email_address) {
    if (isalpha(c)) {
      current += c;
    } else {
      if (!current.empty()) {
        parts.push_back(current);
        current.clear();
      }
      if (c == '@') {
        current.clear();
        parts.push_back(c);
      }
    }
  }
  if (!current.empty()) {
    parts.push_back(current);
  }
  return parts.size() >= 2;
  }
  

