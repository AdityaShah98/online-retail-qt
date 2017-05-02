#include "mydatastore.h"
#include<sstream>

struct ProdNameSorter {
    bool operator()(Product* p1, Product* p2) {
        return (p1->getName() < p2->getName());
    }
};

MyDataStore::MyDataStore() : DataStore()
{

}

MyDataStore::~MyDataStore()
{
   std::set<Product*>::iterator product_it;
   std::set<User*>::iterator user_it;
   std::map<std::string, std::set<Review*> >::iterator review_map_it;
   std::set<Review*>::iterator review_it;
   
   for(product_it = product_set.begin(); product_it != product_set.end(); 
   ++product_it) {
      delete *product_it;
   }
   
   for(user_it = user_set.begin(); user_it != user_set.end();
    ++user_it) {
      delete *user_it;;
   }
   

   for(review_map_it = review_map.begin(); review_map_it != review_map.end();
   ++review_map_it)
   {
      for(review_it = (review_map_it->second).begin(); review_it != (review_map_it->second).end();
      ++review_it)
      {
         delete *review_it;
      }
   }
   
   
   
}

void MyDataStore::addProduct(Product* p)
{
   product_set.insert(p);
   
   std::set<std::string> set_keywords = p->keywords();
   
   std::set<std::string>::iterator set_it;

   for (set_it = set_keywords.begin(); set_it != set_keywords.end(); 
   ++set_it)
   {      
      keywords_map[*set_it].insert(p);
   }
   
   


}
    
void MyDataStore::addUser(User* u)
{
   user_set.insert(u);
   
   std::vector<Product*> product_set_for_user;
   users_map.insert(std::make_pair(u->getName(), product_set_for_user));
   
   
}
 
void MyDataStore::addReview(Review* r)
{
  if(review_map.find(r->prodName) == review_map.end())
  {

    std::set<Review*> temp;
    temp.insert(r);
    review_map.insert(std::make_pair(r->prodName, temp));

  }

  else
  {

    review_map[r->prodName].insert(r);

  }  

}

void MyDataStore::setAverage(Product* p)
{
   std::string product_name = p->getName();
   std::map<std::string, std::set<Review*> >::iterator it;
   std::set<Review*> review_set;
   for(it=review_map.begin(); it!=review_map.end(); ++it)
   {
      if(product_name == it->first)
      {
         review_set=it->second;
         break;   
      }
   }
   if(review_set.empty())
   {
      return;
   }
   else
   {
      std::set<Review*>::iterator set_it;
      int total=0;
      int count=0;
      for(set_it=review_set.begin(); set_it!=review_set.end(); ++set_it)
      {
         total+=((*set_it)->rating);
         count++;
      }
      double average;
      average=(double)total/count;
      //std::cout<<total<<std::endl;
      //std::cout<<count<<std::endl;
      //std::cout<<average<<std::endl;
      
      p->average_rating=average;
   
   }
  

}

std::set<User*> MyDataStore::get_user_set()
{
   return user_set;
}

std::set<Review*> MyDataStore::get_product_review(Product* p)
{
   std::map<std::string, std::set<Review*> >::iterator it;
   std::set<Review*> temp;
   for(it=review_map.begin();it!=review_map.end();++it)
   {
      if(it->first == p->getName())
      {
         temp = it->second;
      }
   }
   return temp;

}

std::vector<Product*> MyDataStore::get_user_cart(User* u)
{
   std::map<std::string, std::vector<Product*> >::iterator it;
   std::vector<Product*> temp;
   for(it=users_map.begin();it!=users_map.end();++it)
   {
      if(it->first == u->getName())
      {
         temp = it->second;
      }
   }
   return temp;

}

std::string MyDataStore::display_review(Review* r)
{
   std::ostringstream strm;
   strm << r->rating;
   std::string rating_str = strm.str();
   
   std::string temp;
   //temp = r->prodName + "\n" + rating_str + " " + r->username + " " +
   //r->date + " " + r->reviewText;
   temp = "Rating: " + rating_str + " Review: " + r->reviewText + "\n"
   + "By " + r->username + " on " + r->date; 
   
   return temp;
        
}

void MyDataStore::dump_review(Review* r, std::ostream& os)
{

    os << r->prodName << std::endl;
    os << r->rating << " " << r->username << " " << r->date << " " << r->reviewText << std::endl;

}

