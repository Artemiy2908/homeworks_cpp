#include "utils.hpp"

#include <stack>

using namespace std;

int Calculate(const std::string &data) { 
    string number_1="";
    string number_2="";
    string znak="";
    int int_number_1=0;
    int int_number_2=0;
    int koll_znak=0;
    for (char const& simvol: data){
        if (simvol!='+' && simvol!='-' && simvol!='*' && simvol!='/' && koll_znak==0){
            if(koll_znak==0){
                number_1.push_back(simvol);
            } else{
                number_2.push_back(simvol);
            }
        }else{
            znak.push_back(simvol);
            koll_znak+=1;
        }
    };
    int_number_1=stoi(number_1);
    int_number_2=stoi(number_2);
    if (znak=="+"){
            return {int_number_1+int_number_2};
    };
    if (znak=="-"){
            return {int_number_1-int_number_2};
    };
    if (znak=="*"){
            return {int_number_1*int_number_2};
    };
    if (znak=="/"){
            return {int_number_1/int_number_2};
    };
 };