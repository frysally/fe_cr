//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "FeCrTestApp.h"
#include "FeCrApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
FeCrTestApp::validParams()
{
  InputParameters params = FeCrApp::validParams();
  return params;
}

FeCrTestApp::FeCrTestApp(InputParameters parameters) : MooseApp(parameters)
{
  FeCrTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

FeCrTestApp::~FeCrTestApp() {}

void
FeCrTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  FeCrApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"FeCrTestApp"});
    Registry::registerActionsTo(af, {"FeCrTestApp"});
  }
}

void
FeCrTestApp::registerApps()
{
  registerApp(FeCrApp);
  registerApp(FeCrTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
FeCrTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  FeCrTestApp::registerAll(f, af, s);
}
extern "C" void
FeCrTestApp__registerApps()
{
  FeCrTestApp::registerApps();
}
