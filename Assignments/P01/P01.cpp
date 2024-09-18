/*****************************************************************************
*                    
*  Author:           Zachary Barrentine
*  Email:            zlbarrentine0427@my.msutexas.edu
*  Label:            P01
*  Title:            Fraction Class
*  Course:           CMPS 2143
*  Semester:         Fall 2024
* 
*  Description:
*        This program defines a class that processes pairs of fractions from a file
*        and performs various mathematical operations such as addition, subtraction,
*        multiplication, division, and equality comparison. It utilizes overloaded
*        operators in some functions, with many of them computing the least common
*        multiple (LCM) and greatest common divisor (GCD) to ensure that results
*        are returned in their simplest form.
*
*  Usage:
*       - $ ./P01 < input
*       - This will read in a file named "input" containing fractions along with their operative values.
* 
*  Files:            
*       P01.cpp     : driver program 
*       input       : input file with fraction data set
*****************************************************************************/

#include <iostream>
#include <string>

using namespace std;

/**
 * Fraction
 *
 * Description:
 *      This class represents a mathematical fraction and supports basic arithmetic operations
 *      such as addition, subtraction, multiplication, and division. It also supports comparison
 *      for equality. The class uses overloaded operators to perform these operations and provides
 *      methods for accessing the numerator and denominator of the fraction.
 *
 * Public Methods:
 *                           Fraction(int num, int den)
 *                           Fraction()
 *      int                  getDenominator()
 *      int                  getNumerator()
 *      Fraction             operator+(const Fraction& other)
 *      Fraction             operator-(const Fraction& other)
 *      Fraction             operator*(const Fraction& other)
 *      Fraction             operator/(const Fraction& other)
 *      bool                 operator==(Fraction& other)
 *      friend std::ostream& operator<<(std::ostream& os, const Fraction& frac)
 *
 * Private Methods:
 *      int                  gcd(int a, int b)
 *      int                  lcm(int a, int b)
 *
 * Usage (Within Main):
 *
 *      Fraction f1(1, 2);                           // Create a Fraction object with numerator 1 and denominator 2
 *      Fraction f2(3, 4);                           // Create another Fraction object with numerator 3 and denominator 4
 *
 *      Fraction sum = f1 + f2;                      // Add fractions
 *      Fraction diff = f1 - f2;                     // Subtract fractions
 *      Fraction prod = f1 * f2;                     // Multiply fractions
 *      Fraction quot = f1 / f2;                     // Divide fractions
 *      bool equal = (f1 == f2);                     // Compare fractions for equality
 *      
 *      cout << f1 << " + " << f2 << " = " << sum;   // Output the result of addition
 *
 * Notes:
 *      - If the denominator is initialized to 0, it will be adjusted to 1.
 *      - The equality operator compares fractions by adjusting their numerators to a common denominator.
 */

class Fraction {
private:
    int numerator;                                 //numerator is a private integer for storing the numerator of each fraction
    int denominator;                               //denominator is the same idea but for the denominator

/**
*Private : gcd
*
* Description:
*      Computes the Greatest Common Divisor (GCD) of two integers.
*
* Params:
*      int a  : First integer
*      int b  : Second integer
*
* Returns:
*      int   : The GCD of the two integers.
*/
    int gcd(int, int);

/**
* Private : lcm
*
* Description:
*      Computes the Least Common Multiple (LCM) of two integers.
*
* Params:
*      int a  : First integer
*      int b  : Second integer
*
* Returns:
*      int   : The LCM of the two integers.
*/
    int lcm(int, int);

public:

/**
* Public : Fraction (Constructor)
*
* Description:
*      Constructs a Fraction object with the given numerator and denominator.
*      If the denominator is zero, it will be set to one, and a warning message will be displayed.
*
* Params:
*      int num  : Numerator of the fraction
*      int den  : Denominator of the fraction
*/
    Fraction(int num, int den) : numerator(num), denominator(den) {
        if(den == 0)
        {
            cout << "You cannot divide by 0. The denominator will be set to 1.\n";
            denominator = 1;
        }
    }
    
/**
* Public : Fraction (Default Constructor)
*
* Description:
*      Constructs a Fraction object with default values of numerator and denominator set to 1.
*/    
    Fraction(){
        numerator = 1;
        denominator = 1;
    }
    
/**
* Public : getDenominator
*
* Description:
*      Returns the denominator of the fraction.
*
* Returns:
*      int   : The denominator of the fraction.
*/
    int getDenominator(){
        return denominator;
    }

