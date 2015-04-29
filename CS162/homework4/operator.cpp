/********************************************************************* 
 * ** Program Filename: operator.cpp
 * ** Author: Megan Conley
 * ** Date: 2/1/2014
 * ** Description: Assignment 4, project 1
 * ** Input: n/a
 * ** Output: Manipulates rational numbers using overloaded operators
 * *********************************************************************/ 

#include <iostream>
#include <sstream>

class Rational {

	public:

/********************************************************************* 
 * ** Function: Rational class constructors
 * ** Description: Constructs a rational object
 * ** Parameters: Either none, one, or two. If none, initializes to
 * 0/1. If one, initializes to 0 over user input. If two, initializes
 * to user's input fraction.
 * ** Pre-Conditions: None
 * ** Post-Conditions: Constructs Rational class object
 * *********************************************************************/ 

		Rational() {
			this->num = 0;
			this->den = 1;
		}

		Rational(int den) {
			this->num = 0;
			this->den = den;
		}
		Rational(int num, int den) {
			this->num = num;
			this->den = den;
		}

		~Rational() {};

/********************************************************************* 
 * ** Function: int n and int d
 * ** Description: Accessor functions for the two variables in this class
 * ** Parameters: None
 * ** Pre-Conditions: num and den are set to a value
 * ** Post-Conditions: Returns num or den for access outside class
 * *********************************************************************/ 

		int n() {
			return this->num;
		}

		int n() const {
			return this->num;
		}

                int d() {
                        return this->den;
                }

                int d() const {
                        return this->den;
                }
		
		friend void gcd_calc(Rational &r);
		friend void gcd(Rational &r);
		friend void simplify(Rational &r);
		friend const Rational operator+(const Rational& r, const Rational& l);
		friend std::ostream& operator<<(std::ostream &out, const Rational& r);
		friend std::istream& operator>>(std::istream &in, Rational& r);	
		friend const Rational operator-(const Rational &r, const Rational &l);
		friend const Rational operator/(const Rational &r, const Rational &l);
		friend const Rational operator*(const Rational &r, const Rational &l);

		Rational& operator=(const Rational &r);

	private:
		int num;
		int den;
};

/********************************************************************* 
 * ** Function: operator=
 * ** Description: Overloads equal operator to set two Rational objects
 * equal to each other.
 * ** Parameters: Rational class object (const)
 * ** Pre-Conditions: At least one Rational class object has been
 * initialized.
 * ** Post-Conditions: Rational class object following operator contains
 * same values as one preceding.
 * *********************************************************************/ 

Rational& Rational::operator=(const Rational &r) {
        num = r.num;
        den = r.den;
        return *this;
}

/********************************************************************* 
 * ** Function: void gcd
 * ** Description: Finds the greatest common denominator of a fraction
 * and reduces it.
 * ** Parameters: One Rational class object
 * ** Pre-Conditions: Rational class object has been initialized
 * ** Post-Conditions: Object now contains reduced value
 * *********************************************************************/ 

void gcd_calc(Rational &r) {
	int gcd;

       	for (int i = 1; (i<=r.num && i <=r.den); i++) {
               	if ((r.num % i == 0) && (r.den % i == 0)) {
                       	gcd = i;
                }
       	}

	r.num /= gcd;
	r.den /= gcd;
}

/********************************************************************* 
 * ** Function: void gcd
 * ** Description: Compensates for the inability for gcd_calc to handle
 * negative numbers - turns negative numbers positive for the calculation,
 * then flips them back to negative if needed.
 * ** Parameters: Rational object
 * ** Pre-Conditions: Rational object has been initialized
 * ** Post-Conditions: Rational object is reduced to lowest terms
 * *********************************************************************/ 

void gcd(Rational &r) {

        if (r.num < 0) {
		r.num *= -1;
		gcd_calc(r);
		r.num *= -1;
	} else if (r.den < 0) {
                r.den *= -1;
                gcd_calc(r);
                r.den *= -1;
	} else if ((r.num < 0) && (r.den < 0)) {
                r.num *= -1;
		r.den *= -1;
                gcd_calc(r);
	} else {
		gcd_calc(r);
	}
}


/********************************************************************* 
 * ** Function: void simplify
 * ** Description: Simplifies a rational by reducing it and correcting
 * the values if the input denominator is negative.
 * ** Parameters: Rational class object
 * ** Pre-Conditions: Rational class object exists; gcd function works
 * ** Post-Conditions: Object now containes simplified values
 * *********************************************************************/ 

void simplify(Rational &r) {

	gcd(r);
	if (r.den < 0) {
		r.num *= -1;
		r.den *= -1;
	}
}

/********************************************************************* 
 * ** Function: operator +
 * ** Description: Overloads + operator to add two Rational class objects
 * ** Parameters: Two Rational objects
 * ** Pre-Conditions: Two objects have been initialized
 * ** Post-Conditions: Returns a Rational that is the sum of the two
 * parameters.
 * *********************************************************************/ 

