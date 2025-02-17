#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

class Movie : public Product {
public:
    Movie(const std::string category, const std::string name, const std::string genre, const std::string rating, double price, int qty);

    ~Movie();

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

    std::string getGenre() const;
    
    std::string getRating() const;


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

    // Specific to movies

    std::string genre_;
    std::string rating_;

};
#endif