 /**
* Public : getNumerator
*
* Description:
*      Returns the numerator of the fraction.
*
* Returns:
*      int   : The numerator of the fraction.
*/   
     int getNumerator(){
        return numerator;
    }
    
// friend std::ostream& operator<<(std::ostream& os, const Fraction& frac);



/**
* Public : operator+
*
* Description:
*      Adds two Fraction objects and returns the result as a new Fraction object.
*
* Params:
*      const Fraction& other : The fraction to be added to the current fraction.
*
* Returns:
*      Fraction : The result of the addition.
*/
    Fraction operator+(const Fraction& other);

/**
* Public : operator-
*
* Description:
*      Subtracts one Fraction object from another and returns the result as a new Fraction object.
*
* Params:
*      const Fraction& other : The fraction to be subtracted from the current fraction.
*
* Returns:
*      Fraction : The result of the subtraction.
*/
    Fraction operator-(const Fraction& other);

/**
* Public : operator*
*
* Description:
*      Multiplies two Fraction objects and returns the result as a new Fraction object.
*
* Params:
*      const Fraction& other : The fraction to be multiplied with the current fraction.
*
* Returns:
*      Fraction : The result of the multiplication.
*/
    Fraction operator*(const Fraction& other);

/**
* Public : operator/
*
* Description:
*      Divides one Fraction object by another and returns the result as a new Fraction object.
*
* Params:
*      const Fraction& other : The fraction to divide the current fraction by.
*
* Returns:
*      Fraction : The result of the division.
*/
    Fraction operator/(const Fraction& other);
    
/**
* Public : operator==
*
* Description:
*      Compares two Fraction objects for equality.
*
* Params:
*      Fraction& other : The fraction to compare with the current fraction.
*
* Returns:
*      bool   : True if the fractions are equal, false otherwise.
*/
    bool operator==(Fraction& other);

/**
* Public : operator<< (Friend Function)
*
* Description:
*      Overloads the output stream operator to allow printing of Fraction objects.
*
* Params:
*      std::ostream& os : The output stream.
*      const Fraction& frac : The fraction to be printed.
*
* Returns:
*      std::ostream& : The updated output stream.
*/
    friend ostream& operator<<(ostream& os, const Fraction& frac);

};

 // Overloaded addition operator
    Fraction Fraction::operator+(const Fraction& other) {
    int commonDenominator = lcm(denominator, other.denominator);                            //commonDenominator is created to store the result of the lcm of the two denominators as an integer

    int adjustedNumerator1 = numerator * (commonDenominator / denominator);                 //adjustedNumerator1 and AdjustedNumerator2 are created to adjust both fractions to the same denominator
    int adjustedNumerator2 = other.numerator * (commonDenominator / other.denominator);

    int resultNumerator = adjustedNumerator1 + adjustedNumerator2;                          //resultNumerator and resultDenominator are created to hold the full values that will go on to be checked for simplification
    int resultDenominator = commonDenominator;

    int divisor = gcd(resultNumerator, resultDenominator);                                  //divisor is created to call on the gcd and then is used to simplify the result
    resultNumerator /= divisor;
    resultDenominator /= divisor;

    return Fraction(resultNumerator, resultDenominator);
    }

    // Overloaded subtraction operator
    Fraction Fraction::operator-(const Fraction& other) {
    int commonDenominator = lcm(denominator, other.denominator);                            //commonDenominator is created to store the result of the lcm of the two denominators as an integer

    int adjustedNumerator1 = numerator * (commonDenominator / denominator);                 //adjustedNumerator1 and AdjustedNumerator2 are created to adjust both fractions to the same denominator
    int adjustedNumerator2 = other.numerator * (commonDenominator / other.denominator);

    int resultNumerator = adjustedNumerator1 - adjustedNumerator2;                          //resultNumerator and resultDenominator are created to hold the full values that will go on to be checked for simplification
    int resultDenominator = commonDenominator;

    int divisor = gcd(resultNumerator, resultDenominator);                                  //divisor is created to call on the gcd and then is used to simplify the result
    resultNumerator /= divisor;
    resultDenominator /= divisor;

    return Fraction(resultNumerator, resultDenominator);
    }

    // Overloaded multiplication operator
    Fraction Fraction::operator*(const Fraction& other) {
    int resultNumerator = numerator * other.numerator;                                       //resultNumerator is created as an integer that stores the numerators of both fractions multiplied
    
    int resultDenominator = denominator * other.denominator;                                 //resultDenominator is created as an integer that stores the denominators of both fractions multiplied
    
    int divisor = gcd(resultNumerator, resultDenominator);                                   //divisor is created to call on the gcd and then is used to simplify the result
    resultNumerator /= divisor;
    resultDenominator /= divisor;
    
    return Fraction(resultNumerator, resultDenominator);
    }

    // Overloaded division operator
    Fraction Fraction::operator/(const Fraction& other) {
    int resultNumerator = numerator * other.denominator;                                     //resultNumerator is created as an integer that stores the numerators of both fractions multiplied
    
    int resultDenominator = denominator * other.numerator;                                   //resultDenominator is created as an integer that stores the denominators of both fractions multiplied
    
    int divisor = gcd(resultNumerator, resultDenominator);                                   //divisor is created to call on the gcd and then is used to simplify the result
    resultNumerator /= divisor;
    resultDenominator /= divisor;
    
    if (resultDenominator == 0) {
        cout << "Error: Division by zero.\n";
        return Fraction(0, 1);                                                              //returns a default fraction to handle this case
    }
    
    return Fraction(resultNumerator, resultDenominator);
    }

    // Overloaded equality operator (==)
    bool Fraction::operator==(Fraction& other) {

    int commonDenominator = lcm(denominator, other.denominator);                            //commonDenominator finds the least common multiple of both denominators
    
    int adjustedNumerator1 = numerator * (commonDenominator / denominator);                 //adjustedNumerator1 modifies the numerator to the possible common denominator
    int adjustedNumerator2 = other.numerator * (commonDenominator / other.denominator);     //the same logic but for the other numerator inside adjustedNumerator2

    return adjustedNumerator1 == adjustedNumerator2;
    }


    // Overload output operator (<<) for printing fractions
    ostream& operator<<(std::ostream& os, const Fraction& frac) {
        os << frac.numerator << "/" << frac.denominator;
        return os;
    }

    // Function to calculate Greatest Common Divisor (GCD)
    int Fraction::gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
    }

    // Function to calculate Least Common Multiple (LCM)
    int Fraction::lcm(int a, int b) {
    return (a * b) / gcd(a, b);
    }

