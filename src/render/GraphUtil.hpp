#ifndef _DEEP_TERRAIN_RL_RENDER_GRAPHUTIL_H_
#define _DEEP_TERRAIN_RL_RENDER_GRAPHUTIL_H_

#include "render/DrawUtil.hpp"

class cGraphUtil
{
public:
	struct tBarPlot
	{
		double mMinVal;
		double mMaxVal;
		double mBaseVal;
		Eigen::VectorXd mVals;
		tVectorArr mColors;

		tBarPlot();
	};

	static void DrawBarPlot(const tBarPlot& bar_plot, const tVector& pos, const tVector& size);
};

#endif
