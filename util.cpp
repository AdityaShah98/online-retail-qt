#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
//#include <set>
#include <vector>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
   // unsigned int i = 0;
   set<string> StringSet;
   vector<int> v;
   string t;

   stringstream s;
   s.str(rawWords);
   
   while(s>>t) {
   v.push_back(-1);
   
   for(unsigned int i = 0; i< t.size(); i++)
   {
      //if(rawWords[i] == '.' || rawWords[i] == '\'')
      if(ispunct(t[i]))
      {
         v.push_back(i);
      }
      //i++;
   }
   
   v.push_back(t.size());
   
  for(unsigned int i=0; i<v.size() - 1; i++)
  {
      // string s = rawWords.substr(v[i]+1,v[i+1]-(v[i]+1));
      // s = trim(s);
      // if(s.size() >= 2)
      // {
      //    temp.insert(s);
      // }
    string temp = "";
      if(v[i+1] - v[i] >=3) {
        for(int j = v[i] + 1; j<v[i+1]; j++) {
          temp = temp + t[j];
        }
        if(temp.size() >=2 ) {
          StringSet.insert(convToLower(temp));
        }
      }


   }
   v.clear();
    
 }

   return StringSet;

}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
