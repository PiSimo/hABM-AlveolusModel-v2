//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#include <memory>

#include "RateFactory.h"
#include "core/simulation/Condition.h"
#include "core/simulation/rates/ConstantRate.h"
#include "core/simulation/rates/ConditionalRate.h"

RateFactory::RateFactory(const std::vector<RateParameter> &rates) {
    for (const auto &rate: rates) {
        if ("ConstantRate" == rate->type) {
            rates_.emplace(std::make_pair(rate->key, std::make_unique<ConstantRate>(rate->rate)));
        } else if ("ConditionalRate" == rate->type) {
            auto condition = std::make_unique<Condition>(rate->condition);
            rates_.emplace(
                    std::make_pair(rate->key, std::make_unique<ConditionalRate>(rate->rate, std::move(condition), rate->additional_factor)));
        }
    }
}

Rate *RateFactory::getRate(const std::string &rate_key) {
    return rates_[rate_key].get();
}

std::unordered_map<std::string, std::unique_ptr<Rate>> &RateFactory::getRates() {
    return rates_;
}
