// File: logarithm.hpp
// Code: Claude Code and Codex
// Review: Ryoichi Ando (ryoichi.ando@zozo.com)
// License: Apache v2.0

#ifndef LOGARITHM_HPP
#define LOGARITHM_HPP

#include <sycl/sycl.hpp>
#include <dpct/dpct.hpp>
#include "../data.hpp"
#include "../float_math.hpp"

namespace logarithm {

static float energy(float g, float ghat, float offset) {
    g -= offset;
    if (g <= 0.0f) {
        return std::numeric_limits<float>::infinity();
    } else if (g >= ghat) {
        return 0.0f;
    }
    return -(g - ghat) * (g - ghat) * fmath::log(g / ghat);
}

static float gradient(float g, float ghat, float offset) {
    g -= offset;
    if (g <= 0.0f) {
        return -std::numeric_limits<float>::infinity();
    } else if (g >= ghat) {
        return 0.0f;
    }
    return (ghat - g) * (2.0f * g * fmath::log(g / ghat) + g - ghat) / g;
}

static float curvature(float g, float ghat, float offset) {
    g -= offset;
    if (g <= 0.0f) {
        return std::numeric_limits<float>::infinity();
    } else if (g >= ghat) {
        return 0.0f;
    }
    return -2.0f * fmath::log(g / ghat) + ghat * (ghat + 2.0f * g) / (g * g) - 3.0f;
}

} // namespace logarithm

#endif
