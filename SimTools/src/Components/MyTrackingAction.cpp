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
// Include files

#include "CLHEP/Geometry/Point3D.h"
///
#include "G4Electron.hh"
#include "G4Gamma.hh"
#include "G4OpticalPhoton.hh"
#include "G4Positron.hh"
#include "G4Step.hh"
#include "G4Timer.hh"
///
#include "GaudiKernel/MsgStream.h"
//
#include "GaudiKernel/DataObject.h"
#include "GaudiKernel/ISvcLocator.h"
#include "GaudiKernel/NTuple.h"
#include "GaudiKernel/SmartDataPtr.h"

#include "GaudiKernel/INTupleSvc.h"

#include "GaudiKernel/Algorithm.h"
#include "GaudiKernel/Chrono.h"
#include "GaudiKernel/IAlgManager.h"
#include "GaudiKernel/IAuditorSvc.h"
#include "GaudiKernel/IConversionSvc.h"
#include "GaudiKernel/IDataProviderSvc.h"
#include "GaudiKernel/IHistogramSvc.h"
#include "GaudiKernel/IMessageSvc.h"
#include "GaudiKernel/IRndmGenSvc.h"
#include "GaudiKernel/ISvcLocator.h"
#include "GaudiKernel/Kernel.h"
#include "GaudiKernel/Stat.h"

#include "GaudiKernel/GaudiException.h"
/// stream
#include <cstdlib>
#include <fstream>
#include <vector>
// local
#include "MyTrackingAction.h"

// #include "TH1F.h"
#include <string>
//-----------------------------------------------------------------------------
// Implementation file for class : MyTrackingAction
//
//-----------------------------------------------------------------------------
// Sample Tracking Action
//=============================================================================
void MyTrackingAction::PreUserTrackingAction( const G4Track* /* theTrack */ ) {
  info( "MyTrackingAction function PreUserTrackingAction" );
  return;
}

void MyTrackingAction::PostUserTrackingAction( const G4Track* /* theTrack */ ) {
  info( "MyTrackingAction function PostUserTrackingAction" );
  return;
}

void MyTrackingAction::SetTrackingManagerPointer( G4TrackingManager* /* theTrackingManager */
{
   info( "MyTrackingAction function SetTrackingManagerPointer" );
   return;
}


//=============================================================================
// Destructor
//=============================================================================
MyTrackingAction::~MyTrackingAction() {}

//=============================================================================
// Initialize
//=============================================================================
StatusCode MyTrackingActionFAC::initialize() {
  info() << "Entering initialize function" << endmsg;
  info() << "Ending initialize function" << endmsg;
  return StatusCode::SUCCESS;
};

//=============================================================================
// Finalize
//=============================================================================
StatusCode MyTrackingActionFAC::finalize() {
  debug() << "Entering finalize function" << endmsg;
  return StatusCode::SUCCESS;
};
DECLARE_COMPONENT_WITH_ID( MyTrackingActionFAC, "MyTrackingAction" )
