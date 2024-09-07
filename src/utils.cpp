#include <sstream>

#include "utils.hpp"

std::string myget_path(std::string path) {
    std::stringstream ss;
    ss << PROJECT_DIR << "/" << path;
    return ss.str();
}