int main(int argc, char *argv[]) {

        int n1, d1, n2, d2;                     // Four integers are created to allow for the two denominators and two numerators to be read in through the string and then stored
        string s1, op, s2;                      // Three strings are created, two for saving the two fractions as a whole entity, and one for saving and determining the operator being used
        while(cin >> s1 >> op >> s2)
        {
            cout<<s1<<" "<<op<<" "<<s2<<endl;
            n1 = s1[0] - '0';
            d1 = s1[2] - '0';
            n2 = s2[0] - '0';
            d2 = s2[2] - '0';
            Fraction f1(n1, d1);                //f1 is the stored information of the first fraction's numerator and denominator
            Fraction f2(n2, d2);                //f2 is the stored information of the second fraction's numerator and denominator

            if(op == "+"){
                // cout<<"+"<<endl;
                Fraction ans = f1 + f2;         // Fraction 'ans' holds the result of f1 and f2's overloaded addition
                cout << ans << endl;
            }
            else if(op == "-"){
                // cout<<"-"<<endl;
                Fraction ans = f1 - f2;         // Fraction 'ans' holds the result of f1 and f2's overloaded subtraction
                cout << ans << endl;
            }
            else if(op == "*"){
                // cout<<"*"<<endl;
                Fraction ans = f1 * f2;         // Fraction 'ans' holds the result of f1 and f2's overloaded multiplication
                cout << ans << endl;
            }
            else if(op == "/"){
                // cout<<"/"<<endl;
                Fraction ans = f1 / f2;         // Fraction 'ans' holds the result of f1 and f2's overloaded division
                cout << ans << endl;
            }
            else if(op == "=="){
                // cout<<"=="<<endl;
                bool ans = f1 == f2;            // Bool 'ans' holds the result of f1 and f2's overloaded equality check
                if(ans == true){
                    cout << "The fractions are equal. \n";
                }
                else
                    cout << "The fractions are not equal. \n";
                }
            else{
                cout << "Operator not recognized. \n";
            }
        }
    return 0;
}
