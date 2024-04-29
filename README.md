# Hybrid Agent-Based Model (hABM) 
# Alveolus Model - Version 2 (v2)

An analytical and computational model framework for simulating early *Aspergillus fumigatus* infection scenarios in the human or murine alveolus.

Christoph Saffer, Paul Rudolph, Sandra Timme, Marco Blickensdorf, Johannes Pollmächer

Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge\
https://www.leibniz-hki.de/en/applied-systems-biology.html \
HKI-Center for Systems Biology of Infection\
Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Institute (HKI)\
Adolf-Reichwein-Straße 23, 07745 Jena, Germany

The project code is licensed under BSD 2-Clause.\
See the LICENSE file provided with the code for the full license.

## Project

Welcome to the repository of the Hybrid Agent-Based Model (hABM) - Alveolus Model - version 2 (v2) - developed by the **Applied Systems Biology** team of **Leibniz-HKI**.
The main purpose of this framework includes simulating an early *Aspergillus fumigatus* infection scenario in one human or murine alveolus. 
It is based on the [previous version](https://github.com/applied-systems-biology/hABM-AlveolusModel) of the hABM-AlveolusModel and was extended by a new app structure - 
enabling more applications to access the agent-based modeling framework for different environments - and by phagocytosing alveolar epithelial cells (AECs), alveolar macrophages (AMs) and swelling *Aspergillus fumigatus* conidia.
The morphological changes of *Aspergillus fumigatus* conidia, the swelling dynamics, is based on ODE models which are also provided in this repository.
Moreover, we also added the analytical Surrogate Infection Model (SIM), based on a neural network implemented in python pytorch that predicts hABM outcomes in a fraction of time and allows extended analyses of infection dynamics.

 ![](VideoS1.m4v "To-scale representation of one human alveolus")

 ![](VideoS2.m4v "Cellular contribution to uptake of A. fumigatus")

To-scale representation of the human alveolus as a 3/4
sphere in the hABM (showcase in first video). It is composed of an epithelial cell layer consisting of alveolar epithelial
cells (AEC) type I (yellow) and type II (blue). A single *A. fumigatus* conidium (red) is
randomly positioned on the inner alveolar surface and the contacting AEC is secreting
chemokines (white isolines) to attract alveolar macrophages (green) towards the conidium.
The alveolar entrance ring and the pores of Kohn (black) are the boundaries of the system. Exemplary uptake of 
*A. fumigatus* conidia by type 2 AECs, type 1 AECs and AMs (showcase in second video).

## Requirements
- C++17 (or higher)
- Boost (>= Version 1.56)
- OpenMP (Version 4.5)
- PovRay (Version 3.7.0.8)
- CMake (recommended for build process)

## Getting started
### Build process

After cloning the repository to a local folder (here: abm/), the framework can be built via cmake:

`~/hABM-AlveolusModel-v2$ mkdir build; cd build`

Release or Debug mode: 

`~/hABM-AlveolusModel-v2/build$ cmake -DCMAKE_BUILD_TYPE=Release .. `
or `~/hABM-AlveolusModel-v2/build$ cmake -DCMAKE_BUILD_TYPE=Debug .. `

`~/hABM-AlveolusModel-v2/build$ make `

The compiled files can be found in the build/ folder.

### Run test configurations

To test if everything was compiled accordingly, run test configuration:

`~/hABM-AlveolusModel-v2/build$ cd test/`

`~/hABM-AlveolusModel-v2/build/test$ ./test_configurations`

(Test must be executed from the folder)

If the tests pass, the framework and its corresponding libraries were successfully installed.

### Model usage and input

Generally, the executable program `build/src/hABM` must be run with a `.json` configuration file as program argument

`~/hABM-AlveolusModel-v2$ build/src/hABM <config-file>.json` 

Additional input files 
- `analyser-config.json`
- `input-config.json`
- `simulator-config.json`
- `visualisation-config.json`

are located in the folder specified as `config_path` variable in `<config-file>.json`.

The output is written to the folder specified in the `output_path` variable in the `<config-file>.json`. 

### Output formats

The output is written to `output_path/AlveolusOutput/SIMULATION_FOLDER/` and contains
- measurements (if activated in `analyser-config.json`)
- visualization (if activated in `visualization-config.json`)

The main output format for generating data applicable to analytical models is found in `measurements/` folder.

## Configurations

Predefined configurations including test scenarios can be found in the folder 'configurations/'. 

For the study on Alveolar Epithelial Cells (AECs): Config folder `configurations/alveolus/basicAlveolus` and config file `config.json`

The parameters for each scenario can be adjusted in the `.json` files in the corresponding configuration folder/files.

## Run simulations 

To run simulations, execute: 

`~/hABM-AlveolusModel-v2$ build/src/hABM config.json`

For parameter screening, the cartesian product of all input sets in the `config.json` file in `parameter_screening` is calculated and the simulations are started for all parameter combinations.

## General structure
The framework is structured as followed:

- **Surrogate_Infection_Model**: Jupyter Notebooks describing data processing and framework for the Surrogate Infection Model (SIM) 
- **Diameter_Models_ODEs**: Jupyter Notebooks describing the fitting of the ODE diameter model and ODE uptake model to fungal swelling and uptake data
- **configurations**: configuration folders including `.json`files that define single scenarios
- **input**: precalculated data or parameters for the model
- **src**: source `.cpp` and header `.h` files of the framework
- **test**: test scenarios and unit tests using doctest library
- **cmake**: CMake specific files

For a detailed overview, we refer to the doxygen documentation (Doxygen-Output.zip).

## Previous publications

The essence of the hybrid agent-based model was applied to various studies about *Aspergillus fumigatus* lung infection in the past, such as:
- [Pollmächer *et. al.* (2014)](https://journals.plos.org/plosone/article?id=10.1371/journal.pone.0111630)
- [Pollmächer *et. al.* (2015)](https://www.frontiersin.org/articles/10.3389/fmicb.2015.00503/)
- [Blickensdorf *et. al.* (2019)](https://www.frontiersin.org/articles/10.3389/fimmu.2019.00142/)
- [Blickensdorf *et. al.* (2020)](https://www.frontiersin.org/articles/10.3389/fmicb.2020.01951/)
- [Saffer *et. al.* (2023)](https://www.nature.com/articles/s41540-023-00272-x)
