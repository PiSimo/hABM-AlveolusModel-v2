//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#ifndef CORE_SIMULATION_CONDITION_H
#define CORE_SIMULATION_CONDITION_H

#include <string>

class Cell;

class Condition {
public:
  // Class for conditioning interactions or states to environmental or cell-specific factors.
    Condition() = default;
    explicit Condition(Cell* cell) :cell_(cell) {};
    explicit Condition(const std::string& condition) :condition_(condition) {};

    bool isFulfilled(Condition* condition);
    Cell* getCell();
    std::string getStringCondition();

private:
    Cell* cell_{};
    std::string condition_{};
    
};

#endif /* CORE_SIMULATION_CONDITION_H */
