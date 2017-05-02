#include "clothing.h"

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, 
double price, int qty, const std::string size, const std::string brand) :
    Product(category, name, price, qty),
    size_(size),
    brand_(brand)
{

} 

std::set<std::string> Clothing::keywords() const
{
   std::set<std::string> name_set;
   std::set<std::string> brand_set;
   std::set<std::string> keywords_set;
   
   name_set = parseStringToWords(name_);
   brand_set = parseStringToWords(brand_); 
   keywords_set = setUnion<std::string>(name_set, brand_set);
   
   return keywords_set;

}

std::string Clothing::displayString() const
{  
   std::ostringstream strm1, strm2;
   strm1 << price_;
   string price_str = strm1.str();
   strm2 << qty_;
   string qty_str = strm2.str();

   string display_string = name_ + "\n" + "Size: " + size_ + " Brand: "
   + brand_ + "\n" + price_str + " " + qty_str + " left.";
   
   return display_string;

}

void Clothing::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ <<
    "\n" << size_ << "\n" << brand_ << endl;
}

std::string Clothing::getSize() const
{
   return size_;
}

std::string Clothing::getBrand() const
{
    return brand_;
}




