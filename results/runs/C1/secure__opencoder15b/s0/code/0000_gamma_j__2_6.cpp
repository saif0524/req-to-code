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

installWebHelp();
deliverManuals();

void installWebHelp() {
   // Step 1: Create a directory for the web help files.
   std::string webHelpDir = "./webhelp";
   // Step 2: Create a file structure for the web help files.
   std::string indexFile = webHelpDir + "/index.html";
   // Step 3: Write the index.html file with instructions on how to use the web help.
   std::ofstream indexFileStream(indexFile);
   indexFileStream << "<html><body>Welcome to the Gamma-J Connecting Retailers web help.\\nTo get started, click on any of the links below:\\n<a href=\"users-guide.html\\">Users Guide</a>\\n\\n<a href=\"installation.html\\">Installation Instructions</a>\\n\\n</body></html>";
   // Step 4: Write the users-guide.html file with detailed instructions on how to use the Users Guide.
   std::string usersGuideFile = webHelpDir + "/users-guide.html";
   std::ofstream usersGuideFileStream(usersGuideFile);
   usersGuideFileStream << "<html><body>Welcome to the Gamma-J Connecting Retailers Users Guide.\\nTo get started, click on any of the links below:\\n<a href=\"index.html\\">Back to main page</a>\\n\\n</body></html>";
   // Step 5: Write the installation.html file with detailed instructions on how to install the web help.
   std::string installationFile = webHelpDir + "/installation.html";
   std::ofstream installationFileStream(installationFile);
   installationFileStream << "<html><body>Welcome to the Gamma-J Connecting Retailers Installation Instructions.\\nTo get started, click on any of the links below:\\n<a href=\"index.html\\">Back to main page</a>\\n\\n</body></html>";
}

void installWebHelp() {
    // Step 1: Create a directory for the web help files.
    std::string webHelpDir = "./webhelp";
    // Step 2: Create a file structure for the web help files.
    std::string indexFile = webHelpDir + "/index.html";
    // Step 3: Write the index.html file with instructions on how to use the web help.
    std::ofstream indexFileStream(indexFile);
    indexFileStream << "<html><body>Welcome to the Gamma-J Connecting Retailers web help.\nTo get started, click on any of the links below:\n\n<a href="users-guide.html">Users Guide</a>

<a href="installation.html">Installation Instructions</a>

</body></html>";\n// Step 4: Write the users-guide.html file with detailed instructions on how to use the Users Guide.\nstd::string usersGuideFile = webHelpDir + "/users-guide.html";\nstd::ofstream usersGuideFileStream(usersGuideFile);
    usersGuideFileStream << "<html><body>Welcome to the Gamma-J Connecting Retailers Users Guide.\nTo get started, click on any of the links below:\n\n<a href="index.html">Back to main page</a>

</body></html>";\n// Step 5: Write the installation.html file with detailed instructions on how to install the web help.\nstd::string installationFile = webHelpDir + "/installation.html";\nstd::ofstream installationFileStream(installationFile);
    installationFileStream << "<html><body>Welcome to the Gamma-J Connecting Retailers Installation Instructions.\nTo get started, click on any of the links below:\n\n<a href="index.html">Back to main page</a>

</body></html>";\n}

