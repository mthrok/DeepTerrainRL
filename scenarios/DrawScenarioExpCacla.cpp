#include "scenarios/DrawScenarioExpCacla.hpp"
#include "scenarios/ScenarioExpCacla.hpp"

cDrawScenarioExpCacla::cDrawScenarioExpCacla(cCamera& cam)
	: cDrawScenarioExp(cam)
{
}

cDrawScenarioExpCacla::~cDrawScenarioExpCacla()
{
}

void cDrawScenarioExpCacla::BuildScene()
{
	mScene = std::shared_ptr<cScenarioSimChar>(new cScenarioExpCacla());
	tCallbackFunc func = std::bind(&cDrawScenarioExpCacla::ResetCallback, this);
	mScene->SetResetCallback(func);
}
