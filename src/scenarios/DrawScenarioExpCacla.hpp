#ifndef _DEEP_TERRAIN_RL_SCENARIOS_DRAWSCENARIOEXPCACLA_H_
#define _DEEP_TERRAIN_RL_SCENARIOS_DRAWSCENARIOEXPCACLA_H_

#include <memory>

#include "scenarios/DrawScenarioExp.hpp"

class cDrawScenarioExpCacla : public cDrawScenarioExp
{
public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	cDrawScenarioExpCacla(cCamera& cam);
	virtual ~cDrawScenarioExpCacla();

protected:
	virtual void BuildScene();
};

#endif
