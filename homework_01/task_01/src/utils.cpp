#include "utils.hpp"

#include <stack>
#include <string>
#include <string_view>
#include <vector>

std::vector<std::string> SplitString(const std::string& data){
    std::vector<std::string> slovar;
    std::string word="";
    int skob=0;
    for(char const& simvol: data){
        if (skob==0){
            if (simvol=='('){
                skob=1;
            }else if(simvol!=' ' and simvol!='\t'){
            word.push_back(simvol);
            }else if(simvol==' ' or simvol=='\t'){
                if (!word.empty()){
                    slovar.push_back(word);
                    word.clear();
                    }
                };
        };
        if (skob==1){
            if (simvol!=')'){
            word.push_back(simvol);
            }else if(simvol==')'){
            word.push_back(simvol);
            if (!word.empty()){
                slovar.push_back(word);
                word.clear();
            }
            skob=0;
            };
        };
    };
if (!word.empty()){
slovar.push_back(word);
word.clear();
}
return{slovar};
};