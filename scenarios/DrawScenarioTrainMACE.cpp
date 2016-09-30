#include "scenarios/DrawScenarioTrainMACE.hpp"
#include "scenarios/ScenarioTrainMACE.hpp"

cDrawScenarioTrainMACE::cDrawScenarioTrainMACE(cCamera& cam)
	: cDrawScenarioTrain(cam)
{
}

cDrawScenarioTrainMACE::~cDrawScenarioTrainMACE()
{
}

void cDrawScenarioTrainMACE::BuildTrainScene(std::shared_ptr<cScenarioTrain>& out_scene) const
{
	out_scene = std::shared_ptr<cScenarioTrainMACE>(new cScenarioTrainMACE());
}
