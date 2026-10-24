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

int get_currentLanguage();
void addLanguage(int newLanguage);
vector<int> get_availableLanguages();
void deleteLanguage(int language);

int get_currentLanguage() {
    return 3;
  }

vector<int> addLanguage(int newLanguage) { vector<int> temp = _availableLanguages; temp.push_back(newLanguage); _availableLanguages = temp; return temp; },
    

vector<int> get_availableLanguages() {
  return _availableLanguages;
}

vector<int> deleteLanguage(int language) { vector<int> temp = _availableLanguages; temp.erase(temp.begin() + language); _availableLanguages = temp; return _availableLanguages; }, "reasoning": [1] 确定要删除的语言编号，然后从 _availableLanguages 中删除该元素，确保列表保持正确。[2] 使用 erase 函数删除元素，避免出错。[3] 返回当前可用语言列表。

