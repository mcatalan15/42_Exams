#pragma once
#include "ATarget.hpp"
#include <map>

using std::string;

class TargetGenerator {
	private :
		TargetGenerator(TargetGenerator const & src);
		TargetGenerator & operator=(TargetGenerator const & src);
		std::map < string, ATarget*> _target;
	public :
		TargetGenerator();
		~TargetGenerator();
		void learnTargetType(ATarget*);
		void forgetTargetType(string const &);
		ATarget* createTarget(string const &);
};

