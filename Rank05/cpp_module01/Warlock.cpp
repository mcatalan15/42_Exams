#include "Warlock.hpp"

using std::string;

Warlock::Warlock(const string &name, const string &title) : _name(name), _title(title) {
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock() {}

Warlock &Warlock::operator=(Warlock const &rhs) {
	this->_name = rhs._name;
	this->_name = rhs._title;
	return *this;
}

Warlock::Warlock(Warlock const &obj) { *this = obj; }

Warlock::~Warlock() {
 	std::cout << _name <<  ": My job here is done!" << std::endl;
	for (std::map<std::string, ASpell*>::iterator it = _SpellBook.begin(); it != _SpellBook.end(); ++it)
		delete it->second;
	_SpellBook.clear();
} 

string const &Warlock::getName() const { return(_name); }

string const &Warlock::getTitle() const { return(_title); }

void	Warlock::setTitle(string const &str) { _title = str; }

void	Warlock::introduce() const { std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl; }

void Warlock::learnSpell(ASpell *spell)
{
	if (spell)
		if (_SpellBook.find(spell->getName()) == _SpellBook.end())
			_SpellBook[spell->getName()] = spell->clone();
 }

void	Warlock::forgetSpell(string SpellName) {
	if (_SpellBook.find(SpellName) != _SpellBook.end()) {
		delete _SpellBook[SpellName];
		_SpellBook.erase(_SpellBook.find(SpellName));
	}
}

void	Warlock::launchSpell(string SpellName, ATarget const &target) {
	if (_SpellBook.find(SpellName) != _SpellBook.end())
		_SpellBook[SpellName]->launch(target);
}