const Rational operator+(const Rational &r, const Rational &l) {
	return Rational(((r.num * l.den) + (l.num * r.den)), (r.den * l.den));
}

/********************************************************************* 
 * ** Function: operator <<
 * ** Description: Overloads operator << to print a Rational object
 * ** Parameters: outstream, Rational object
 * ** Pre-Conditions: Rational object has been initialized
 * ** Post-Conditions: Rational object is printed to console
 * *********************************************************************/ 

std::ostream& operator<<(std::ostream &out, const Rational& r) {
                out << r.num;
                out << "/";
                out << r.den;
                return out;
}

/********************************************************************* 
 * ** Function: operator >>
 * ** Description: Overloads operator >> to initialize a Rational object
 * ** Parameters: instream, Rational object
 * ** Pre-Conditions: Rational object has been declared
 * ** Post-Conditions: Rational object initialized to input values
 * **********************************************************************/ 

std::istream& operator>>(std::istream &in, Rational& r) {
                char c;
                in >> r.num;
                in >> c; // dummy to hold '/' character
                in >> r.den;
                return in;
}

/********************************************************************* 
 * ** Function: operator -
 * ** Description: Overloads operator - to subtract 2 Rational objects
 * ** Parameters: Two Rational objects
 * ** Pre-Conditions: Two Rational objects have been initialized
 * ** Post-Conditions: Returns Rational object that is equal to the
 * difference between the two parameters
 * *********************************************************************/ 

const Rational operator-(const Rational &r, const Rational &l) {
        return Rational(((r.num * l.den) - (l.num * r.den)), (r.den * l.den));
}

/********************************************************************* 
 * ** Function: operator /
 * ** Description: Overloads operator / to divide 2 Rational objects
 * ** Parameters: Two Rational objects
 * ** Pre-Conditions: Two Rational objects have been initialized
 * ** Post-Conditions: Returns Rational object that is the quotient
 * of the two objects
 * *********************************************************************/ 

const Rational operator/(const Rational &r, const Rational &l) {
	return Rational((r.num * l.den), (r.den * l.num));
}

/********************************************************************* 
 * ** Function: operator *
 * ** Description: Overloads operator * to multiply 2 Rational objects
 * ** Parameters: Two Rational objects
 * ** Pre-Conditions: Two objects have been initialized
 * ** Post-Conditions: Returns object that is the product of the
 * two parameters
 * *********************************************************************/ 
 
const Rational operator*(const Rational &r, const Rational &l) {
	return Rational((l.num * r.num), (l.den * r.den));
}

/********************************************************************* 
 * ** Function:
 * ** Description: 
 * ** Parameters: 
 * ** Pre-Conditions: 
 * ** Post-Conditions: 
 * *********************************************************************/ 

void test_add_sub() {

		char ans;

	do {
		Rational test1;
		Rational test2;

		std::cout << "Enter two fractions in the form '#/#':" << std::endl;
		std::cout << "First fraction: ";
		std::cin >> test1;
		std::cout << "Second fraction: ";
		std::cin >> test2;

		std::cout << "Adding fractions " << test1 << " and " << test2 << ":" << std::endl;
		Rational sum = test1 + test2;
		std::cout << "The sum is " << sum << std::endl;
		
		std::cout << "Subtracting fractions " << test1 << " and " << test2 << ":" << std::endl;
		Rational diff = test1 - test2;
                std::cout << "The difference is " << diff << std::endl;

		std::cout << "Do again? (y/n): ";
		std::cin >> ans;
	} while (ans == 'y' || ans == 'Y');
}
		
void test_div_mult() {

                char ans;

        do {
                Rational test1;
                Rational test2;

                std::cout << "Enter two fractions in the form '#/#':" << std::endl;
                std::cout << "First fraction: ";
                std::cin >> test1;
                std::cout << "Second fraction: ";
                std::cin >> test2;

                std::cout << "Multiplying fractions " << test1 << " and " << test2 << ":" << std::endl;
                Rational pro = test1 * test2;
                std::cout << "The sum is " << pro << std::endl;

                std::cout << "Dividing fractions " << test1 << " and " << test2 << ":" << std::endl;
                Rational quo = test1 / test2;
                std::cout << "The sum is " << quo << std::endl;


                std::cout << "Do again? (y/n): ";
                std::cin >> ans;
        } while (ans == 'y' || ans == 'Y');
}
		
void test_simplify() {

                char ans;

        do {
                Rational test1;

                std::cout << "Enter a fraction in the form '#/#' :";
                std::cin >> test1;
		std::cout << test1 << " simplified is : ";
		simplify(test1);
		std::cout << test1 << std::endl;

                std::cout << "Do again? (y/n): ";
                std::cin >> ans;
        } while (ans == 'y' || ans == 'Y');
}

int main() {

//	test_add_sub();
	//test_div_mult();
	test_simplify();

	return 0;
}
