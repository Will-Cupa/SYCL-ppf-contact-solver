// File: quadratic.hpp
// Code: Claude Code and Codex
// Review: Ryoichi Ando (ryoichi.ando@zozo.com)
// License: Apache v2.0

#ifndef QUADRATIC_HPP
#define QUADRATIC_HPP

#include <sycl/sycl.hpp>
#include <dpct/dpct.hpp>
#include "../data.hpp"

namespace quadratic {

static float energy(float g, float ghat, float offset) {
    g -= offset;
    float y = ghat - g;
    if (y > 0.0f) {
        return y * y;
    } else {
        return 0.0f;
    }
}

static float gradient(float g, float ghat, float offset) {
    g -= offset;
    float y = ghat - g;
    if (y > 0.0f) {
        return -2.0f * y;
    } else {
        return 0.0f;
    }
}

static float curvature(float g, float ghat, float offset) {
    g -= offset;
    if (ghat - g > 0.0f) {
        return 2.0f;
    } else {
        return 0.0f;
    }
}

} // namespace quadratic

#endif
