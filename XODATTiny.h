/*
  Subclass of a FixedPoints signed fixed-point number,
  with some operators made implicit rather than
  explicit for compatability
*/

#ifndef ATTINY_XOD
#define ATTINY_XOD

#include <stddef.h>
#include <FixedPoints.h>
#include <FixedPointsCommon.h>

template <unsigned Integer, unsigned Fraction>
struct XODFixedPoint : SFixed<Integer, Fraction> {
  typedef SFixed<Integer, Fraction> fixed_point_t;
  using fixed_point_t::fixed_point_t;  // pull in base constructors
  using typename fixed_point_t::IntegerType;  // pull in "IntegerType"

  using fixed_point_t::operator double;
  using fixed_point_t::operator float;
  using fixed_point_t::operator IntegerType;

  constexpr XODFixedPoint(const fixed_point_t& rhs)
      :  // implict constructor from parent type
        fixed_point_t(rhs) {}

  constexpr operator float() const { return static_cast<float>(*this); }

  constexpr operator double() const { return static_cast<double>(*this); }

  constexpr operator IntegerType() const {
    return static_cast<IntegerType>(*this);
  }
};

#endif