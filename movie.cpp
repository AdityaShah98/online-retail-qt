#include "movie.h"

using namespace std;

Movie::Movie(const std::string category, const std::string name, double price,
    int qty, const std::string genre, const std::string rating) :
    Product(category, name, price, qty),
    genre_(genre),
    rating_(rating)
{

} 


std::set<std::string> Movie::keywords() const
{
   std::set<std::string> name_set;
   std::set<std::string> genre_set;
   std::set<std::string> keywords_set;
   
   name_set = parseStringToWords(name_);
   genre_set = parseStringToWords(genre_);
   keywords_set = setUnion<std::string>(name_set, genre_set);
   
   return keywords_set;

}

std::string Movie::displayString() const
{
   std::ostringstream strm1, strm2;
   strm1 << price_;
   string price_str = strm1.str();
   strm2 << qty_;
   string qty_str = strm2.str();
   
   string display_string = name_ + "\n" + "Genre: " + genre_ + " Rating: "
   + rating_ + "\n" + price_str + " " + qty_str + " left.";
   
   return display_string;

}

void Movie::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ <<
    "\n" << genre_ << "\n" << rating_ << endl;
}

std::string Movie::getGenre() const
{
    return genre_;
}

std::string Movie::getRating() const
{
    return rating_;
}




