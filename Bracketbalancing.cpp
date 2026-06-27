#include <iostream>
#include <stack>
#include <string>
using namespace std;

int countRev(string s)
{
    stack<char> st;
    if (s.size() % 2 != 0)
    {
        return -1;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty() || st.top() == ')' || st.top() == ']' || st.top() == '}')
            {
                st.push(s[i]);
            }
            else
            {
                st.pop();
            }
        }
    }
    int ans = 0 , open = 0 , close = 0 ;
    while(!st.empty()){
        if(st.top() == '(' || st.top() == '[' || st.top() == '{'){
            open++;
        }else{
            close++;
        }
        st.pop();
    }
    ans = (open + 1) / 2 + (close + 1) / 2;
    return ans;
}


int main (){
    
    string s ;
    cout<<"Enter the string : ";
    cin>>s;
    int ans = countRev(s);
    if(ans == -1){
        cout<<"Invalid String"<<endl;
    }else{
        cout<<"Minimum number of reversals required : "<<ans<<endl;
    }

    return 0;
}