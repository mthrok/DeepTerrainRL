#ifndef _DEEP_TERRAIN_RL_SIM_RAPTORCONTROLLERCACLA_H_
#define _DEEP_TERRAIN_RL_SIM_RAPTORCONTROLLERCACLA_H_

#include "sim/BaseControllerCacla.hpp"
#include "sim/RaptorController.hpp"

class cRaptorControllerCacla : public virtual cRaptorController, public virtual cBaseControllerCacla
{
public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	cRaptorControllerCacla();
	virtual ~cRaptorControllerCacla();

protected:
	virtual void UpdateAction();
	virtual bool IsCurrActionCyclic() const;
};

#endif
