//       $Id: constants.h 627 2020-01-12 18:27:53Z p20068 $
//      $URL: https://svn01.fh-hagenberg.at/se/minilib/ml5/trunk/product/ml5/inc/ml5/utility/constants.h $
// $Revision: 627 $
//     $Date: 2020-01-12 19:27:53 +0100 (So., 12 Jän 2020) $
//   Creator: peter.kulczycki<AT>fh-hagenberg.at
//  Creation: June 1, 2018
//   $Author: p20068 $
// Copyright: (c) 2018 Peter Kulczycki (peter.kulczycki<AT>fh-hagenberg.at)
//            (c) 2018 Michael Hava (michael.hava<AT>fh-hagenberg.at)
//   License: This document contains proprietary information belonging to
//            University of Applied Sciences Upper Austria, Campus Hagenberg. It
//            is distributed under the Boost Software License, Version 1.0 (see
//            http://www.boost.org/LICENSE_1_0.txt).

#pragma once

#include "./detection.h"

// -------------------------------------------------------------------------------------------------

namespace ml5 {

constexpr auto version_mayor  {5};
constexpr auto version_minor  {3};
constexpr auto version_string {"5.03"};
constexpr auto version        {version_mayor * 100 + version_minor};

}   // namespace ml5

// -------------------------------------------------------------------------------------------------

namespace ml5::util {

template <typename T> constexpr T pi {static_cast <T> (3.1415926535897932384626433832795L)};

template <typename T> constexpr T deg {pi <T> / 180};
template <typename T> constexpr T rad {1 / deg <T>};

constexpr double DEG {deg <double>};
constexpr double PI  {pi <double>};
constexpr double RAD {rad <double>};

}   // namespace ml5::util

// -------------------------------------------------------------------------------------------------

namespace ml5::literals {

inline double operator "" _deg (unsigned long long int const value) {
   return static_cast <double> (value) * util::deg <double>;
}

inline double operator "" _deg (long double const value) {
   return static_cast <double> (value * util::deg <long double>);
}

inline double operator "" _rad (unsigned long long int const value) {
   return static_cast <double> (value) * util::rad <double>;
}

inline double operator "" _rad (long double const value) {
   return static_cast <double> (value * util::rad <long double>);
}

}   // namespace ml5::literals

// -------------------------------------------------------------------------------------------------
