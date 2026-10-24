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

void createHelpLink();
void displayHelpWindow();
void setHelpTopic(int topic);
int getHelpTopic();
void updateHelpLink();

void createHelpLink() {
   QPushButton* helpLink = new QPushButton("Help");

   connect(helpLink, SIGNAL(clicked()), this, SLOT(displayHelpWindow()));

   ui->verticalLayout->addWidget(helpLink);
}

void displayHelpWindow() {
     // Create a help window
     HelpWindow* helpWindow = new HelpWindow();

     // Display the help window
     helpWindow->show();
}

void setHelpTopic(int topic) {
     currentTopic = topic;
}

int getHelpTopic() {
     return currentTopic;
}

void updateHelpLink() {
     QPushButton* helpLink = new QPushButton("Help");
     connect(helpLink, SIGNAL(clicked()), this, SLOT(displayHelpWindow()));
     ui->verticalLayout->addWidget(helpLink);
}

void setHelpTopic(int topic) {
     currentTopic = topic;
}

int getHelpTopic() {
     return currentTopic;
}

void displayHelpWindow() {
     // Create a help window
     HelpWindow* helpWindow = new HelpWindow();

     // Display the help window
     helpWindow->show();
}

void setHelpTopic(int topic) {
     // Set the current help topic
     currentTopic = topic;
}

int getHelpTopic() {
   return currentTopic;
}

void updateHelpLink() {
  QPushButton* helpLink = new QPushButton("Help");
  connect(helpLink, SIGNAL(clicked()), this, SLOT(displayHelpWindow()));
  ui->verticalLayout->addWidget(helpLink);
}

void displayHelpWindow() {
  HelpWindow* helpWindow = new HelpWindow();
  helpWindow->show();
}

void setHelpTopic(int topic) {
  currentTopic = topic;
}

int getHelpTopic() {
  return currentTopic;
}

void setHelpTopic(int topic) {
  currentTopic = topic;
}

int getHelpTopic() {
  return currentTopic;
}

void displayHelpWindow() {
  HelpWindow* helpWindow = new HelpWindow();
  helpWindow->show();
}

