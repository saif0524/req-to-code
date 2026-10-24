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

void createHelpLink(QWidget* widget);
void showHelpWindow(QWidget* parent);
void populateHelpWindow(QWidget* window);
void connectHelpButton(QWidget* widget, QWidget* helpWindow);
void handleHelpButtonPress(QWidget* widget);

void createHelpLink(QWidget* widget) {
  QPushButton* helpButton = new QPushButton(widget);
  helpButton->setText("Help");
  helpButton->setStyleSheet("QPushButton { background-color: lightblue; color: black; }");
  helpButton->move(widget->width() - helpButton->width() - 10, 10);
  connect(helpButton, &QPushButton::clicked, widget, &QWidget::showHelpWindow);
  return helpButton;
}

void showHelpWindow(QWidget* parent) {
  QWidget* helpWindow = new QWidget(parent);
  populateHelpWindow(helpWindow);
  helpWindow->show();
}

void populateHelpWindow(QWidget* window) {
  QTextEdit* helpText = new QTextEdit(window);
  helpText->setText("Content from user manuals");
  helpText->show();
}

void connectHelpButton(QWidget* widget, QWidget* helpWindow) {
  QPushButton* helpButton = createHelpLink(widget);
  connect(helpButton, &QPushButton::clicked, widget, &QWidget::showHelpWindow);
}

void handleHelpButtonPress(QWidget* widget) { showHelpWindow(widget); }

