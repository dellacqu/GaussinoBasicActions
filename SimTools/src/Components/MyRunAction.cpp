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

///
#include "GaudiKernel/MsgStream.h"
//
#include "GaudiKernel/DataObject.h"
#include "GaudiKernel/ISvcLocator.h"
#include "GaudiKernel/NTuple.h"
#include "GaudiKernel/SmartDataPtr.h"

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
#include "MyRunAction.h"

#include <string>
//-----------------------------------------------------------------------------
// Implementation file for class : MyRunAction
//
//-----------------------------------------------------------------------------
// Sample Run Action
//=============================================================================
void MyRunAction::BeginOfRunAction( const G4Run* /* theRun */ ) {
  info( "MyRunAction function BeginOfRunAction" );
  info( " dio bastardo!!!!" );
  return;
}

void MyRunAction::EndOfRunAction( const G4Run* /* theRun */ ) {
  info( "MyRunAction function EndOfEventAction" );
  info( "dio puttana!!!!" );
  return;
}


//=============================================================================
// Destructor
//=============================================================================
MyRunAction::~MyRunAction() {}

//=============================================================================
// Initialize
//=============================================================================
StatusCode MyRunActionFAC::initialize() {
  info() << "Entering initialize function" << endmsg;
  info() << "Ending initialize function" << endmsg;
  return StatusCode::SUCCESS;
};

//=============================================================================
// Finalize
//=============================================================================
StatusCode MyRunActionFAC::finalize() {
  debug() << "Entering finalize function" << endmsg;
  return StatusCode::SUCCESS;
};
DECLARE_COMPONENT_WITH_ID( MyRunActionFAC, "MyRunAction" )
