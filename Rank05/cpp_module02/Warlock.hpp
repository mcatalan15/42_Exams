#include <map>
#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

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
	SpellBook _SpellBook;

public:
	Warlock(const string &name, const string &title) : _name(name), _title(title)
	{
		std::cout << _name << ": This looks like another boring day." << std::endl;
	}
	~Warlock()
	{
		std::cout << _name << ": My job here is done!" << std::endl;
	}
	string const &getName() const { return _name; }
	string const &getTitle() const { return _title; }
	void setTitle(string const &str) { _title = str; }
	void introduce() const
	{
		std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
	}
	void learnSpell(ASpell *spell) { _SpellBook.learnSpell(spell); }
	void forgetSpell(string SpellName) { _SpellBook.forgetSpell(SpellName); }
	void launchSpell(string SpellName, ATarget const &target)
	{
		ASpell *spell = _SpellBook.createSpell(SpellName);
		if (spell)
		{
			spell->launch(target);
			delete spell; // Clean up the cloned spell
		}
	}
};