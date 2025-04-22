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
#ifndef MYEVENTACTION_MYEVENTACTION_H
#define MYEVENTACTION_MYEVENTACTION_H

// Include files
// Geant4
#include "G4Event.hh"
#include "G4ProcessManager.hh"
#include "G4Timer.hh"
#include "G4UserTrackingAction.hh"
#include "G4VProcess.hh"
#include "G4UserEventAction.hh"

// GiGa
#include "GaudiKernel/IHistogramSvc.h"
#include "GaudiKernel/INTupleSvc.h"
#include "GaudiKernel/NTuple.h"
#include "GiGaMTFactories/GiGaFactoryBase.h"
#include "GiGaMTFactories/GiGaTool.h"
// Gaudi
#include "Gaudi/Accumulators/Histogram.h"
#include "Gaudi/Algorithm.h"
/// stream
#include <cstdlib>
#include <fstream>

/** @class MyEventAction MyEventAction.h 
 *

 *
 *  @author ADA 
 *  @date   2025-04-10
 */

// ==================================================================
// Class MyEventAction 
// ==================================================================
class MyEventAction : virtual public G4UserEventAction, virtual public Gsino::Message {
public:
  void 	BeginOfEventAction(const G4Event*) override final;
  void  EndOfEventAction(const G4Event*) override final;


  ~MyEventAction() override;

private:
};

// ==================================================================
// Class MyEventActionFAC
// ==================================================================
class MyEventActionFAC : public extends<GiGaTool, GiGaFactoryBase<G4UserEventAction>> {
  // Declare configurable properties
public:
  // Constructor
  using extends::extends;
  StatusCode initialize() final;
  StatusCode finalize() final;

private:

  virtual G4UserEventAction* construct() const override {
    debug() << "Initialize construct function" << endmsg;
    auto action = new MyEventAction{};
    action->SetMessageInterface( this->message_interface() );
    // Propagate values of properties
    debug() << "Propagating values" << endmsg;
    debug() << "End construct function" << endmsg;
    return action;
  };
};

#endif
