// This file is part of LatCommon.
//
// LatCommon
// Copyright (C) 2012-2016  Pierre L'Ecuyer and Universite de Montreal
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/* NormaMinkL1.h for ISO C++ */
#ifndef LATCOMMON__NORMAMINKL1_H
#define LATCOMMON__NORMAMINKL1_H
#include "latcommon/Normalizer.h"
#include <stdexcept>


namespace LatCommon {

/**
 * This class implements theoretical bounds on the length of the shortest
 * nonzero vector in a lattice, based on the densest sphere packing in space.
 * The length of vectors is computed using the \f${\mathcal{L}}_1\f$ norm.
 * Here, the length of the shortest nonzero vector gives the minimal number
 * of hyperplanes that cover all the points of the lattice. The following
 * upper bound in this case was established by Marsaglia
 * \cite rMAR68a&thinsp; by applying the general convex body theorem of
 * Minkowski:
 * \f[
 * \ell_t^* = (t! m^k)^{1/t} = \gamma_t m^{k/t},
 * \f]
 * for lattices of rank \f$k\f$, containing \f$m\f$ points per unit volume,
 * in dimension \f$t\f$. The lattice constants are thus \f$\gamma_t =
 * (t!)^{1/t}\f$.
 *
 */
class NormaMinkL1 : public Normalizer {
public:

   /**
    * Constructor for the Marsaglia’s bounds with the
    * \f${\mathcal{L}}_1\f$ norm. The lattices are those of rank \f$k\f$, with
    * \f$m\f$ points per unit volume, in all dimensions \f$\le t\f$. The bias
    * factor `beta` \f$= \beta\f$ gives more weight to some of the dimensions.
    * Restriction: \f$t \le48\f$.
    */
   NormaMinkL1 (const MScal & m, int k, int t, double beta = 1);

   /**
    * Returns the value of the lattice constant \f$\gamma_j\f$ in
    * dimension \f$j\f$.
    */
   double getGamma (int j) const throw (std::out_of_range);
private:

   /**
    * Lattice constants \f$\gamma_j\f$ for Marsaglia’s bounds in each dimension
    * \f$j\f$.
    */
   static const double m_gamma[1 + Normalizer::MAX_DIM];
};

}
#endif