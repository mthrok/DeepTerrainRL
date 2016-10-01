#ifndef _DEEP_TERRAIN_RL_SIM_DOGCONTROLLER_Q_H_
#define _DEEP_TERRAIN_RL_SIM_DOGCONTROLLER_Q_H_

#include "sim/DogController.hpp"
#include "sim/BaseControllerQ.hpp"

class cDogControllerQ : public virtual cDogController, public virtual cBaseControllerQ
{
public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	cDogControllerQ();
	virtual ~cDogControllerQ();

protected:

};

#endif
