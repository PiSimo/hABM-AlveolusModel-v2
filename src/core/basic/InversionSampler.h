//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#ifndef CORE_BASIC_INVERSIONSAMPLER_H
#define CORE_BASIC_INVERSIONSAMPLER_H

#include <iostream>
#include <math.h>

#include "core/basic/Sampler.h"

class InversionSampler : public Sampler {
public:
    // Class for inversion sampling from different distributions
    InversionSampler();
    InversionSampler(const char *);
    InversionSampler(const InversionSampler &orig);
    virtual ~InversionSampler();
    double getSampledValue(unsigned int dim = 1);
    void sample(Randomizer *randomizer, unsigned int distrColumn = 0);
    double sampleFunction(double);

private:
    double sampledValue;
};

#endif /* CORE_BASIC_INVERSIONSAMPLER_H */
