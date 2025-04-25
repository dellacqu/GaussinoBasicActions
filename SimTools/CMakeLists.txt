###############################################################################
# (c) Copyright 2021 CERN for the benefit of the LHCb and FCC Collaborations  #
#                                                                             #
# This software is distributed under the terms of the Apache License          #
# version 2 (Apache-2.0), copied verbatim in the file "COPYING".              #
#                                                                             #
# In applying this licence, CERN does not waive the privileges and immunities #
# granted to it by virtue of its status as an Intergovernmental Organization  #
# or submit itself to any jurisdiction.                                       #
###############################################################################
#[=======================================================================[.rst:
Sim/SimTools

Author: Antonio Gomez
------------
#]=======================================================================]
# gaudi_add_library(SimToolsLib
# 	SOURCES
# 		src/Components/RadLengthColl.cpp
# 	LINK
# 		Geant4::G4global
# )

# gaudi_install(SCRIPTS)
# gaudi_install(PYTHON)
# gaudi_add_pytest()

gaudi_add_module(SimTools
    SOURCES
    src/Components/MyEventAction.cpp
    src/Components/MyRunAction.cpp
    src/Components/MySteppingAction.cpp
    src/Components/MyTrackingAction.cpp
    LINK
        Geant4::G4run
        Geant4::G4intercoms
	Gaudi::GaudiKernel
	Gaussino::GiGaMTFactoriesLib
	Gaussino::GiGaMTCoreRunLib
	Gaussino::GiGaMTCoreMessageLib
	Gaussino::GiGaMTCoreDetLib
	Gaussino::GiGaMTGeoLib

)