std::vector<Product*> MyDataStore::search
(std::vector<std::string>& terms, int type) {
   
  
   
   std::set<Product*> result_set;
   std::set<std::set<Product*> > temp;
   std::vector<Product*> result_v;
  
  
   for(unsigned int i = 0; i < terms.size(); i++)
   {
      if(keywords_map.find(terms[i]) != keywords_map.end())
      {
         temp.insert(keywords_map[terms[i]]);

      }
   }
   
   if(temp.size() == 0)
   {
      std::vector<Product*> empty_vec;
      return empty_vec;
   
   }
   
   std::set<std::set<Product*> >::iterator set_of_sets_it;
   set_of_sets_it = temp.begin();   
   
   
   if(type == 0)
   {
      
      std::set<Product*> temp_set;
      temp_set = *set_of_sets_it;
      result_set = setIntersection<Product*>(temp_set, temp_set);
   }
   
   else if(type == 1)
   {
      std::set<Product*> temp_set;
      temp_set = *set_of_sets_it;
      result_set = setUnion<Product*>(temp_set, temp_set);
   }
   
   ++set_of_sets_it;
   

  for(; set_of_sets_it != temp.end(); 
  ++set_of_sets_it) {

      if(type == 0)
      {
         if(temp.size()!=terms.size()) {
            return result_v;
         }

         std::set<Product*> temp_set;
         temp_set = *set_of_sets_it;
        
      }
      
      else if(type == 1){
         std::set<Product*> temp_set;
         temp_set = *set_of_sets_it;
         result_set = setUnion<Product*>(result_set, temp_set);
      }
      
   }
   
   std::set<Product*>::iterator set_it;
   for(set_it = result_set.begin(); set_it != result_set.end(); ++set_it)
   {
      result_v.push_back(*set_it);
   }
   
   return result_v;

}
    
void MyDataStore::dump(std::ostream& ofile)
{  
   std::set<Product*>::iterator set_it;
   
   ofile << "<products>" << "\n";
   for(set_it = product_set.begin(); set_it != product_set.end(); ++set_it)
   {
      (*set_it) -> dump(ofile);
   }
   ofile << "</products>" << "\n";
   
   std::set<User*>::iterator user_it;
   ofile << "<users>" << "\n";
   for(user_it = user_set.begin(); user_it != user_set.end(); ++user_it)
   {
      (*user_it) -> dump(ofile);
   }
   ofile << "</users>" << "\n";

   std::map<std::string, std::set<Review*> >::iterator review_map_it;
   std::set<Review*>::iterator review_it;
   ofile << "<reviews>" << "\n";
   for(review_map_it = review_map.begin(); review_map_it != review_map.end(); ++review_map_it)
   {
      std::set<Review*> temp = review_map_it -> second;
      for(review_it = temp.begin(); review_it != temp.end(); ++review_it)
      {
        dump_review(*review_it, ofile);

      }
   }
   ofile << "</reviews>" << "\n";
   
}

void MyDataStore::add_to_cart(std::string u, Product* p)
{
    if(users_map.find(u) == users_map.end()) {
      std::cout << "User not found." << std::endl;
      return;
   }
   
   else {
      users_map[u].push_back(p);
   }
   
   
}


void MyDataStore::view_cart(std::string u)
{
   //std::sort((u->cart_vector).begin(), (u->cart_vector).end(), 
   //ProdNameSorter());
   
   if(users_map.find(u) == users_map.end()) {
      std::cout << "User not found." << std::endl;
      return;
   }
   
   else if(users_map[u].size() == 0) {
      std::cout << "No products to show for" << u << std::endl; 
      return;
   }
   
   else {
      std::sort(users_map[u].begin(), users_map[u].end(), 
      ProdNameSorter());
      
      for(unsigned int i = 0; i < users_map[u].size() ; i++)
      {
        std::cout << "Item " << i+1 << std::endl;
        std::cout << (users_map[u])[i]->displayString() << std::endl;

      }
      
    return;
    
   }
    
}

void MyDataStore::buy_cart(std::string u) {

   if(users_map.find(u) == users_map.end()) {
      std::cout << "User not found." << std::endl;
      return;
   }
   
   else if(users_map[u].size() == 0) {
      std::cout << "No products to show for " << u << std::endl;
      return; 
   }
   
   else {
      
      User* user_ptr;
      std::set<User*>::iterator set_it;
      bool found = false;
      
      for(set_it = user_set.begin(); set_it != user_set.end(); 
      ++set_it) {     
       
         if((*set_it)->getName() == u) {
            user_ptr = *set_it;
            found = true;
            break;
         }
          
      }
      
      if(found == false)
      {
         return;
      } 
   
      for(unsigned int i = 0; i < users_map[u].size() ; i++)
      {
        double product_price = (users_map[u])[i]->getPrice();
        int product_quantity = (users_map[u])[i]->getQty();
        double user_balance = user_ptr->getBalance();
        
        if(user_balance >= product_price && product_quantity > 0) {
         (users_map[u])[i]->subtractQty(1);
         user_ptr->deductAmount(product_price);
         users_map[u].erase(users_map[u].begin() + i);
         i--;
         
        }

      }
   
   }
   
}

void MyDataStore::remove_from_cart(std::string u, Product* p)
{
    if(users_map.find(u) == users_map.end())
    {
      std::cout << "User not found." << std::endl;
      return;
    }
   
   else
   {
      for(unsigned int i=0; i<users_map[u].size(); i++)
      {
         if((users_map[u])[i]->getName() == p->getName())
         {
            users_map[u].erase(users_map[u].begin() + i);
            break;
         }
      }
   }

}


