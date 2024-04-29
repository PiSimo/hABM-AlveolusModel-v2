//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#ifndef COREABM_POVFILEALVEOLUS_H
#define COREABM_POVFILEALVEOLUS_H

#include "core/visualisation/PovFile.h"
#include "apps/alveolus/AlveoleSite.h"

class PovFileAlveolus: public PovFile {
public:
    explicit PovFileAlveolus(const std::string &filebody) : PovFile(filebody) {};

    void transcribeSite(Site &site);
    void transcribeAgents(Site &site);

    void transcribeParticles(Site &site);
};


#endif //COREABM_POVFILEALVEOLUS_H
