#include <map>
#include <iostream>
#include "ASpell.hpp"

using std::string;

class Warlock
{
private:
	Warlock &operator=(Warlock const &rhs)
	{
		this->_name = rhs._name;
		this->_title = rhs._title;
		return *this;
	}
	Warlock(Warlock const &obj) { *this = obj; }
	Warlock() {};
	string _name;
	string _title;
	std::map<string, ASpell * >_SpellBook;

public:
	Warlock(const string &name, const string &title) : _name(name), _title(title) { std::cout << _name << ": This looks like another boring day." << std::endl; }
	~Warlock() {
		std::cout << _name << ": My job here is done!" << std::endl;
		for (std::map<string, ASpell*>::iterator it = _SpellBook.begin(); it != _SpellBook.end(); ++it)
			delete it->second;
		_SpellBook.clear();
	}
	string const &getName() const { return _name; }
	string const &getTitle() const { return _title; }
	void setTitle(string const &str) { _title = str; }
	void introduce() const { std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl; }
	void learnSpell(ASpell *spell) {
		if (spell)
			if (_SpellBook.find(spell->getName()) == _SpellBook.end())
				_SpellBook[spell->getName()] = spell->clone();
	}
	void forgetSpell(string SpellName) {
		if (_SpellBook.find(SpellName) != _SpellBook.end()) {
			delete _SpellBook[SpellName];
			_SpellBook.erase(_SpellBook.find(SpellName));
		}
	}
	void launchSpell(string SpellName, ATarget const &target) {
		if (_SpellBook.find(SpellName) != _SpellBook.end())
			_SpellBook[SpellName]->launch(target);
	}
};