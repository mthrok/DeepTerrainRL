#include "learning/AsyncCaclaTrainer.hpp"
#include "learning/CaclaTrainer.hpp"

cAsyncCaclaTrainer::cAsyncCaclaTrainer()
{
}

cAsyncCaclaTrainer::~cAsyncCaclaTrainer()
{
}

void cAsyncCaclaTrainer::BuildTrainer(std::shared_ptr<cNeuralNetTrainer>& out_trainer) const
{
	out_trainer = std::shared_ptr<cNeuralNetTrainer>(new cCaclaTrainer());
}
