#ifndef _DEEP_TERRAIN_RL_SIM_GOATCONTROLLERMACE_H_
#define _DEEP_TERRAIN_RL_SIM_GOATCONTROLLERMACE_H_

#include "sim/DogControllerMACE.hpp"

class cGoatControllerMACE : public cDogControllerMACE
{
public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	cGoatControllerMACE();
	virtual ~cGoatControllerMACE();

	virtual tVector GetTargetVel() const;

protected:
};

#endif
