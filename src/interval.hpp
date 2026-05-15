#ifndef INTERVAL_H
#define INTERVAL_H

#include "utilities.hpp"

struct interval {

    double min, max;

    interval() : min(+infinity), max(-infinity) {}
    interval(double min, double max) : min(min), max(max) {}

    double size() const;
    bool contains(double x) const;
    double clamp(double x) const;
    bool surrounds(double x) const;

    static const interval empty, universe;
};

#endif