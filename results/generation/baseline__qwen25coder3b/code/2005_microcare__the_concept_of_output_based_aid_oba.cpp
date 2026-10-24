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

std::string getOBAProgramDescription();
std::vector<std::string> getMajorAdvantages();
std::string getPastExperiences();
std::vector<std::string> getSuccessStories();
std::string getImplementationStatus();

std::string getOBAProgramDescription() { return "Past experiences with development aid showed, that financing inputs, e.g. facilities and equipment, does not result in the necessary improvement of health outcomes. Thus as a change of paradigm, the OBA concept finances agreed outputs with predefined quality rather than pre-defined inputs by selling vouchers for STD services at subsidised prices to patients. These vouchers will be refunded to service providers in the private sector (medical doctors, qualified nurses and midwives), government hospitals, NGOs, and faith-based organisations. The major advantages of the OBA approach are, that it allows To target resources to address selected health problems, To target the provision of services to specific parts of the population and To stimulate private market initiative and competition. The approach was successfully applied in the sixties/seventies in South Korea and Taiwan. In recent years also a programme was run in Nicaragua but the OBA has not been implemented in larger scale programs."; }

std::vector<std::string> getMajorAdvantages() {
  std::string text = "..."; // The provided text
  std::string start = "The major advantages of the OBA approach are, that it allows To target resources to address selected health problems, To target the provision of services to specific parts of the population and To stimulate private market initiative and competition. The approach was successfully applied in the sixties/seventies in South Korea and Taiwan. In recent years also a programme was run in Nicaragua but the OBA has not been implemented in larger scale programs.";
  std::string end = "\n";
  size_t startIndex = text.find(start);
  size_t endIndex = text.find(end, startIndex);
  std::string advantagesText = text.substr(startIndex, endIndex - startIndex);
  std::istringstream iss(advantagesText);
  std::vector<std::string> advantages;
  std::string advantage;
  while (std::getline(iss, advantage, ',')) {
    advantages.push_back(advantage);
  }
  return advantages;
}

std::string getPastExperiences() { std::string text = "..."; std::string start = "Past experiences with development aid showed, that financing inputs, e.g. facilities and equipment, does not result in the necessary improvement of health outcomes. Thus as a change of paradigm, the OBA concept finances agreed outputs with predefined quality rather than pre-defined inputs by selling vouchers for STD services at subsidised prices to patients. These vouchers will be refunded to service providers in the private sector (medical doctors, qualified nurses and midwives), government hospitals, NGOs, and faith-based organisations. The major advantages of the OBA approach are, that it allows To target resources to address selected health problems, To target the provision of services to specific parts of the population and To stimulate private market initiative and competition. The approach was successfully applied in the sixties/seventies in South Korea and Taiwan. In recent years also a programme was run in Nicaragua but the OBA has not been implemented in larger scale programs."; std::string end = "\n"; size_t startIndex = text.find(start); size_t endIndex = text.find(end, startIndex); std::string pastExperiencesText = text.substr(startIndex, endIndex - startIndex); return pastExperiencesText; }

std::vector<std::string> getSuccessStories() { std::string text = "..."; std::string start = "..."; std::string end = "..."; size_t startIndex = text.find(start); size_t endIndex = text.find(end, startIndex); std::string successStoriesText = text.substr(startIndex, endIndex - startIndex); std::istringstream iss(successStoriesText); std::vector<std::string> successStories; std::string successStory; while (std::getline(iss, successStory, ',')) { successStories.push_back(successStory); } return successStories; }

std::string getImplementationStatus() { return "In Progress"; }

