#ifndef _DEEP_TERRAIN_RL_SIM_DOGCONTROLLERCACLA_H_
#define _DEEP_TERRAIN_RL_SIM_DOGCONTROLLERCACLA_H_

#include "sim/BaseControllerCacla.hpp"
#include "sim/DogController.hpp"

class cDogControllerCacla : public virtual cDogController, public virtual cBaseControllerCacla
{
public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	cDogControllerCacla();
	virtual ~cDogControllerCacla();

protected:
	virtual void UpdateAction();
	virtual bool IsCurrActionCyclic() const;
};

#endif
