#ifndef _DEEP_TERRAIN_RL_SCENARIOS_DRAWSCENARIOEXP_H_
#define _DEEP_TERRAIN_RL_SCENARIOS_DRAWSCENARIOEXP_H_

#include <memory>
#include "scenarios/DrawScenarioSimChar.hpp"

class cDrawScenarioExp : public cDrawScenarioSimChar
{
public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	cDrawScenarioExp(cCamera& cam);
	virtual ~cDrawScenarioExp();

protected:
	virtual void BuildScene();
	virtual void ResetCallback();
};

#endif
