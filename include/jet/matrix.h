// Copyright (c) 2016 Doyub Kim

#ifndef INCLUDE_JET_MATRIX_H_
#define INCLUDE_JET_MATRIX_H_

#include <jet/macros.h>
#include <array>
#include <type_traits>

namespace jet {

template <typename T, size_t M, size_t N>
class Matrix {
 public:
    static_assert(
        M > 0,
        "Number of rows for static-sized matrix should be greater than zero.");
    static_assert(
        N > 0,
        "Number of columns for static-sized matrix should be greater than zero.");
    static_assert(
        std::is_floating_point<T>::value,
        "Matrix only can be instantiated with floating point types");

    T elements[M][N];

    Matrix();
};

}  // namespace jet

#include "detail/matrix-inl.h"

#endif  // INCLUDE_JET_MATRIX_H_
