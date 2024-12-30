#include <iostream>

using std::string;

class Warlock {

	private :
		Warlock & operator=(Warlock const & rhs);
		Warlock(Warlock const & obj);
		Warlock();
		string _name;
		string _title;
		
	public :

		Warlock(const string& name, const string& title);
		~Warlock();
		string const & getName() const;
		string const & getTitle() const;
		void	setTitle(string const & str);
		void	introduce() const;
};
