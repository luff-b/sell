//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "sellTestApp.h"
#include "sellApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
sellTestApp::validParams()
{
  InputParameters params = sellApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

sellTestApp::sellTestApp(InputParameters parameters) : MooseApp(parameters)
{
  sellTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

sellTestApp::~sellTestApp() {}

void
sellTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  sellApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"sellTestApp"});
    Registry::registerActionsTo(af, {"sellTestApp"});
  }
}

void
sellTestApp::registerApps()
{
  registerApp(sellApp);
  registerApp(sellTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
sellTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  sellTestApp::registerAll(f, af, s);
}
extern "C" void
sellTestApp__registerApps()
{
  sellTestApp::registerApps();
}
