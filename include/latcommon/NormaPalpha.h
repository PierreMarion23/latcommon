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

/* NormaPalpha.h for ISO C++ */
#ifndef NORMAPALPHA_H
#define NORMAPALPHA_H
#include "latcommon/Normalizer.h"


namespace LatCommon {

/**
 * This class implements theoretical bounds on the values of
 * \f$P_{\alpha}\f$ for a lattice (see class <tt>Palpha</tt>).
 *
 */
class NormaPalpha : public Normalizer {
public:

   /**
    * Constructor for the bounds \f$B_{\alpha}(s)\f$ obtained for lattices, in
    * all dimensions \f$\le s\f$, where \f$\alpha= {}\f$<tt>alpha</tt>. The
    * lattices have rank \f$1\f$, with \f$m\f$ points per unit volume.
    * Restriction: \f$2 \le s \le48\f$, \f$\alpha\ge2\f$, and \f$m\f$ prime.
    */
   NormaPalpha (const MScal & m, int alpha, int s, NormType norm = L2NORM);

   /**
    * Computes and returns the bound \f$B_{\alpha}(s)\f$ given in
    * \cite mSLO94a&thinsp; (p. 83, Theorem 4.4). Given \f$s > 1\f$,
    * \f$\alpha> 1\f$, \f$m\f$ prime, and \f$m >
    * e^{\alpha s/(\alpha-1)}\f$, then there exists an integer vector
    * \f$\mathbf{a} \in\mathbb Z^s\f$ such that
    * \f[
    *   P_{\alpha}(s, \mathbf{a})  \le  B_{\alpha}(s)  =  {\Big [WARNING: attributes={'char': <plasTeX.TeXFragment object at 0x7f9d49b94e20>}] \frac{e}{s} \Big [WARNING: attributes={'char': <plasTeX.TeXFragment object at 0x7f9d49b94f58>}]}^{\alpha s} \frac{(2\ln m + s)^{\alpha s}}{m^{\alpha}}.
    * \f]
    * If the conditions for the existence of the bound are not satisfied,
    * the function returns \f$-1\f$.
    */
   double calcBound (int alpha, int s);

   /**
    * Returns the value of \f$\alpha\f$.
    */
   int getAlpha () const;
private:

   /**
    * The value of \f$\alpha\f$.
    */
   int alpha;
};

}
#endif