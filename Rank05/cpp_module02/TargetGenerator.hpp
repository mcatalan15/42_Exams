#pragma once
#include "ATarget.hpp"
#include <map>

using std::string;

class TargetGenerator
{
private:
	TargetGenerator(TargetGenerator const &src) { *this = src; }
	TargetGenerator &operator=(TargetGenerator const &src)
	{
		_target = src._target;
		return *this;
	}
	std::map<string, ATarget *> _target;

public:
	TargetGenerator() {}
	~TargetGenerator()
	{
		for (std::map<string, ATarget *>::iterator it = _target.begin(); it != _target.end(); ++it)
			delete it->second;
		_target.clear();
	}

	void learnTargetType(ATarget *target)
	{
		if (target && _target.find(target->getType()) == _target.end())
			_target[target->getType()] = target->clone();
	}

	void forgetTargetType(string const &target)
	{
		std::map<string, ATarget *>::iterator it = _target.find(target);
		if (it != _target.end())
		{
			delete it->second;
			_target.erase(it);
		}
	}

	ATarget *createTarget(string const &target)
	{
		std::map<string, ATarget *>::iterator it = _target.find(target);
		if (it != _target.end())
			return it->second->clone();
		return NULL;
	}
};
