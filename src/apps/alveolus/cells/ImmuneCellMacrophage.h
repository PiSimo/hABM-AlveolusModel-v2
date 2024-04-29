//  Copyright by Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer
//  Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
//  https://www.leibniz-hki.de/en/applied-systems-biology.html
//  HKI-Center for Systems Biology of Infection
//  Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
//  Adolf-Reichwein-Straße 23, 07745 Jena, Germany
//
//  This code is licensed under BSD 2-Clause
//  See the LICENSE file provided with this code for the full license.

#ifndef ImmuneCellMacrophage_H
#define    ImmuneCellMacrophage_H

#include "core/simulation/Cell.h"
#include "ImmuneCellAlveolus.h"
#include "apps/alveolus/AlveoleSite.h"

class ImmuneCellMacrophage : public ImmuneCell {
public:
  // Class for macrophage cells that enables macrophage properties such as receptor-ligand binding for chemotaxis
    ImmuneCellMacrophage(std::unique_ptr<Coordinate3D> c, int id, Site *site, double time_delta, double current_time)
        : ImmuneCell(std::move(c), id, site, time_delta, current_time) {};

    /*!
     * Sets up ImmuneCellMacrophage from input parameters
     * @param time_delta Double that contains time step
     * @param current_time Double that contains current time
     * @param parameters SimulationParameters with agent parameters
     */
    void setup(double time_delta, double current_time, abm::util::SimulationParameters::AgentParameters *parameters) final;

    /*!
     * Lets the ImmuneCellMacrophage interact with molecules
     * @param timestep Double that contains time step
     */
    void interactWithMolecules(double timestep) final;

    /// Sets variable on certain event
    void setVariableOnEvent(std::string variable, double value) final;

    /// Returns "ImmuneCellMacrophage"
    std::string getTypeName() final;

    /// Returns value for feature (variable)
    double getFeatureValueByName(std::string name) final;

    // Returns number of uptaken fungi
    unsigned int getCurrentNoOfUptakes();

private:
    void handleInteractionEvent(InteractionEvent *ievent, double current_time) final;
    unsigned int currentNoOfUptakes{};
    double timeOfAECThit{};

    // Variables for model taken from Guo et al. (2007)
    double receptors{};
    double LRComplexes{};
    double Rinternalized{};
    double k_blr{};
    double k_i{};
    double k_r{};
    double consumedLigandsPersistence{};

    double radius{};
    AlveoleSite* alveolesite{};
    Coordinate3D cumulativePersistenceGradient{};
    abm::utilAlveolus::ImmuneCellMacrophage* ic_parameters{};
};

#endif    /* ImmuneCellMacrophage_H */

