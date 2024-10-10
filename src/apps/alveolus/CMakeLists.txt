add_library(simulatorAlveolus SHARED
        SimulatorAlveolus.cpp
        AlveoleSite.cpp
        io_utils_alveolus.cpp
        cells/FungalCellAlveolus.cpp
        cells/ImmuneCellAlveolus.cpp
        CellFactoryAlveolus.cpp
        AnalyserAlveolus.cpp
        InSituMeasurementsAlveolus.cpp
        AgentManagerAlveolus.cpp
        cells/ImmuneCellMacrophage.cpp
        visualizer/VisualizerAlveolus.cpp
        visualizer/PovFileAlveolus.cpp
        particles/ParticleManager.cpp
        particles/Particle.cpp
        particles/ParticleNeighbourList.cpp
        particles/StaticBalloonList.cpp
        movement/BiasedPersistentRandomWalk.cpp
        interactiontypes/PiercingOfImmuneCell.cpp
        cellparts/HyphalBranch.cpp
        environment/Surface.cpp
)

target_include_directories(simulatorAlveolus PRIVATE ../..)