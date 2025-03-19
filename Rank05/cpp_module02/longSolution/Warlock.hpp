#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

using std::string;

class Warlock {

	private :
		string _name;
		string _title;
		SpellBook _SpellBook;
		Warlock & operator=(Warlock const & rhs);
		Warlock(Warlock const & obj);
		Warlock();

	public :
		Warlock(string const &name, string const &title);
		~Warlock();
		string const & getName() const;
		string const & getTitle() const;
		void	setTitle(string const & str);
		void	introduce() const;
		void learnSpell(ASpell* spell);
		void forgetSpell(string SpellName);
		void launchSpell(string SpellName, ATarget const & target);
};
