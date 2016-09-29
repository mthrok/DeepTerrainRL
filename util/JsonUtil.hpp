#ifndef _DEEP_TERRAIN_RL_UTIL_JSONUTIL_H_
#define _DEEP_TERRAIN_RL_UTIL_JSONUTIL_H_

#include <string>
#include <json/json.h>
#include "util/MathUtil.hpp"

class cJsonUtil
{
public:
	static std::string BuildVectorJson(const Eigen::VectorXd& vec);
	static bool ReadVectorJson(const Json::Value& root, Eigen::VectorXd& out_vec);

private:

};

#endif
