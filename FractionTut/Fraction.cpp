#include <iostream>
using namespace std;

class Fraction
{
private:
	int numerator, denominator;
public:
	Fraction()
	{
		numerator = 1;
		denominator = 1;
	}
	Fraction(int n, int d) //An optional error message 
	{
		numerator = n;
		if (d == 0)
		{
			cout << "ERROR: YOU CANNOT DIVIDE BY ZERO" << endl;
			exit(0); // This will terminate the program if division by 0 is attempted
		}
		else
			denominator = d;
	}

	Fraction Sum(Fraction secondFraction) //Recall [a/b + c/d = (a*d +b*c)/b*d ]
	{
		int n = numerator*secondFraction.denominator + secondFraction.numerator*denominator;
		int d = denominator*secondFraction.denominator;
		return Fraction(n / gcd(n, d), d / gcd(n, d));
	}
	Fraction Difference(Fraction secondFraction) // similar to addition
	{
		int n = numerator*secondFraction.denominator - secondFraction.numerator*denominator;
		int d = denominator*secondFraction.denominator;
		return Fraction(n / gcd(n, d), d / gcd(n, d));
	}
	Fraction Product(Fraction secondFraction) // Recall [a/b * c/d = a*c /b*d ]
	{
		int n = numerator*secondFraction.numerator;
		int d = denominator*secondFraction.denominator;
		return Fraction(n / gcd(n, d), d / gcd(n, d));
	}
	Fraction Division(Fraction secondFraction)
	{
		int n = numerator*secondFraction.denominator;
		int d = denominator*secondFraction.numerator;
		return Fraction(n / gcd(n, d), d / gcd(n, d));
	}

	int gcd(int n, int d)
	{
		int remainder;
		while (d != 0)
		{
			remainder = n % d;
			n = d;
			d = remainder;
		}
		return n;
	}
	void show() // Display method
	{
		cout << numerator << "/" << denominator << endl;
	}
};

int main()
{
	int x, y, w, z;
	cout << "Enter First Fraction :" << endl;
	cin >> x;
	cin >> y;
	cout << x << "/" << y << endl;
	cout << "Enter Second Fraction :" << endl;
	cin >> w;
	cin >> z;
	cout << w << "/" << z << endl;
	cout << "Results:" << endl;
	Fraction a(x, y);
	Fraction b(w, z);
	Fraction Answer;
	cout << "Sum is :" << endl;
	Answer = a.Sum(b);
	Answer.show();
	cout << "Difference is :" << endl;
	Answer = a.Difference(b);
	Answer.show();
	cout << "Product is :" << endl;
	Answer = a.Product(b);
	Answer.show();
	cout << "Division is :" << endl;
	Answer = a.Division(b);
	Answer.show();

}