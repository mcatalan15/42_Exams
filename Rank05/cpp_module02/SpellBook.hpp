#pragma once
#include "ASpell.hpp"
#include <map>

using std::string;

class SpellBook
{
private:
	SpellBook(SpellBook const &src) { *this = src; }
	SpellBook &operator=(SpellBook const &src)
	{
		_SpellBook = src._SpellBook;
		return *this;
	}
	std::map<string, ASpell *> _SpellBook;

public:
	SpellBook() {}
	~SpellBook()
	{
		for (std::map<string, ASpell *>::iterator it = _SpellBook.begin(); it != _SpellBook.end(); ++it)
			delete it->second;
		_SpellBook.clear();
	}

	void learnSpell(ASpell *spell)
	{
		if (spell && _SpellBook.find(spell->getName()) == _SpellBook.end())
			_SpellBook[spell->getName()] = spell->clone();
	}

	void forgetSpell(string const &SpellName)
	{
		std::map<string, ASpell *>::iterator it = _SpellBook.find(SpellName);
		if (it != _SpellBook.end())
		{
			delete it->second;
			_SpellBook.erase(it);
		}
	}

	ASpell *createSpell(string const &SpellName)
	{
		std::map<string, ASpell *>::iterator it = _SpellBook.find(SpellName);
		if (it != _SpellBook.end())
			return it->second->clone();
		return NULL;
	}
};