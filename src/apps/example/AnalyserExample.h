//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#ifndef COREABM_ANALYSEREXAMPLE_H
#define COREABM_ANALYSEREXAMPLE_H

#include "InSituMeasurementsExample.h"
#include "core/analyser/Analyser.h"

class AnalyserExample : public Analyser{
  public:
    AnalyserExample(const std::string &config_path, const std::string &project_dir);
    std::shared_ptr<InSituMeasurements> generateMeasurement(const std::string &id) const override;

  protected:
    mutable std::vector<std::shared_ptr<InSituMeasurementsExample>> measurements_;
};

#endif // COREABM_ANALYSEREXAMPLE_H
