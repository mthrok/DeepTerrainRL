#ifndef _DEEP_TERRAIN_RL_SCENARIOS_DRAWSCENARIOTRAINCACLA_H_
#define _DEEP_TERRAIN_RL_SCENARIOS_DRAWSCENARIOTRAINCACLA_H_

#include <memory>

#include "scenarios/DrawScenarioTrain.hpp"

class cDrawScenarioTrainCacla: public cDrawScenarioTrain
{
public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	cDrawScenarioTrainCacla(cCamera& cam);
	virtual ~cDrawScenarioTrainCacla();

protected:

	virtual void BuildTrainScene(std::shared_ptr<cScenarioTrain>& out_scene) const;
};

#endif
