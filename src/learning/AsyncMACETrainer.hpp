#ifndef _DEEP_TERRAIN_RL_LEARNING_ASYNCMACETRAINER_H_
#define _DEEP_TERRAIN_RL_LEARNING_ASYNCMACETRAINER_H_

#include "learning/AsyncTrainer.hpp"

class cAsyncMACETrainer : public cAsyncTrainer
{
public:

	cAsyncMACETrainer();
	virtual ~cAsyncMACETrainer();

	virtual void SetNumActionFrags(int num);
	virtual void SetActionFragSize(int size);

protected:
	int mNumActionFrags;
	int mActionFragSize;

	virtual void BuildTrainer(std::shared_ptr<cNeuralNetTrainer>& out_trainer) const;
	virtual void SetupTrainer(std::shared_ptr<cNeuralNetTrainer>& out_trainer);
};

#endif
