#ifndef _DEEP_TERRAIN_RL_SCENARIOS_SCENARIOEXPMACE_H_
#define _DEEP_TERRAIN_RL_SCENARIOS_SCENARIOEXPMACE_H_

#include "scenarios/ScenarioExp.hpp"
#include "learning/MACETrainer.hpp"
#include "sim/DogControllerMACE.hpp"
#include "sim/GoatControllerMACE.hpp"
#include "sim/RaptorControllerMACE.hpp"

class cScenarioExpMACE : public cScenarioExp
{
public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	cScenarioExpMACE();
	virtual ~cScenarioExpMACE();

	virtual std::string GetName() const;

protected:

	virtual void RecordFlagsBeg(tExpTuple& out_tuple) const;
	virtual void RecordFlagsEnd(tExpTuple& out_tuple) const;

	virtual bool CheckExpCritic() const;
	virtual bool CheckExpActor() const;
};

#endif
