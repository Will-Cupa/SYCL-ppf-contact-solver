// File: fix.hpp
// Code: Claude Code and Codex
// Review: Ryoichi Ando (ryoichi.ando@zozo.com)
// License: Apache v2.0

#ifndef FIX_HPP
#define FIX_HPP

#include <sycl/sycl.hpp>
#include <dpct/dpct.hpp>
#include "../../common.hpp"
#include "../../data.hpp"

namespace fix {

float energy(const Vec3f &x, const Vec3f &y) {
    return 0.5f * (x - y).squaredNorm();
}

Vec3f gradient(const Vec3f &x, const Vec3f &y) {
    return (x - y);
}

Mat3x3f hessian() { return Mat3x3f::Identity(); }

} // namespace fix

#endif
