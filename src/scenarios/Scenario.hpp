#ifndef _DEEP_TERRAIN_RL_SCENARIOS_SCENARIO_H_
#define _DEEP_TERRAIN_RL_SCENARIOS_SCENARIO_H_

#include <string>
#include <functional>
#include "util/ArgParser.hpp"

class cScenario
{
public:
	typedef std::function<void()> tCallbackFunc;
	typedef std::function<void(double)> tTimeCallbackFunc;

	virtual ~cScenario();

	virtual void Init();
	virtual void ParseArgs(const cArgParser& parser);
	virtual void Reset();
	virtual void Clear();
	virtual void Run();
	virtual void Shutdown();

	virtual bool IsDone() const;
	virtual void Update(double time_elapsed);
	virtual void SetResetCallback(tCallbackFunc func);

	virtual std::string GetName() const;

protected:
	tCallbackFunc mResetCallback;

	cScenario();
};

#endif
