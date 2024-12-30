#include "ASpell.hpp"

using std::string;

ASpell::ASpell(string name, string effects) : _name(name), _effects(effects) {}

ASpell &ASpell::operator=(ASpell const &rhs) {
	_name = rhs.getName();
	_effects = rhs.getEffects();
	return *this;
} 

ASpell::ASpell(ASpell const &obj) { *this = obj; }

ASpell::~ASpell(){}

string ASpell::getName() const { return (_name); }

string ASpell::getEffects() const { return(_effects); }

void ASpell::launch(ATarget const &target) const { target.getHitBySpell(*this); }

