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
        char c;
        int len;
        len = s.length();
        int i = 0;
        int j = 0;
        int last = 0;
        int delcount = 0;
        int wordcount = 0;
        bool isHead = true;
        string new_str;
        //cp to new_str;
        for (int i=0; i < len;i++){
            // skip head spaces;
            if (s[i] == ' ' && isHead){
                continue;
            }
            else if (s[i] != ' '){
                isHead = false;
                new_str += s[i];
            }
            else if(s[i] == ' '){
                if (s[i - 1] != ' ') new_str += s[i];
            }
        }
        cout << "in reverse Words " <<new_str<< endl;
        
        // skip the tail spaces
        int tail = new_str.length() - 1;
        //TODO bug happens here!
        while(new_str[tail] == ' ') tail--;
        new_str.resize(tail + 1);
        
        reverse(new_str,0,tail);
        cout << "in reverse Words " <<new_str<< endl;
        
        //reverse each word
        for(i=0;i<new_str.length();i++){
            if (new_str[i] == ' '){
                reverse(new_str,last,i-1);
                last = i + 1;
            }
        }
        reverse(new_str,last,i-1);
        s  =  new_str;
    }
};


int main(){
Solution s;
string t1 = "  harvey  is  a    pig!  ";
cout << "input is: " << t1 << endl;
s.reverseWords(t1);
cout << "output is " << t1 << endl;
}
