#pragma once
#include <vector>
#include <string>

enum class BoardPosition : char {
    TOP_LEFT,
    TOP_MIDDLE,
    TOP_RIGHT,
    MIDDLE_LEFT,
    CENTER,
    MIDDLE_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_MIDDLE,
    BOTTOM_RIGHT,
};

static const std::vector<std::string> BoardPositionString {
    "0 - Top Left",
    "1 - Top Middle",
    "2 - Top Right",
    "3 - Middle Left",
    "4 - Centre",
    "5 - Middle Right",
    "6 - Bottom Left",
    "7 - Bottom Middle",
    "8 - Bottom Right"
};
