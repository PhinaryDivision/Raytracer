#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "hittable.hpp"
#include "vec3.hpp"
#include "interval.hpp"
#include "material.hpp"

#include <cmath>
#include <memory>

struct sphere : public hittable {

    point3 center;
    double radius;
    std::shared_ptr<material> mat;

    sphere(const point3& center, double radius, std::shared_ptr<material> mat);
    bool hit(const ray& r, interval ray_t, hit_record& rec) const override;
};

#endif