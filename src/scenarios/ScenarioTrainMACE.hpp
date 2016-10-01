#ifndef _DEEP_TERRAIN_RL_SCENARIOS_SCENARIOTRAINMACE_H_
#define _DEEP_TERRAIN_RL_SCENARIOS_SCENARIOTRAINMACE_H_

#include "scenarios/ScenarioTrainCacla.hpp"
#include "learning/MACETrainer.hpp"
#include "learning/AsyncMACETrainer.hpp"

class cScenarioTrainMACE : public cScenarioTrain
{
public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	cScenarioTrainMACE();
	virtual ~cScenarioTrainMACE();

	virtual std::string GetName() const;

protected:
	virtual void BuildTrainer(std::shared_ptr<cTrainerInterface>& out_trainer);
	virtual void BuildExpScene(std::shared_ptr<cScenarioExp>& out_exp) const;
	virtual void GetFragParams(int& out_num_frags, int& out_frag_size) const;
};

#endif
