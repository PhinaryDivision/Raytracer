#ifndef INTERVAL_HPP
#define INTERVAL_HPP

#include "utilities.hpp"

struct interval {

    double min, max;

    interval();
    interval(double min, double max);
    interval(const interval& a, const interval& b);

    double size() const;
    bool contains(double x) const;
    double clamp(double x) const;
    interval expand(double delta) const;
    bool surrounds(double x) const;

    static const interval empty, universe;
};

#endif