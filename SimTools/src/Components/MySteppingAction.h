/*****************************************************************************\
* (c) Copyright 2020 CERN for the benefit of the LHCb Collaboration           *
*                                                                             *
* This software is distributed under the terms of the GNU General Public      *
* Licence version 3 (GPL Version 3), copied verbatim in the file "COPYING".   *
*                                                                             *
* In applying this licence, CERN does not waive the privileges and immunities *
* granted to it by virtue of its status as an Intergovernmental Organization  *
* or submit itself to any jurisdiction.                                       *
\*****************************************************************************/
// $Id: $
#ifndef MYSTEPPINGACTION_MYSTEPPINGACTION_H
#define MYSTEPPINGACTION_MYSTEPPINGACTION_H

// Include files
// Geant4
#include "G4Event.hh"
#include "G4ProcessManager.hh"
#include "G4Timer.hh"
#include "G4VProcess.hh"
#include "G4UserSteppingAction.hh"

// GiGa
#include "GiGaMTFactories/GiGaFactoryBase.h"
#include "GiGaMTFactories/GiGaTool.h"
// Gaudi
#include "Gaudi/Algorithm.h"
/// stream
#include <cstdlib>
#include <fstream>

/** @class MySteppingAction MySteppingAction.h 
 *

 *
 *  @author ADA 
 *  @date   2025-04-10
 */

// ==================================================================
// Class MySteppingAction 
// ==================================================================
class MySteppingAction : virtual public G4UserSteppingAction, virtual public Gsino::Message {
public:
  void 	UserSteppingAction(const G4Step*) override final;


  ~MySteppingAction() override;

private:
};

// ==================================================================
// Class MySteppingActionFAC
// ==================================================================
class MySteppingActionFAC : public extends<GiGaTool, GiGaFactoryBase<G4UserSteppingAction>> {
  // Declare configurable properties
public:
  // Constructor
  using extends::extends;
  StatusCode initialize() final;
  StatusCode finalize() final;

private:

  virtual G4UserSteppingAction* construct() const override {
    debug() << "Initialize construct function" << endmsg;
    auto action = new MySteppingAction{};
    action->SetMessageInterface( this->message_interface() );
    // Propagate values of properties
    debug() << "Propagating values" << endmsg;
    debug() << "End construct function" << endmsg;
    return action;
  };
};

#endif
