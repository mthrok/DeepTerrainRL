#include "learning/AsyncQNetTrainer.hpp"
#include "learning/QNetTrainer.hpp"

cAsyncQNetTrainer::cAsyncQNetTrainer()
{
}

cAsyncQNetTrainer::~cAsyncQNetTrainer()
{
}

void cAsyncQNetTrainer::BuildTrainer(std::shared_ptr<cNeuralNetTrainer>& out_trainer) const
{
	out_trainer = std::shared_ptr<cNeuralNetTrainer>(new cQNetTrainer());
}
