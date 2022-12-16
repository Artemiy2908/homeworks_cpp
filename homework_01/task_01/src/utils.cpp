#include "utils.hpp"

#include <stack>
#include <string>
#include <string_view>
#include <vector>

std::vector<std::string> SplitString(const std::string& data){
    std::vector<std::string> dict;
    std::string word="";
    bool brackets=false;
    for(char const& simvol: data){
        if (!brackets){
            if (simvol=='('){
                brackets=true;
            }else if(simvol!=' ' && simvol!='\t'){
                word.push_back(simvol);
            }else {
                if (!word.empty()){
                    dict.push_back(word);
                    word.clear();
                    }
                }
        }
        if (brackets){
            if (simvol!=')'){
                word.push_back(simvol);
            }else if(simvol==')'){
                word.push_back(simvol);
                if (!word.empty()){
                    dict.push_back(word);
                    word.clear();
                }
            brackets=false;
            }
        }
    }
    if (!word.empty()){
        dict.push_back(word);
        word.clear();
    }
    return{dict};
}
