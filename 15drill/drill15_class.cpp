#include "std_lib_facilities.h"

struct Person {
	private:
		string first_name, second_name;
		int age;
	public:
		string get_first_name() const {return first_name;}
		string get_second_name() const {return second_name;}
		int get_age() const {return age;}
	Person(string first_name="",string second_name="",int age = 0) {
		this->first_name = first_name;
		this->second_name = second_name;
		this->age = age;
		if (age < 0 || age > 150)
		{
			error("Please choose a correct age!(error: age not between 0-150)");
		}
		for (char s : first_name+second_name)
		{
			if (!isalpha(s))
			{
				error("Please choose a correct name! (error: name is not alphabet)");
			}
		}
	}
};

istream& operator>>(istream& is, Person& p)
{
	string first_name;
	string second_name;
	int age;
	
	is >> first_name >> second_name >> age;
	p = Person(first_name, second_name, age);

	return is;
}

ostream& operator<<(ostream& os, Person& p)
{
	return os << "first_name: " << p.get_first_name() << "\nsecond_name: " << p.get_second_name() << "\nage: " << p.get_age() << "\n";
}

int main()
{
	//Person Goofy("Goofy", 63);
	//cout << "Name: " << Goofy.get_name() << "\nAge: " << Goofy.get_age() << "\n";

	vector<Person> v;
	Person p;

	cout << "Define first_name, second_name, age values for a person!" << "\n";
	while (cin >> p)
	{
		v.push_back(p);
	}
	cout << "\n";
	for (Person p : v)
	{
		cout << p;
	}
}