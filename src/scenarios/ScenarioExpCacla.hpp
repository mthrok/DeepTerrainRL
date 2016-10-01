#ifndef _DEEP_TERRAIN_RL_SCENARIOS_SCENARIOEXPCACLA_H_
#define _DEEP_TERRAIN_RL_SCENARIOS_SCENARIOEXPCACLA_H_

#include "scenarios/ScenarioExp.hpp"

class cScenarioExpCacla : public cScenarioExp
{
public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	cScenarioExpCacla();
	virtual ~cScenarioExpCacla();

	virtual std::string GetName() const;

protected:

	virtual void RecordFlagsBeg(tExpTuple& out_tuple) const;
	virtual void RecordFlagsEnd(tExpTuple& out_tuple) const;
};

#endif
