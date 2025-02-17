#include <sstream>
#include <iomanip>
#include "product.h"
#include "book.h"
#include "util.h"

using namespace std;

Book::Book(const std::string category, const std::string name, const std::string ISBN, const std::string author, double price, int qty) : 
    Product(category, name, price, qty), 
    ISBN_(ISBN), 
    author_(author)
{

}

Book::~Book()
{

}

std::string Book::getAuthor() const
{

    return author_;

}

std::string Book::getISBN() const
{

    return ISBN_;

}

std::string Book::displayString() const
{

    std::string returnString = "";

    returnString += name_ + "\n";

    returnString += "Author: " + author_ + " ISBN: " + ISBN_ + "\n";

    returnString += std::to_string(price_);
    
    returnString += " ";
    
    returnString += std::to_string(qty_) + " left.";
    
    returnString += "\n";

    return returnString;

}

std::set<std::string> Book::keywords() const
{

    std::set<std::string> initialKeywords;

    initialKeywords = parseStringToWords(getName());

    initialKeywords.insert(getISBN());

    std::set<std::string> authorWordset;

    authorWordset = parseStringToWords(getAuthor());

    std::set<std::string> returnKeywords;
    
    returnKeywords = setUnion(initialKeywords, authorWordset);

    return returnKeywords;

}

void Book::dump(std::ostream& os) const
{

    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << ISBN_ << "\n" << author_ << endl;

}

