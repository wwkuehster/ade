#include "adeApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<adeApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

adeApp::adeApp(InputParameters parameters) : MooseApp(parameters)
{
  adeApp::registerAll(_factory, _action_factory, _syntax);
}

adeApp::~adeApp() {}

void
adeApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"adeApp"});
  Registry::registerActionsTo(af, {"adeApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
adeApp::registerApps()
{
  registerApp(adeApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
adeApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  adeApp::registerAll(f, af, s);
}
extern "C" void
adeApp__registerApps()
{
  adeApp::registerApps();
}
