#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "hittable.hpp"
#include "vec3.hpp"
#include "interval.hpp"
#include "material.hpp"

#include <cmath>
#include <memory>

struct sphere : public hittable {
    public:
    sphere(const point3& static_center, double radius, std::shared_ptr<material> mat);
    sphere(const point3& center1, const point3& center2, double radius, std::shared_ptr<material> mat);
    bool hit(const ray& r, interval ray_t, hit_record& rec) const override;

    private:
    ray center;
    double radius;
    std::shared_ptr<material> mat;
};

#endif