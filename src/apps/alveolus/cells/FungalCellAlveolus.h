//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.


#ifndef CORE_SIMULATION_FungalCellAlveolus_H
#define CORE_SIMULATION_FungalCellAlveolus_H

#include "core/simulation/cells/FungalCell.h"
#include "apps/alveolus/io_utils_alveolus.h"
#include "apps/alveolus/cellparts/HyphalBranch.h"


class FungalCellAlveolus : public FungalCell {
public:
    // To create your own Celltypes, you have to create your own CellFactory, to make sure the cell can be created
    // This must be included in the constructor of the Site (here: AlveoleSite)
    // The corresponding CellType must be used in the simulator-config.json etc.
    FungalCellAlveolus(std::unique_ptr<Coordinate3D> c, int id, Site *site,
               double time_delta, double current_time) : FungalCell(std::move(c), id, site, time_delta, current_time) {}

    void doMorphologicalChanges(double timestep, double current_time) final;

    bool isActive();

    // To guarantee the same functionality for derived class "FungalCellAlveolus" as for "FungalCell":
    // Make sure the getTypeName returns a substring of "FungalCell"
    std::string getTypeName() { return "FungalCellAlveolus"; };
    int getNumberOfBranches() {return number_of_branches_;};
    void increaseNumberOfBranches() {number_of_branches_ += 1;};

    void handleInteractionEvent(InteractionEvent *ievent, double current_time);
    void setup(double time_delta, double current_time, abm::util::SimulationParameters::AgentParameters* parameters) final;
    abm::utilAlveolus::FungalParametersAlveolus* getFungalParameter(){return fc_parameters;};

private:
    bool hyphal_growth_{};
    double rswelling_rate_{};
    double swell_diameter_{};
    double swell_carrying_capacity_{};
    double rate_next_mothercell_hyphae_{};
    int number_of_branches_{};
    bool is_active_{};

    std::vector<std::unique_ptr<HyphalBranch>> hyphal_branches_{};
    abm::utilAlveolus::FungalParametersAlveolus* fc_parameters;
};

#endif /* CORE_SIMULATION_FungalCellAlveolus_H */
