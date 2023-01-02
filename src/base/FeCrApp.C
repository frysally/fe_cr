#include "FeCrApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
FeCrApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

FeCrApp::FeCrApp(InputParameters parameters) : MooseApp(parameters)
{
  FeCrApp::registerAll(_factory, _action_factory, _syntax);
}

FeCrApp::~FeCrApp() {}

void
FeCrApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"FeCrApp"});
  Registry::registerActionsTo(af, {"FeCrApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
FeCrApp::registerApps()
{
  registerApp(FeCrApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
FeCrApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  FeCrApp::registerAll(f, af, s);
}
extern "C" void
FeCrApp__registerApps()
{
  FeCrApp::registerApps();
}
