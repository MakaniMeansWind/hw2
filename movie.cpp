#include <sstream>
#include <iomanip>
#include "product.h"
#include "movie.h"
#include "util.h"

using namespace std;

Movie::Movie(const std::string category, const std::string name, const std::string genre, const std::string rating, double price, int qty) : 
    Product(category, name, price, qty), 
    genre_(genre), 
    rating_(rating)
{

}

Movie::~Movie()
{

}

std::string Movie::getGenre() const
{

    return genre_;

}

std::string Movie::getRating() const
{

    return rating_;

}

std::string Movie::displayString() const
{

    std::string returnString = "";

    returnString += name_ + "\n";

    returnString += "Genre: " + genre_ + " Rating: " + rating_ + "\n";

    returnString += std::to_string(price_);
    
    returnString += " ";
    
    returnString += std::to_string(qty_) + " left.";
    
    returnString += "\n";

    return returnString;

}

std::set<std::string> Movie::keywords() const
{

    std::set<std::string> returnKeywords;

    returnKeywords = parseStringToWords(getName());

    returnKeywords.insert(convToLower(getGenre()));

    // std::set<std::string> genreWordset;

    // genreWordset = parseStringToWords(getGenre());

    // std::set<std::string> returnKeywords;
    
    // returnKeywords = setIntersection(initialKeywords, genreWordset);

    return returnKeywords;

}

void Movie::dump(std::ostream& os) const
{

    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << endl;

}

