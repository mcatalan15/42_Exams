#pragma once
#include <iostream>
#include "ATarget.hpp"

using std::string;

class ATarget;

class ASpell 
{
	protected :
		string _name;
		string _effects;
	
	public :
		ASpell(string name, string effects);
		ASpell & operator=(ASpell const & rhs);
		ASpell(ASpell const & obj);
		virtual ~ASpell();
		string getName() const;
		string getEffects() const;
		virtual ASpell* clone() const = 0;
		void launch(ATarget const & target) const;
};
