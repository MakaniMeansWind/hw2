#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

class Book : public Product {
public:
    Book(const std::string category, const std::string name, const std::string ISBN, const std::string author, double price, int qty);

    ~Book();

    /**
     * Returns the appropriate keywords that this product should be associated with
     */
    std::set<std::string> keywords() const;

    /**
     * Allows for a more detailed search beyond simple keywords
     */
    // bool isMatch(std::vector<std::string>& searchTerms) const;

    /**
     * Returns a string to display the product info for hits of the search
     */
    std::string displayString() const;

    /**
     * Outputs the product info in the database format
     */
    void dump(std::ostream& os) const;

    std::string getAuthor() const;
    
    std::string getISBN() const;


    // /**
    //  * Accessors and mutators
    //  */
    // double getPrice() const;
    // std::string getName() const;
    // int getQty() const;
    // void subtractQty(int num);

protected:
    // std::string name_;
    // double price_;
    // int qty_;
    // std::string category_;

    // Specific to books

    std::string ISBN_;
    std::string author_;

};
#endif
