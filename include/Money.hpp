#include <cstdint>
#include <cmath>
#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>

#define DOLLARS_TO_CENTS 100.0

class Money {

    public: 
        // Explicit constructors to prevent implicit conversion
        explicit Money(int64_t cents) : _amount(cents) {};
        explicit Money(double  dollars) { 
            double rounded_dollars = std::round(dollars * DOLLARS_TO_CENTS);
            _amount = static_cast<int64_t>(rounded_dollars);
        };

        // Static function so that you can use a string to create a Money object
        static Money from_string(std::string str) {

            // Remove $ character
            str.erase( std::remove( str.begin(), str.end(), '$'), str.end() );

            // Find index of the '.' if one exists
            double val = std::stod(str);

            // Convert this double to a int64_t 
            int64_t rounded_val = std::round( val * DOLLARS_TO_CENTS );

            // Define Money object and return it 
            Money m = Money(rounded_val);

            return m;
        }

        // Overload arithmetic operators 
        Money operator+(const Money& rhs) const {
            return Money( this->_amount + rhs.getAmount() );
        }

        Money operator-(const Money& rhs) const {
            return Money( this->_amount - rhs.getAmount() );
        }

        Money operator*(const Money& rhs) const {
            return Money( this->_amount * rhs.getAmount() );
        }

        Money operator/(const Money& rhs) const {
            // Calls constructor that has explicit type double which gets rounded and converted to int64_t
            return Money( static_cast<double>(this->_amount) / static_cast<double>(rhs.getAmount()) );
        }

        Money operator=(const Money& rhs) {
            return Money( this->_amount = rhs.getAmount() );
        }
        
        // Overload logic operators
        bool operator==(const Money& rhs) const {
            return (this->_amount == rhs.getAmount() );
        }

        bool operator!=(const Money& rhs) const {
            return(this->_amount != rhs.getAmount() );
        }

        bool operator<(const Money& rhs) const {
            return (this->_amount < rhs.getAmount() );
        }

        bool operator>(const Money& rhs) const {
            return (this->_amount > rhs.getAmount() );
        }

        bool operator<=(const Money& rhs) const {
            return (this->_amount <= rhs.getAmount() );
        }

        bool operator>=(const Money& rhs) const {
            return (this->_amount >= rhs.getAmount() );
        }

        // Helper function to print out the contents of Money class
        void print(std::ostream& os) const {
            int64_t dollars = this->_amount / 100;
            int64_t cents   = this->_amount % 100;

            os << dollars << "." << cents;
        }
    
        // Getter method for the amount of money
        int64_t getAmount() const {return _amount;}

    protected:
    // Amount of money represented in cents
    int64_t _amount; 


};


// free function that works with iostreams
inline std::ostream& operator<<(std::ostream& os, const Money& m)
{
    m.print(os);
    return os;
}
