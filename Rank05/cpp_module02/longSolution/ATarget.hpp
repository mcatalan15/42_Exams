#pragma once
#include <iostream>
#include "ASpell.hpp"

using std::string;

class ASpell;

class ATarget {
	protected :
		string _type;
	
	public :
		ATarget(string type);
		ATarget & operator=(ATarget const & rhs);
		ATarget(ATarget const & obj);
		virtual ~ATarget();
		string getType() const;
		virtual ATarget* clone() const = 0;
		void	getHitBySpell(ASpell const & spell) const;
};

