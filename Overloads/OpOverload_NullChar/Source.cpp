//Program that demonstrates 4 operator overloads and shows null character functionality with cin,cout objects.

#include <iostream>
#include <cassert>

using namespace std;

class myOverloads
{
public:
	myOverloads() {

	}
	//copy constructor
	myOverloads(const myOverloads& m) {
		for (size_t i = 0; i < sizeof(mychar) / sizeof(char); i++)
		{
			mychar[i] = m.mychar[i];
		}
	}
	char& operator[](int index) {
		assert(index >= 0 && index < 10);
		return mychar[index];
	}
	void operator=(const myOverloads & m) {
		for (size_t i = 0; i < sizeof(mychar) / sizeof(char); i++)
		{
			mychar[i] = m.mychar[i];
		}
	}
	friend ostream& operator<<(ostream & out, const myOverloads & m) {
		out << m.mychar;
		return out;
	}
	friend istream& operator>>(istream & in, myOverloads & m) {
		in >> m.mychar;
		return in;
	}
private:
	char mychar[10] = { '1' };
};


int main()
{
	myOverloads myA;
	cout << "Input some data: ";
	cin >> myA;	//cin automatically appends a null character to the end of the input
	cout << "Output of stored data: " << myA << endl;
	//subscript operator overload has precedence over assignment overload by order of operations
	cout << "Insert a null-char at 0-9: ";
	int index;
	cin >> index;
	myA[index] = '\0';	//PoC that adding a null character to show that cout reads until it hits null character
	cout << "Modified c-string: " << myA << endl;

	myOverloads myB(myA);	//copy constructor in action
	cout << "myB copied from myA: ";
	cout << myB << endl;

	system("pause");
	return 0;
}