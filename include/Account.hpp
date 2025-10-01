#include <string>
#include <vector>
#include "Money.hpp"
#include "Transaction.hpp"

class Account {

    public: 
    virtual ~Account() = default;

    virtual void deposit(Money amount, std::string desc = "");

    virtual void withdraw(Money amount, std::string desc = "") = 0;

    virtual void post_month_end() = 0;

    Money balance() const;

    int id() const; 

    std::string_view name() const;


    protected: 

    void record(Money delta, std::string desc, bool credit);

    private:

    int _id;
    std::string _name; 
    Money _balance; 
    std::vector<Transaction> _history; 

}