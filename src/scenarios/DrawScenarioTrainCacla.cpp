#include "scenarios/DrawScenarioTrainCacla.hpp"
#include "scenarios/ScenarioTrainCacla.hpp"

cDrawScenarioTrainCacla::cDrawScenarioTrainCacla(cCamera& cam)
	: cDrawScenarioTrain(cam)
{
}

cDrawScenarioTrainCacla::~cDrawScenarioTrainCacla()
{
}

void cDrawScenarioTrainCacla::BuildTrainScene(std::shared_ptr<cScenarioTrain>& out_scene) const
{
	out_scene = std::shared_ptr<cScenarioTrainCacla>(new cScenarioTrainCacla());
}
