#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "hittable.hpp"
#include "color.hpp"
#include "texture.hpp"

#include <memory>

struct material {
    virtual ~material() = default;

    virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const {
        return false;
    }
};

class lambertian : public material {
    public:
    lambertian(const color& albedo);
    lambertian(std::shared_ptr<texture> tex);
    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override;

    private:
    std::shared_ptr<texture> tex;
};

class metal : public material {
    public:
    metal(const color& albedo, double fuzz);
    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override;

    private:
    color albedo;
    double fuzz;
};

class dialectric : public material {
    public:
    dialectric(double refaction_index);
    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override;

    private:
    double refraction_index;

    static double reflectance(double cosine, double refraction_index);
};

#endif