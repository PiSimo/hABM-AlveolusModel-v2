//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#ifndef CORE_SIMULATION_CONSTANTRATE_H
#define CORE_SIMULATION_CONSTANTRATE_H

#include "Rate.h"

class ConstantRate : public Rate {
public:
  // Class for a constant rate which does not change during runtime.
    explicit ConstantRate(double constant_value) : constant_rate_(constant_value) {}

    [[nodiscard]] double calculateProbability(double timestep, double current_time, Condition *cond, Cell *cell, Site *site) const final;
    [[nodiscard]] double getRateValue() const final { return constant_rate_; }
    [[nodiscard]] std::string_view getRateType() const final { return "ConstantRate"; }

private:
    double constant_rate_;
};
#endif /* CORE_SIMULATION_CONSTANTRATE_H */
