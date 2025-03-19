#pragma once
#include <iostream>
#include "ASpell.hpp"

using std::string;

class ASpell;

class ATarget {
	protected:
		string _type;

	public:
		ATarget(string type) : _type(type) {}
		ATarget &operator=(ATarget const &rhs) {
			_type = rhs.getType();
			return *this;
		}
		ATarget(ATarget const &obj) { *this = obj; }
		virtual ~ATarget() {}
		string getType() const { return (_type); }
		virtual ATarget *clone() const = 0;
		void getHitBySpell(ASpell const &spell) const;
};