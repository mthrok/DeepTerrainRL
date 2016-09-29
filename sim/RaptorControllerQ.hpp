#ifndef _DEEP_TERRAIN_RL_SIM_RAPTORCONTROLLERQ_H_
#define _DEEP_TERRAIN_RL_SIM_RAPTORCONTROLLERQ_H_

#include "sim/RaptorController.hpp"
#include "sim/BaseControllerQ.hpp"

class cRaptorControllerQ : public virtual cRaptorController, public virtual cBaseControllerQ
{
public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	cRaptorControllerQ();
	virtual ~cRaptorControllerQ();

protected:

};
#endif
