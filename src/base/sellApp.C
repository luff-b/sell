#include "sellApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
sellApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

sellApp::sellApp(InputParameters parameters) : MooseApp(parameters)
{
  sellApp::registerAll(_factory, _action_factory, _syntax);
}

sellApp::~sellApp() {}

void
sellApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<sellApp>(f, af, s);
  Registry::registerObjectsTo(f, {"sellApp"});
  Registry::registerActionsTo(af, {"sellApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
sellApp::registerApps()
{
  registerApp(sellApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
sellApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  sellApp::registerAll(f, af, s);
}
extern "C" void
sellApp__registerApps()
{
  sellApp::registerApps();
}
