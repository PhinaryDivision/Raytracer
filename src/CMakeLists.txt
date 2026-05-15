set(SOURCES
    main.cpp
    vec3.cpp
    color.cpp
    ray.cpp
    sphere.cpp
    hittable.cpp
    hittable_list.cpp
    interval.cpp
    camera.cpp
    material.cpp)

target_sources(raytracer PRIVATE ${SOURCES})
target_compile_features(raytracer PRIVATE cxx_std_20)
target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
