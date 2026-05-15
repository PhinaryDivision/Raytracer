#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.hpp"
#include "interval.hpp"

#include <memory>
#include <vector>

struct hittable_list : public hittable {

    std::vector<std::shared_ptr<hittable>> objects;

    hittable_list() {};
    hittable_list(std::shared_ptr<hittable> object)  { add(object); };

    void clear();
    void add(std::shared_ptr<hittable> object);
    bool hit(const ray& r, interval ray_t, hit_record& rec) const override;

};

#endif