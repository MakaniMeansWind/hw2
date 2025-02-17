#include <sstream>
#include <iomanip>
#include "product.h"
#include "clothing.h"
#include "util.h"

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, const std::string size, const std::string brand, double price, int qty) :
    Product(category, name, price, qty), 
    size_(size), 
    brand_(brand)
{

}

Clothing::~Clothing()
{

}

std::string Clothing::getSize() const
{

    return size_;

}

std::string Clothing::getBrand() const
{

    return brand_;

}

std::string Clothing::displayString() const
{

    std::string returnString = "";

    returnString += name_ + "\n";

    returnString += "Size: " + size_ + " Brand: " + brand_ + "\n";

    returnString += std::to_string(price_);
    
    returnString += " ";
    
    returnString += std::to_string(qty_) + " left.";
    
    returnString += "\n";

    return returnString;

}

std::set<std::string> Clothing::keywords() const
{

    std::set<std::string> initialKeywords;

    initialKeywords = parseStringToWords(getName());

    std::set<std::string> brandWordset;

    brandWordset = parseStringToWords(getBrand());

    std::set<std::string> returnKeywords;
    
    returnKeywords = setUnion(initialKeywords, brandWordset);

    return returnKeywords;

}

void Clothing::dump(std::ostream& os) const
{

    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << endl;

}

