#ifndef _DEEP_TERRAIN_RL_SIM_SIMBOX_H_
#define _DEEP_TERRAIN_RL_SIM_SIMBOX_H_

#include "sim/SimObj.hpp"

class cSimBox : public cSimObj
{
public:
	struct tParams
	{
		EIGEN_MAKE_ALIGNED_OPERATOR_NEW

		tParams();

		eType mType;
		double mMass;
		double mFriction;
		tVector mPos;
		tVector mVel;
		tVector mSize;
		tVector mAxis;
		double mTheta;
	};

	cSimBox();
	virtual ~cSimBox();

	virtual void Init(std::shared_ptr<cWorld> world, const tParams& params);
	tVector GetSize() const;

	virtual eShape GetShape() const;

protected:
};

#endif
