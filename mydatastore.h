#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <sstream>
#include "datastore.h"
#include "product.h"
#include "util.h"
#include "review.h"


class MyDataStore : public DataStore {
public:
    
    MyDataStore();
    
    ~MyDataStore();
    
    void addProduct(Product* p);
    
    void addUser(User* u);

    void addReview(Review* r);
    
    void setAverage(Product* p);
    
    std::set<User*> get_user_set();
    
    std::set<Review*> get_product_review(Product* p);
    
    std::vector<Product*> get_user_cart(User* u);
    
    std::string display_review(Review* r);
    
    void dump_review(Review* r, std::ostream& os);    

    std::vector<Product*> search
    (std::vector<std::string>& terms, int type);

    void dump(std::ostream& ofile);
    
    //void add_to_cart(User* u, int hit);
    void add_to_cart(std::string u, Product* p);
    
    //void view_cart(User* u);
    void view_cart(std::string u);
    
    //void buy_cart(User* u);
    void buy_cart(std::string u);
    
    void remove_from_cart(std::string u, Product* p);
    

    
private:  
    std::set<Product*> product_set;
    std::set<User*> user_set;  
    std::map<std::string, std::set<Product*> > keywords_map; 
    std::map<std::string, std::vector<Product*> > users_map;
    std::map<std::string, std::set<Review*> > review_map;

};     

#endif
