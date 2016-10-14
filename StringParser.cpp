#include "StringParser.h"


 std::vector<std::string>& StringParser::getResult(){
     size_t size = d_str.size();
     std::string str_temp;
     for(size_t i=0; i!=size; ++i){
        char c = d_str[i];
        if(d_delimiters.find(c)!=d_delimiters.end()||i==size-1){
            //this is a delimiter;
            if(str_temp.size()!=0){
                d_result.push_back(str_temp);
                str_temp = "";
            }
        } else {
            //this is not a delimiter
            str_temp.push_back(c);
        }
     }
     return d_result;
 }
