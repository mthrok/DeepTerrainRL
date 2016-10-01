#ifndef _DEEP_TERRAIN_RL_RENDER_DRAWOBJ_H_
#define _DEEP_TERRAIN_RL_RENDER_DRAWOBJ_H_

#include "render/DrawUtil.hpp"
#include "util/MathUtil.hpp"
#include "sim/SimBox.hpp"
#include "sim/SimPlane.hpp"
#include "sim/SimCapsule.hpp"

class cDrawObj
{
public:
	static void Draw(const cSimObj* obj, cDrawUtil::eDrawMode draw_mode = cDrawUtil::eDrawSolid);
	static void DrawBox(const cSimBox* box, cDrawUtil::eDrawMode draw_mode = cDrawUtil::eDrawSolid);
	static void DrawPlane(const cSimPlane* plane, double size, cDrawUtil::eDrawMode draw_mode = cDrawUtil::eDrawSolid);
	static void DrawCapsule(const cSimCapsule* cap, cDrawUtil::eDrawMode draw_mode = cDrawUtil::eDrawSolid);
};

#endif
