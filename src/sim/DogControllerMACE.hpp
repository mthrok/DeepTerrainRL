#ifndef _DEEP_TERRAIN_RL_SIM_DOGCONTROLLERMACE_H_
#define _DEEP_TERRAIN_RL_SIM_DOGCONTROLLERMACE_H_

#include "sim/DogController.hpp"
#include "sim/BaseControllerMACE.hpp"

class cDogControllerMACE : public virtual cDogController, public virtual cBaseControllerMACE
{
public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	cDogControllerMACE();
	virtual ~cDogControllerMACE();

	virtual void Reset();

protected:

	virtual bool IsCurrActionCyclic() const;

	virtual void UpdateAction();
	virtual void BuildBaseAction(int action_id, tAction& out_action) const;
	virtual void ProcessCommand(tAction& out_action);
	virtual int AssignFragID(int a_id) const;

	virtual void BuildActorBias(int a_id, Eigen::VectorXd& out_bias) const;
};

#endif
