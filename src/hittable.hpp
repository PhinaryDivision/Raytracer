#ifndef HITTABLE_HPP
#define HITTABLE_HPP

#include "ray.hpp"
#include "interval.hpp"
#include "aabb.hpp"

#include <memory>

struct material;

struct hit_record {
    point3 p;
    vec3 normal;
    std::shared_ptr<material> mat;
    double t;
    bool front_face;

    void set_face_normal(const ray& r, const vec3& outward_normal);
};

struct hittable {
    virtual ~hittable() = default;
    virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;
    virtual aabb bounding_box() const = 0;
};

#endif