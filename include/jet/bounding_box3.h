// Copyright (c) 2016 Doyub Kim

#ifndef INCLUDE_JET_BOUNDING_BOX3_H_
#define INCLUDE_JET_BOUNDING_BOX3_H_

#include <jet/bounding_box.h>
#include <jet/vector3.h>
#include <jet/ray3.h>
#include <limits>

namespace jet {

template <typename T>
struct BoundingBoxRayIntersection3 {
    bool isIntersecting = false;
    T tNear = std::numeric_limits<T>::max();
    T tFar = std::numeric_limits<T>::max();
};

//!
//! \brief 3-D axis-aligned bounding box class.
//! \tparam T - Real number type.
//! \tparam N - Dimension.
//!
template <typename T>
class BoundingBox<T, 3> {
 public:
    Vector3<T> lowerCorner;
    Vector3<T> upperCorner;

    //! Default constructor.
    BoundingBox();

    //! Constructs a box that tightly covers two points.
    explicit BoundingBox(const Vector3<T>& point1, const Vector3<T>& point2);

    //! Constructs a box with other box instance.
    BoundingBox(const BoundingBox& other);


    //! Returns width of the box.
    T width() const;

    //! Returns height of the box.
    T height() const;

    //! Returns depth of the box.
    T depth() const;

    //! Returns length of the box in given axis.
    T length(size_t axis);

    //! Returns true of this box and other box overlaps.
    bool overlaps(const BoundingBox& other) const;

    //! Returns true if the input vector is inside of this box.
    bool contains(const Vector3<T>& point) const;

    //! Returns true if the input ray is intersecting with this box.
    bool intersects(const Ray3<T>& ray) const;

    //! Returns intersection.isIntersecting = true if the input ray is
    //! intersecting with this box. If interesects, intersection.tNear is
    //! assigned with distant to the closest intersecting point, and
    //! intersection.tFar with furthest.
    void getClosestIntersection(
        const Ray3<T>& ray,
        BoundingBoxRayIntersection3<T>* intersection) const;

    //! Returns the mid-point of this box.
    Vector3<T> midPoint() const;

    //! Returns diagonal length of this box.
    T diagonalLength() const;

    //! Returns squared diagonal length of this box.
    T diagonalLengthSquared() const;


    //! Resets this box to initial state (min=infinite, max=-infinite).
    void reset();

    //! Merges this and other point.
    void merge(const Vector3<T>& point);

    //! Merges this and other boxes.
    void merge(const BoundingBox& other);

    //! Expands this box by given delta to all direction.
    //! If the width of the box was x, expand(y) will result a box with
    //! x+y+y width.
    void expand(T delta);

    //! Returns corner position. Index starts from x-first order.
    Vector3<T> corner(size_t idx) const;
};

template <typename T> using BoundingBox3 = BoundingBox<T, 3>;

typedef BoundingBox3<float> BoundingBox3F;
typedef BoundingBox3<double> BoundingBox3D;
typedef BoundingBoxRayIntersection3<float> BoundingBoxRayIntersection3F;
typedef BoundingBoxRayIntersection3<double> BoundingBoxRayIntersection3D;

}  // namespace jet

#include "detail/bounding_box3-inl.h"

#endif  // INCLUDE_JET_BOUNDING_BOX3_H_
