//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#include "PiercingOfImmuneCell.h"
#include "core/simulation/Interaction.h"
#include "core/simulation/Cell.h"


std::string PiercingOfImmuneCell::getTypeName() const{
    return "PiercingOfImmuneCell";
}

void PiercingOfImmuneCell::handleInteraction(Interaction *interaction,Cell* cell, double timestep, double current_time){
    Cell* immune_cell;
    Cell* fungal_cell;
    if (abm::util::isSubstring(interaction->getFirstCell()->getTypeName(), "ImmuneCell")) {
        immune_cell = interaction->getFirstCell();
        fungal_cell = interaction->getSecondCell();
    } else {
        fungal_cell = interaction->getFirstCell();
        immune_cell = interaction->getSecondCell();
    }
    auto current_radius = immune_cell->getMorphology()->getBasicSphereOfThis()->getRadius();
    if (current_radius > 10.6 * 0.6) {
        immune_cell->getMorphology()->getBasicSphereOfThis()->setRadius(current_radius * 0.99);
        double blue = immune_cell->getSurface()->getColorRGB()->getBlue();
        double green = immune_cell->getSurface()->getColorRGB()->getGreen();
        double red = immune_cell->getSurface()->getColorRGB()->getRed();
        double transm = immune_cell->getSurface()->getColorRGB()->getTransmit();
        immune_cell->getSurface()->setColorRGB(std::make_unique<ColorRGB>(red * 1.005, green * 1.005, blue * 1.005, transm * 1.005));
    }
    immune_cell->setShiftAllowed(false);
    fungal_cell->setShiftAllowed(false);

}