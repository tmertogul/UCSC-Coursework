// Tim Mertogul
// tmertogu@ucsc.edu
// Michael Lowe
// mimlowe@ucsc.edu
// CMPS109
// Spring 2015
// ASG 3

// $Id: xless.h,v 1.3 2014-04-24 18:02:55-07 - - $

#ifndef __XLESS_H__
#define __XLESS_H__

//
// We assume that the type type_t has an operator< function.
//

template <typename Type>
struct xless {
   bool operator() (const Type& left, const Type& right) const {
      return left < right;
   }
};

#endif

