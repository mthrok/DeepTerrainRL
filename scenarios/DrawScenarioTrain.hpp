#ifndef _DEEP_TERRAIN_RL_SCENARIOS_DRAWSCENARIOTRAIN_H_
#define _DEEP_TERRAIN_RL_SCENARIOS_DRAWSCENARIOTRAIN_H_

#include <memory>

#include "scenarios/DrawScenarioSimChar.hpp"
#include "scenarios/ScenarioTrain.hpp"

class cDrawScenarioTrain: public cDrawScenarioSimChar
{
public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	cDrawScenarioTrain(cCamera& cam);
	virtual ~cDrawScenarioTrain();

	virtual void Init();
	virtual void Reset();
	virtual void Clear();
	virtual void Update(double time_elapsed);

	virtual void Keyboard(unsigned char key, int x, int y);
	virtual void Shutdown();

	virtual std::string GetName() const;

protected:
	std::shared_ptr<cScenarioTrain> mTrain;

	virtual void BuildTrainScene(std::shared_ptr<cScenarioTrain>& out_scene) const;
	virtual void ToggleTraining();
	virtual void ResetCallback();
};

#endif
