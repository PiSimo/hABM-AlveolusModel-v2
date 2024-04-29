//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#include "CellFactoryAlveolus.h"
#include "core/simulation/cells/ImmuneCell.h"
#include "core/simulation/cells/FungalCell.h"
#include "apps/alveolus/cells/FungalCellAlveolus.h"
#include "core/simulation/Site.h"
#include "apps/alveolus/cells/ImmuneCellMacrophage.h"


CellFactoryAlveolus::CellFactoryAlveolus(const std::unique_ptr<abm::util::SimulationParameters::SiteParameters>
        &site_parameters) : CellFactory(site_parameters){
}

std::shared_ptr<Cell> CellFactoryAlveolus::createCell(const std::string &agenttype,
                                              std::unique_ptr<Coordinate3D> c,
                                              int id,
                                              Site *site,
                                              double time_delta,
                                              double current_time) {
    std::shared_ptr<Cell> agent{};
    auto site_tag = site->getIdentifier();
    if (agenttype == "Cell") {
        agent = std::make_shared<Cell>(std::move(c), id, site, time_delta, current_time);
    } else if (agenttype == "ImmuneCell") {
        agent = std::make_shared<ImmuneCell>(std::move(c), id, site, time_delta, current_time);
    } else if (agenttype == "FungalCell") {
        agent = std::make_shared<FungalCell>(std::move(c), id, site, time_delta, current_time);
    }else if (agenttype == "FungalCellAlveolus") {
        agent = std::make_shared<FungalCellAlveolus>(std::move(c), id, site, time_delta, current_time);
    }else if (agenttype == "ImmuneCellMacrophage") {
        agent = std::make_shared<ImmuneCellMacrophage>(std::move(c), id, site, time_delta, current_time);
    }
    agent->setup(time_delta, current_time, agent_configurations_[site_tag + agenttype].get());

    return agent;
}


