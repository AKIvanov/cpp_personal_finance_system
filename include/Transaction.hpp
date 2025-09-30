#include <chrono>
#include <iostream>
#include "Money.hpp"

class Transaction {

    public: 

    Transaction (std::chrono::time_point<std::chrono::system_clock> timestamp,
                 const std::string& description,
                 const Money& initial_amount, 
                 const Money& balance_after,
                 bool credit_or_debit) : _timestamp(timestamp), 
                                        _description(description),
                                        _initial_amount(initial_amount), 
                                        _balance_after(balance_after), 
                                        _credit_or_debit(credit_or_debit) {};

    std::chrono::time_point<std::chrono::system_clock> getTimeStamp() const {
        return _timestamp;
    }
    
    std::string getDescription() const {
        return _description;
    }

    Money getInitialAmount() const {
        return _initial_amount;
    }

    Money getBalanceAfter() const {
        return _balance_after;
    }

    bool getCreditOrDebit() const {
        return _credit_or_debit;
    }

    private:
    std::chrono::time_point<std::chrono::system_clock> _timestamp;
    std::string _description; 
    Money _initial_amount;
    Money _balance_after;
    bool _credit_or_debit; 
    

}