//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#ifndef CORE_SIMULATION_RATE_H
#define CORE_SIMULATION_RATE_H

#include <string>

class Condition;
class Cell;
class Site;

class Rate {
  public:
    /// Class for rate related calculations defining interaction rates. Rate definitions are given in the associated input-config.
    virtual ~Rate() = default;

    [[nodiscard]] virtual double
    calculateProbability(double timestep, double current_time, Condition *cond, Cell *cell, Site *site) const = 0;
    [[nodiscard]] virtual double getRateValue() const = 0;
    [[nodiscard]] virtual std::string_view getRateType() const = 0;
    virtual void adjustRate(const std::string &, double timestep_size) {};
};

#endif /* CORE_SIMULATION_RATE_H */
