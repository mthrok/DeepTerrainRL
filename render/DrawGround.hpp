#ifndef _DEEP_TERRAIN_RL_RENDER_DRAWGROUND_H_
#define _DEEP_TERRAIN_RL_RENDER_DRAWGROUND_H_

#include "sim/Ground.hpp"

class cDrawGround
{
public:
	static void Draw2D(const cGround* ground, const tVector& col, const tVector& bound_min, const tVector& bound_max);
	static void Draw3D(const cGround* ground, const tVector& col, const tVector& bound_min, const tVector& bound_max);

protected:
	static void DrawFlat2D(const cGround* ground, const tVector& col, const tVector& bound_min, const tVector& bound_max);
	static void DrawFlat3D(const cGround* ground, const tVector& col, const tVector& bound_min, const tVector& bound_max);
	static void DrawVar2D(const cGround* ground, const tVector& col, const tVector& bound_min, const tVector& bound_max);
	static void DrawVar3D(const cGround* ground, const tVector& col, const tVector& bound_min, const tVector& bound_max);
};

#endif
