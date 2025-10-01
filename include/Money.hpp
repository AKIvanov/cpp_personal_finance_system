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
        template< typename T, typename = std::enable_if_t<std::is_integral_v<T>> >
        explicit Money(T cents) : _amount(static_cast<int64_t>(cents)) {};
        
        // Static function that returns a Money object that is based on a double 
        static Money from_double(double d) {
            double rounded_dollars = std::round(d * DOLLARS_TO_CENTS);
            
            Money m( static_cast<int64_t>(rounded_dollars) );
            
            return m;
        }

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

        Money operator*(const int& rhs) {
                    int iVal = this->_amount * rhs;
                    return Money( iVal );
                }

        Money operator*(const double& rhs) {
            double dVal = this->_amount * rhs;
            int64_t iVal = this->convertDoubleToInt64_t(dVal);
            return Money( iVal );
        }
        
        Money operator/(const int& rhs) {
            double dVal = this->_amount / rhs; 
            int iVal = std::round(dVal);
            return Money( iVal );
        }

        Money operator/(const double& rhs) {
            int64_t iVal = this->convertDoubleToInt64_t(rhs);
            int64_t iVal2 = this->_amount / iVal; 
            return Money( iVal2 );
        }

        Money& operator=(const Money& rhs) {
            if (this != &rhs) _amount = rhs.getAmount();
            return *this; 
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

        // Helper function to convert a double to int64_t
        int64_t convertDoubleToInt64_t(double d)
        {
            int64_t val = std::round(d * DOLLARS_TO_CENTS);
            return val;
        }

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
