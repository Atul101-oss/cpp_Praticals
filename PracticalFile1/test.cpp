#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::stringstream ss;

    // Write data to the stringstream
    ss << "Hello, " << 42 << " world!";

    // Read data from the stringstream
    std::string outputString;
    ss >> outputString;

    // Display the extracted string
    std::cout << "Extracted string: " << outputString << std::endl;

    return 0;
}
