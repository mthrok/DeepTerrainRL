#ifndef _DEEP_TERRAIN_RL_SCENARIOS_DRAWSCENARIOEXPMACE_H_
#define _DEEP_TERRAIN_RL_SCENARIOS_DRAWSCENARIOEXPMACE_H_

#include <memory>
#include "scenarios/DrawScenarioExp.hpp"

class cDrawScenarioExpMACE : public cDrawScenarioExp
{
public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	cDrawScenarioExpMACE(cCamera& cam);
	virtual ~cDrawScenarioExpMACE();

protected:
	virtual void BuildScene();
};

#endif
