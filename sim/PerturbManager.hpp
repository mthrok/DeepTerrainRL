#ifndef _DEEP_TERRAIN_RL_SIM_PERTURBMANAGER_H_
#define _DEEP_TERRAIN_RL_SIM_PERTURBMANAGER_H_

#include <memory>
#include "sim/Perturb.hpp"

class cPerturbManager
{
public:
	cPerturbManager();
	virtual ~cPerturbManager();

	virtual void Update(double time_step);
	virtual void Clear();
	virtual void AddPerturb(const tPerturb& perturb);

	virtual int GetNumPerturbs() const;
	virtual const tPerturb& GetPerturb(int i) const;

protected:
	std::vector<tPerturb, Eigen::aligned_allocator<tPerturb>> mPerturbs;

	virtual void UpdatePerturbs(double time_step);
};

#endif
