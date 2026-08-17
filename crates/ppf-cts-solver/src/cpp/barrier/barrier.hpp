// File: barrier.hpp
// Code: Claude Code and Codex
// Review: Ryoichi Ando (ryoichi.ando@zozo.com)
// License: Apache v2.0

#ifndef BARRIER_DEF_HPP
#define BARRIER_DEF_HPP

#include <sycl/sycl.hpp>
#include <dpct/dpct.hpp>
#include "../csrmat/csrmat.hpp"
#include "../data.hpp"

namespace barrier {

float energy(float g, float ghat, float offset, Barrier barrier);
float gradient(float g, float ghat, float offset, Barrier barrier);
float curvature(float g, float ghat, float offset, Barrier barrier);
Vec3f compute_edge_gradient(const Vec3f &e, float eps, float offset,
                                       Barrier barrier);
template <unsigned N>
float
compute_stiffness(const Proximity<N> &prox, const SVecf<N> &mass,
                  const FixedCSRMat &hess, const Vec3f &e, float eps,
                  float offset, const ParamSet &param);
Mat3x3f compute_edge_hessian(const Vec3f &e, float eps, float offset,
                                        Barrier barrier);
DiffTable2 compute_strainlimiting_diff_table(const Vec2f &a, float eps,
                                                        Barrier barrier);
float strainlimiting_energy(const Vec2f &a, float eps,
                                       Barrier barrier);

} // namespace barrier

#endif
