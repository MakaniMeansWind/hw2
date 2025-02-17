#include "mydatastore.h"

using namespace std;

// MyDataStore::MyDataStore()
// {

// }

MyDataStore::~MyDataStore()
{


    std::set<Product*>::iterator productBaseIt;

    for(productBaseIt = productBase.begin(); productBaseIt != productBase.end(); ++productBaseIt)
    {

        delete *productBaseIt;

    }

    std::map<std::string, User*>::iterator userBaseIt;

    for(userBaseIt = userBase.begin(); userBaseIt != userBase.end(); ++userBaseIt)
    {

        delete (*userBaseIt).second;

    }

}

void MyDataStore::addProduct(Product* p)
{

    std::set<Product*>::iterator productBaseIt = productBase.find(p);
    
    if(productBaseIt == productBase.end())
    {

        productBase.insert(p);

        correlateKeywordsToProduct(p);

    }

    return;

}

void MyDataStore::addUser(User* u)
{

    std::map<std::string, User*>::iterator userBaseIt = userBase.find(u->getName());

    if(userBaseIt == userBase.end())
    {

        userBase.insert(std::make_pair(u->getName(), u));

        userToCart.insert(std::make_pair(u->getName(), std::vector<Product*>{}));

    }

    return;

}

void MyDataStore::correlateKeywordsToProduct(Product* p)
{

    std::set<std::string> returnKeywords = p->keywords();

    std::set<std::string>::iterator returnKeywordsIt;

    // std::map<std::string, std::set<Product*>> keywordsToProducts;

    for(returnKeywordsIt = returnKeywords.begin(); returnKeywordsIt != returnKeywords.end(); ++returnKeywordsIt)
    {

        std::map<std::string, std::set<Product*>>::iterator keywordsToProductsIt = keywordsToProducts.find(*returnKeywordsIt);

        if(keywordsToProductsIt == keywordsToProducts.end())
        {

            keywordsToProducts.insert(std::make_pair(*(returnKeywordsIt), std::set<Product*>{p}));

        }

        else
        {

            keywordsToProducts[*(returnKeywordsIt)].insert(p);

        }

    }

}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{

    std::vector<Product*> productHits;

    std::vector<Product*> emptyProductHits;

    if(type != 0 && type != 1)
    {

        return emptyProductHits;

    }

    // AND search! (intersection of results for each term)

    else if(type == 0)
    {

        std::set<Product*> intersectionSet;

        for(int i = 0; i < int(terms.size()); i++)
        {

            std::map<std::string, std::set<Product*>>::iterator keywordsToProductsIt = keywordsToProducts.find(terms[i]);

            // cout << "Terms of I is: " << terms[i] << endl;

            if(keywordsToProductsIt == keywordsToProducts.end())
            {

                // cout << "Returning Empty!" << endl;

                return emptyProductHits;

            }

            else if(keywordsToProductsIt != keywordsToProducts.end())
            {

                if(intersectionSet.empty())
                {

                    intersectionSet = keywordsToProducts[terms[i]];

                }

                else
                {

                    intersectionSet = setIntersection(keywordsToProducts[terms[i]], intersectionSet);

                }
            
            }

        }

        std::set<Product*>::iterator intersectionSetIt;

        for(intersectionSetIt = intersectionSet.begin(); intersectionSetIt != intersectionSet.end(); ++intersectionSetIt)
        {

            productHits.push_back(*intersectionSetIt);

        }

    }

    // OR search! (union of results for each term)

    else if(type == 1)
    {

        std::set<Product*> unionSet;

        for(int i = 0; i < int(terms.size()); i++)
        {

            std::map<std::string, std::set<Product*>>::iterator keywordsToProductsIt = keywordsToProducts.find(terms[i]);

            if(keywordsToProductsIt != keywordsToProducts.end())
            {

                unionSet = setUnion(keywordsToProducts[terms[i]], unionSet);

            }

        }

        std::set<Product*>::iterator unionSetIt;

        for(unionSetIt = unionSet.begin(); unionSetIt != unionSet.end(); ++unionSetIt)
        {

            productHits.push_back(*unionSetIt);

        }

    }

    return productHits;

}

void MyDataStore::dump(std::ostream& ofile)
{

    std::set<Product*>::iterator productBaseIt;

    std::map<std::string, User*>::iterator userBaseIt;
 
    ofile << "<products>" << "\n";

    for(productBaseIt = productBase.begin(); productBaseIt != productBase.end(); ++productBaseIt)
    {

        (*productBaseIt)->dump(ofile);

    }

    ofile << "</products>" << "\n";

    ofile << "<users>" << "\n";

    for(userBaseIt = userBase.begin(); userBaseIt != userBase.end(); ++userBaseIt)
    {

        (*userBaseIt).second->dump(ofile);

    }

    ofile << "</users>" << "\n";

    return;

}

bool MyDataStore::addToCart(std::string username, int targetIndex, std::vector<Product*> hits)
{

    std::map<std::string, std::vector<Product*>>::iterator userToCartIt = userToCart.find(username);

    if(userToCartIt != userToCart.end() && targetIndex - 1 < int(hits.size()))
    {

        userToCart[username].push_back(hits[targetIndex - 1]);

        return true;

    }

    return false;

}

bool MyDataStore::viewCart(std::string username)
{

    std::map<std::string, std::vector<Product*>>::iterator userToCartIt = userToCart.find(username);

    if(userToCartIt != userToCart.end())
    {

        std::vector<Product*> targetUserCart = userToCart[username];

        for(int i = 0; i < int(targetUserCart.size()); i++)
        {

            cout << "Item: " << i + 1 << " Item Name: " << targetUserCart[i]->getName() << endl;

            cout << targetUserCart[i]->displayString();

        }

        return true;

    }

    return false;
}

bool MyDataStore::buyCart(std::string username)
{

    std::map<std::string, std::vector<Product*>>::iterator userToCartIt = userToCart.find(username);

    std::map<std::string, User*>::iterator targetUser = userBase.find(username);

    if(userToCartIt != userToCart.end() && targetUser != userBase.end())
    {

        // std::vector<Product*> targetUserCart = userToCart[username];

        for(int i = 0; i < int(userToCart[username].size()); i++)
        {

            if(userToCart[username][i]->getPrice() <= (*targetUser).second->getBalance())
            {

                cout << (*targetUser).first << " has a balance of: " << (*targetUser).second->getBalance() << endl;

                if(userToCart[username][i]->getQty() > 0)
                {

                    cout << (*targetUser).first << "is buying a product!" << endl;

                    userToCart[username][i]->subtractQty(1);

                    (*targetUser).second->deductAmount(userToCart[username][i]->getPrice());

                    cout << (*targetUser).first << " NOW has a balance of: " << (*targetUser).second->getBalance() << endl;

                    userToCart[username].erase(userToCart[username].begin() + i);

                    i--;

                }

            }

        }

        return true;

    }
    
    return false;

}
