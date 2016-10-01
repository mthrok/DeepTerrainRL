#ifndef _DEEP_TERRAIN_RL_SCENARIOS_DRAWSCENARIOTRAINMACE_H_
#define _DEEP_TERRAIN_RL_SCENARIOS_DRAWSCENARIOTRAINMACE_H_

#include <memory>

#include "scenarios/DrawScenarioTrain.hpp"

class cDrawScenarioTrainMACE: public cDrawScenarioTrain
{
public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	cDrawScenarioTrainMACE(cCamera& cam);
	virtual ~cDrawScenarioTrainMACE();

protected:

	virtual void BuildTrainScene(std::shared_ptr<cScenarioTrain>& out_scene) const;
};

#endif
