//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#ifndef COREABM_VISUALIZERALVEOLUS_H
#define COREABM_VISUALIZERALVEOLUS_H

#include "core/visualisation/Visualizer.h"
#include "apps/alveolus/AlveoleSite.h"

class VisualizerAlveolus: public Visualizer {
public:

    VisualizerAlveolus(const std::string &config_path, const std::string &project_dir, int total_runs = 0) : Visualizer(config_path, project_dir, total_runs) {};

    void visualizeCurrentConfiguration(Site &site, const SimulationTime &time, int run, bool simulation_end) const override;

};


#endif //COREABM_VISUALIZERALVEOLUS_H
