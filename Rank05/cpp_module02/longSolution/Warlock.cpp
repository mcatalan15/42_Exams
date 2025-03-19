#include "Warlock.hpp"

Warlock::Warlock(string const &name, string const &title) : _name(name), _title(title) {
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock() {}

Warlock & Warlock::operator=(Warlock const & rhs) {
	this->_name = rhs._name;
	this->_title = rhs._title;
	return *this;
}

Warlock::Warlock(Warlock const & obj) {	*this = obj; }

Warlock::~Warlock() { std::cout << _name << ": My job here is done!" << std::endl; }

string const & Warlock::getName() const { return (_name); }

string const & Warlock::getTitle() const {return (_title); }

void	Warlock::setTitle(string const & str) { _title = str; }

void	Warlock::introduce() const { std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl; }

void Warlock::learnSpell(ASpell* spell) { _SpellBook.learnSpell(spell); }

void Warlock::forgetSpell(string SpellName) { _SpellBook.forgetSpell(SpellName); }

void Warlock::launchSpell(string SpellName, ATarget const & target) {
	if (_SpellBook.createSpell(SpellName))
		_SpellBook.createSpell(SpellName)->launch(target);
}

