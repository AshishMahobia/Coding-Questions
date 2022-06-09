#include<bits/stdc++.h>
using namespace std;

unordered_map<char,int> symbols = {{'[',-1},{'(',-2},{'{',-3},{']',1},{')',2},{'}',3}};
 
string isBalanced(string s){
    stack<char> st;
    for(char bracket : s ){            // har ek string ke element ke through jayenge aur char bracket in(:) s
        if(symbols[bracket] < 0){    // ye humari integer value a jayegi jo bracket ke sath associted hai aur ye less than 0 hai mtlb ye opening type ka bracket hai
          st.push(bracket);    // opening type ki bracket ke liye hum bracket ko stack me push kar denge
        }  
        else              // else mtlb bracket closing type ka hai to is case me to hume match karna hoga ki opening jo closing wala hai uske liye opning wala stack me hai ki ni 
        {
           if(st.empty())  return "NO";  // agar humari parentheses balanced ni hai to seedha hi humne NO print kar diya
           char top = st.top();    // agar humara stack khali ni hai to hum top ko lenge aur 
           st.pop();        // aur usko nikal denge
           if(symbols[top] + symbols[bracket] != 0)  // ab iske baad hume ye check karna hai ki jo ye humara top hai uska koi valid closed bracket hai ki ni   
               return "NO";            
        }
    }
   if(st.empty()) return "YES";
   return "NO";

}
   

int main() {
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << isBalanced(s) << endl;
    }
}