#pragma once
#include "ASpell.hpp"
#include <map>

using std::string;

class SpellBook {
	private :
		SpellBook(SpellBook const & src);
		SpellBook & operator=(SpellBook const & src);
		std::map < string, ASpell*> _SpellBook;
	public :
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell*);
		void forgetSpell(string const &);
		ASpell* createSpell(string const &);
};

