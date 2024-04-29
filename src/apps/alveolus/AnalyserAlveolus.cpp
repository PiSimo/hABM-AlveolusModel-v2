//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#include "AnalyserAlveolus.h"

AnalyserAlveolus::AnalyserAlveolus(const std::string& config_path, const std::string& project_dir)
    : Analyser( std::move(config_path), std::move(project_dir)){}

std::shared_ptr<InSituMeasurements> AnalyserAlveolus::generateMeasurement(const std::string& id) const {
    std::shared_ptr<InSituMeasurementsAlveolus> new_measurement = nullptr;
#pragma omp critical
    {
        new_measurement = measurements_.emplace_back(
            std::make_shared<InSituMeasurementsAlveolus>(parameters_.active_measurements, id));
    }
    return new_measurement;
}
void AnalyserAlveolus::outputAllMeasurements() const {
    for (const auto &measurement: measurements_) {
        measurement->writeToFiles(measurement_path_);
    }
}
