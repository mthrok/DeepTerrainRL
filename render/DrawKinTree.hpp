#ifndef _DEEP_TERRAIN_RL_RENDER_DRAWKINTREE_H_
#define _DEEP_TERRAIN_RL_RENDER_DRAWKINTREE_H_

#include "anim/KinTree.hpp"
#include <set>

class cDrawKinTree
{
public:
	static void Draw(const Eigen::MatrixXd& joint_desc, const Eigen::VectorXd& pose, double link_width, const tVector& fill_col, const tVector& line_col);
	static void DrawTree(const Eigen::MatrixXd& joint_desc, const Eigen::VectorXd& pose, int joint_id, double link_width, const tVector& fill_col, const tVector& line_col);
};

#endif
