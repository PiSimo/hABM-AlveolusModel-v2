//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#include "AnalyserExample.h"

AnalyserExample::AnalyserExample(const std::string& config_path, const std::string& project_dir)
    : Analyser( std::move(config_path), std::move(project_dir)){}

std::shared_ptr<InSituMeasurements> AnalyserExample::generateMeasurement(const std::string& id) const {
    std::shared_ptr<InSituMeasurementsExample> new_measurement = nullptr;
#pragma omp critical
    {
        new_measurement = measurements_.emplace_back(
            std::make_shared<InSituMeasurementsExample>(parameters_.active_measurements, id));
    }
    return new_measurement;
}