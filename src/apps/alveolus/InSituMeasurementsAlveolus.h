//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#ifndef COREABM_INSITUMEASUREMENTSEXAMPLE_H
#define COREABM_INSITUMEASUREMENTSEXAMPLE_H

#include "core/analyser/InSituMeasurements.h"
#include "AlveoleSite.h"


class InSituMeasurementsAlveolus : public InSituMeasurements {
public:
    InSituMeasurementsAlveolus(std::unordered_set<std::string> active_measurements, const std::string &);
    void setSite(Site *site) override { site_ = dynamic_cast<AlveoleSite*>(site); };
    void observeMeasurements(const SimulationTime &time);
    void writeToFiles(const std::string &output_dir) const override;
};

#endif // COREABM_INSITUMEASUREMENTSEXAMPLE_H
