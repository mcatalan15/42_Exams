#include <iostream>

using std::string;

class Warlock {
	private:
		Warlock& operator=(Warlock const &rhs) {
			this->_name = rhs._name;
			this->_title = rhs._title;
			return *this;
		}
		Warlock(Warlock const &obj) { *this = obj; }
		Warlock(){};
		string _name;
		string _title;
	public:
		Warlock(const string& name, const string& title) : _name(name), _title(title) { std::cout << _name << ": This looks like another boring day." << std::endl; }
		~Warlock() { std::cout << _name << ": My job here is done!" << std::endl; }
		string const& getName() const { return _name; }
		string const& getTitle() const { return _title; }
		void setTitle(string const& str) { _title = str; }
		void introduce() const { std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl; }
};
