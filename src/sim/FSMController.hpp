#ifndef _DEEP_TERRAIN_RL_SIM_FSMCONTROLLER_H_
#define _DEEP_TERRAIN_RL_SIM_FSMCONTROLLER_H_

#include "sim/Controller.hpp"

class cFSMController : public cController
{
public:
	virtual ~cFSMController();

	virtual int GetState() const;
	virtual double GetPhase() const;
	virtual void SetPhase(double phase);

protected:
	int mState;
	double mPhase;

	cFSMController();
};

#endif
