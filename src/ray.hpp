#ifndef RAY_H
#define RAY_H

#include "vec3.hpp"

struct ray {
    point3 orig;
    vec3 dir;

    ray() = default;
    ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}

    const point3& origin() const;
    const vec3& direction() const;

    point3 at(double t) const;
};

#endif