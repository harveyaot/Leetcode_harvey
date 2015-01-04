#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    void reverse(string &s,int i, int j){
        while(i<j){
            char c = s[i];
            s[i++] = s[j];
            s[j--] = c; 
        }
    }

    void reverseWords(string &s) {
        int len = s.length();
        int ep = len - 1;
        int sp = len - 1;
        string new_str;
        //cp to new_str;
        for (int i=len - 1; i >= -1;i--){
            if (s[i] == ' ' || i == -1){
                if ( sp != ep ){
                    new_str += s.substr(sp,ep - sp);
                    new_str += ' ';
                }
                sp = ep = i ;
            }
            else {
                sp -- ;
            }
        }
        s  =  new_str.substr(0,new_str.length() - 1);
    }
};


int main(){
Solution s;
string t1 = "    ";
cout << "input is:" << t1 <<"$"<< endl;
s.reverseWords(t1);
cout << "output is:" << t1 <<"$"<< endl;
}
