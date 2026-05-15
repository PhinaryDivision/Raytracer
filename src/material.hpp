#ifndef MATERIAL_H
#define MATERIAL_H

#include "hittable.hpp"
#include "color.hpp"

struct material {
    virtual ~material() = default;

    virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const {
        return false;
    }
};

class lambertian : public material {
    public:
    lambertian(const color& albedo);
    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override;

    private:
    color albedo;
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