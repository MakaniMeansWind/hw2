#ifndef CLOTHING_H
#define CLOTHING_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

class Clothing : public Product {
public:
    Clothing(const std::string category, const std::string name, const std::string size, const std::string brand, double price, int qty);

    ~Clothing();

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

    std::string getSize() const;
    
    std::string getBrand() const;


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

    // Specific to clothing

    std::string size_;
    std::string brand_;

};
#endif
