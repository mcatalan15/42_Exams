#pragma once
#include <iostream>
#include "ATarget.hpp"

using std::string;

class ATarget;

class ASpell {
	protected:
		string _name;
		string _effects;

	public:
		ASpell(string name, string effects) : _name(name), _effects(effects) {}
		ASpell &operator=(ASpell const &rhs) {
			_name = rhs.getName();
			_effects = rhs.getEffects();
			return *this;
		}
		ASpell (ASpell const &obj) { *this = obj; }
		virtual ~ASpell() {}
		string getName() const { return (_name); }
		string getEffects() const {return _effects; }
		virtual ASpell *clone() const = 0;
		void launch(ATarget const &target) const;
};
