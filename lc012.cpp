#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string res;
    string intToRoman(int num) {
        while(num){
            if(num/1000){
                num-=1000;
                res.append("M");
                continue;
            }
            if(num/900){
                num-=900;
                res.append("CM");
                continue;
            }
            if(num/500){
                num-=500;
                res.append("D");
                continue;
            }
            if(num/400){
                num-=400;
                res.append("CD");
                continue;
            }
            if(num/100){
                num-=100;
                res.append("C");
                continue;
            }
            if(num/90){
                num-=90;
                res.append("XC");
                continue;
            }
            if(num/50){
                num-=50;
                res.append("L");
                continue;
            }
            if(num/40){
                num-=40;
                res.append("XL");
                continue;
            }
            if(num/10){
                num-=10;
                res.append("X");
                continue;
            }
            if(num/9){
                num-=9;
                res.append("IX");
                continue;
            }
            if(num/5){
                num-=5;
                res.append("V");
                continue;
            }
            if(num/4){
                num-=4;
                res.append("IV");
                continue;
            }
            if(num/1){
                num-=1;
                res.append("I");
                continue;
            }
        }
        return res;
    }
};

int main(){
    int num = 58;
    Solution so;
    cout<<so.intToRoman(num);
}