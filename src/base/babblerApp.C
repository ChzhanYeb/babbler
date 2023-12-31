#include "babblerApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
babblerApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

babblerApp::babblerApp(InputParameters parameters) : MooseApp(parameters)
{
  babblerApp::registerAll(_factory, _action_factory, _syntax);
}

babblerApp::~babblerApp() {}

void 
babblerApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<babblerApp>(f, af, s);
  Registry::registerObjectsTo(f, {"babblerApp"});
  Registry::registerActionsTo(af, {"babblerApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
babblerApp::registerApps()
{
  registerApp(babblerApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
babblerApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  babblerApp::registerAll(f, af, s);
}
extern "C" void
babblerApp__registerApps()
{
  babblerApp::registerApps();
}
