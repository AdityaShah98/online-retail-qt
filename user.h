#ifndef USER_H
#define USER_H
#include <string>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include "product.h"
#include "book.h"
#include "clothing.h"
#include "movie.h"

/**
 * Implements User functionality and information storage
 *  You should not need to derive anything from User at this time
 */
class User {
public:
    User();
    User(std::string name, double balance, int type);
    virtual ~User();

    double getBalance() const;
    std::string getName() const;
    void deductAmount(double amt);
    virtual void dump(std::ostream& os);
    
    //std::vector<Product*> cart_vector;
    //std::queue<Product*> cart_queue;

private:
    std::string name_;
    double balance_;
    int type_;
    
};
#endif
