//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#include "ImmuneCellAlveolus.h"

#include "core/analyser/Analyser.h"
#include "core/simulation/Site.h"

void ImmuneCellAlveolus::handleInteractionEvent(InteractionEvent *ievent, double current_time) {
    if (ievent->getNextState() == "Pierce") {
        auto icState = getCellStateByName("Death");
        if (icState != 0) {
            setState(icState);
            INFO_STDOUT("Pierce: ImmuneCellAlveolus died");
        }
    }
}

std::string ImmuneCellAlveolus::getTypeName() {
    return "ImmuneCellAlveolus";
}

void ImmuneCellAlveolus::setup(double time_delta,
                       double current_time,
                       abm::util::SimulationParameters::AgentParameters *parameters) {

    ic_parameters = static_cast<abm::utilAlveolus::ImmuneCellParametersAlveolus *>(parameters);
    Cell::setup(time_delta, current_time, parameters);
}
