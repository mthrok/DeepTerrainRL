#ifndef _DEEP_TERRAIN_RL_LEARNING_ASYNCQNETTRAINER_H_
#define _DEEP_TERRAIN_RL_LEARNING_ASYNCQNETTRAINER_H_

#include "learning/AsyncTrainer.hpp"

class cAsyncQNetTrainer : public cAsyncTrainer
{
public:

	cAsyncQNetTrainer();
	virtual ~cAsyncQNetTrainer();

protected:

	virtual void BuildTrainer(std::shared_ptr<cNeuralNetTrainer>& out_trainer) const;
};

#endif
