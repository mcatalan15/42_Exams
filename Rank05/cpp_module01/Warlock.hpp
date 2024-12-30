#include <map>
#include <iostream>
#include "ASpell.hpp"

using std::string;

class Warlock {
	private:
		Warlock &operator=(Warlock const &rhs);
		Warlock(Warlock const &obj);
		Warlock();
		string _name;
		string _title;
		std::map < string, ASpell * > _SpellBook;
  
	public:
		Warlock(const string &name, const string &title);
		~Warlock();
		string const &getName() const;
		string const &getTitle() const;
		void	setTitle(string const &str);
		void	introduce() const;
		void	learnSpell(ASpell *spell);
		void	forgetSpell(string SpellName);
		void	launchSpell(string SpellName, ATarget const &target);
};
