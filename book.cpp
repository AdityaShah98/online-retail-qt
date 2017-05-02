#include "book.h"

using namespace std;

Book::Book(const std::string category, const std::string name, double price,
    int qty, const std::string ISBN, const std::string author) :
    Product(category, name, price, qty),
    ISBN_(ISBN),
    author_(author)
    
{
  
} 


std::set<std::string> Book::keywords() const
{
   std::set<std::string> name_set;
   std::set<std::string> author_set;
   std::set<std::string> keywords_set;
   
   name_set = parseStringToWords(name_);
   author_set = parseStringToWords(author_);
   keywords_set = setUnion<std::string>
   (name_set, author_set);
   keywords_set.insert(ISBN_);
   
   return keywords_set;

}

std::string Book::displayString() const
{
   std::ostringstream strm1, strm2;
   strm1 << price_;
   string price_str = strm1.str();
   strm2 << qty_;
   string qty_str = strm2.str();
   
   std::string display_string = name_ + "\n" + "Author: " + author_ + 
   " ISBN: " + ISBN_ + "\n" + price_str + " " + qty_str + " left.";
   
   return display_string;

}

void Book::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ <<
    "\n" << ISBN_ << "\n" << author_ << endl;
}

std::string Book::getISBN() const
{
    return ISBN_;
}

std::string Book::getAuthor() const
{
    return author_;
}




