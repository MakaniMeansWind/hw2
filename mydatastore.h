#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include "datastore.h"
#include <map>
#include <utility>
#include "util.h"

class MyDataStore : public DataStore {
public:

    MyDataStore() { }

    ~MyDataStore();

    /**
     * Adds a product to the data store
     */
    void addProduct(Product* p);

    /**
     * Adds a user to the data store
     */
    void addUser(User* u);

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    std::vector<Product*> search(std::vector<std::string>& terms, int type);

    void correlateKeywordsToProduct(Product* p);

    /**
     * Reproduce the database file from the current Products and User values
     */
    void dump(std::ostream& ofile);

    bool addToCart(std::string username, int targetIndex, std::vector<Product*> hits);

    bool viewCart(std::string username);

    bool buyCart(std::string username);

private:

    std::map<std::string, User*> userBase;

    std::set<Product*> productBase;

    std::map<std::string, std::set<Product*>> keywordsToProducts;

    std::map<std::string, std::vector<Product*>> userToCart;

};

#endif
