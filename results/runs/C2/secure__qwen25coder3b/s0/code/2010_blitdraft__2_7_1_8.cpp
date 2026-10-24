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

using boost::make_unique;

std::string generateGlossary(const std::vector<std::pair<std::string, std::string>>& terms);
std::string formatTerm(const std::string& term, const std::string& definition);
std::string generateHTMLGlossary(const std::vector<std::pair<std::string, std::string>>& terms);
std::string generatePDFGlossary(const std::vector<std::pair<std::string, std::string>>& terms);
std::string generateTextGlossary(const std::vector<std::pair<std::string, std::string>>& terms);

std::string generateGlossary(const std::vector<std::pair<std::string, std::string>>& terms) {
  if (terms.empty()) {
    return "";
  }

  std::string glossary;
  for (const auto& [term, definition] : terms) {
    glossary += formatTerm(term, definition) + "\n\n";
  }

  return glossary;
}

std::string formatTerm(const std::string& term, const std::string& definition) {
  if (term.empty() || definition.empty()) {
    return "";
  }

  return term + ": " + definition + "\n";
}

std::string generateHTMLGlossary(const std::vector<std::pair<std::string, std::string>>& terms) {
  if (terms.empty()) {
    return "";
  }

  std::ostringstream oss;
  oss << "<dl>";
  for (const auto& [term, definition] : terms) {
    if (!term.empty() && !definition.empty()) {
      oss << "<dt>" << term << "</dt>" << "<dd>" << definition << "</dd>" << std::endl;
    }
  }
  oss << "</dl>";

  return oss.str();
}

std::string generatePDFGlossary(const std::vector<std::pair<std::string, std::string>>& terms) {
  if (terms.empty()) {
    return "";
  }

  auto doc = boost::make_unique<com.itextpdf.text.Document>();
  auto writer = boost::make_unique<com.itextpdf.text.pdf.PdfWriter>(std::ofstream("glossary.pdf"));
  doc->setPageSize(com.itextpdf.text.PageSize.A4);
  doc->open();

  auto table = boost::make_unique<com.itextpdf.text.Table>(2);
  table->setWidthPercentage(100);

  for (const auto& [term, definition] : terms) {
    auto row = boost::make_unique<com.itextpdf.text.pdf.PdfPRow>();
    row->addCell(term);
    row->addCell(definition);
    table->addRow(std::move(row));
  }

  doc->add(table);
  doc->close();

  return "glossary.pdf";
}

std::string generateTextGlossary(const std::vector<std::pair<std::string, std::string>>& terms) {
  if (terms.empty()) {
    return "";
  }

  std::ostringstream oss;
  for (const auto& [term, definition] : terms) {
    oss << formatTerm(term, definition) << std::endl;
  }

  return oss.str();
}

