#ifndef _DEEP_TERRAIN_RL_LEARNING_EXPTUPLE_H_
#define _DEEP_TERRAIN_RL_LEARNING_EXPTUPLE_H_

#include "util/MathUtil.hpp"

struct tExpTuple
{
public:
	static bool TestFlag(unsigned int flag, int idx);

	tExpTuple();
	tExpTuple(int state_size, int action_size);

	virtual void ClearFlags();
	virtual void SetFlag(bool val, int idx);
	virtual bool GetFlag(int idx) const;

	int mID;
	double mReward;
	unsigned int mFlags;
	Eigen::VectorXd mStateBeg;
	Eigen::VectorXd mAction;
	Eigen::VectorXd mStateEnd;
};

#endif
