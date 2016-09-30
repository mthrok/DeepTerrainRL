#include "scenarios/DrawScenarioExpMACE.hpp"
#include "scenarios/ScenarioExpMACE.hpp"

cDrawScenarioExpMACE::cDrawScenarioExpMACE(cCamera& cam)
	: cDrawScenarioExp(cam)
{
}

cDrawScenarioExpMACE::~cDrawScenarioExpMACE()
{
}

void cDrawScenarioExpMACE::BuildScene()
{
	mScene = std::shared_ptr<cScenarioSimChar>(new cScenarioExpMACE());
	tCallbackFunc func = std::bind(&cDrawScenarioExpMACE::ResetCallback, this);
	mScene->SetResetCallback(func);
}
