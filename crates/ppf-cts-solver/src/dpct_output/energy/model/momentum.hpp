// File: momentum.hpp
// Code: Claude Code and Codex
// Review: Ryoichi Ando (ryoichi.ando@zozo.com)
// License: Apache v2.0

#ifndef MOMENTUM_HPP
#define MOMENTUM_HPP

#include <sycl/sycl.hpp>
#include <dpct/dpct.hpp>
#include "../../common.hpp"
#include "../../data.hpp"

namespace momentum {

float energy(float dt, const Vec3f &x, const Vec3f &y) {
    return 0.5f * (x - y).squaredNorm() / (dt * dt);
}

Vec3f gradient(float dt, const Vec3f &x, const Vec3f &y) {
    return (x - y) / (dt * dt);
}

Mat3x3f hessian(float dt) { return Mat3x3f::Identity() / (dt * dt); }

} // namespace momentum

#endif
