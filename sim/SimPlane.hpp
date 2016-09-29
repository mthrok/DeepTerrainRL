#ifndef _DEEP_TERRAIN_RL_SIM_SIMPLANE_H_
#define _DEEP_TERRAIN_RL_SIM_SIMPLANE_H_

#include "sim/SimObj.hpp"

class cSimPlane : public cSimObj
{
public:
	struct tParams
	{
		EIGEN_MAKE_ALIGNED_OPERATOR_NEW

		tParams();

		double mMass;
		double mFriction;
		tVector mOrigin;
		tVector mNormal;
	};

	cSimPlane();
	virtual ~cSimPlane();

	virtual void Init(std::shared_ptr<cWorld> world, const tParams& params);
	virtual tVector GetCoeffs() const;
	virtual eShape GetShape() const;

protected:
};

#endif
