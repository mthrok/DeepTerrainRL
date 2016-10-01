#ifndef _DEEP_TERRAIN_RL_LEARNING_ASYNCCACLATRAINER_H_
#define _DEEP_TERRAIN_RL_LEARNING_ASYNCCACLATRAINER_H_

#include "learning/AsyncACTrainer.hpp"

class cAsyncCaclaTrainer : public cAsyncACTrainer
{
public:

	cAsyncCaclaTrainer();
	virtual ~cAsyncCaclaTrainer();

protected:

	virtual void BuildTrainer(std::shared_ptr<cNeuralNetTrainer>& out_trainer) const;
};

#endif
