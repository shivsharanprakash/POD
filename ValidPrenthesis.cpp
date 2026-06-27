#include<iostream>
#include<stack>
using namespace std ;

bool isValid(string s){
    stack<char> st ;

    for(char ch :s){
        if(ch=='('||ch=='['||ch=='{'){
            st.push(ch);
        }else{
            
            if(st.empty()){
                return false ;
            }

            if(ch ==')' && st.top()!='('){
                return false;
            }
            if(ch ==']' && st.top()!='['){
                return false;
            }
            if(ch =='}' && st.top()!='{'){
                return false;
            }
            st.pop();
        }
    }

    return st.empty();

}

int main(){
    string s ;
    cout<<"Enter the string : ";
    cin>>s;
    isValid(s) ? cout<<"Valid Parenthesis"<<endl : cout<<"Invalid Parenthesis"<<endl ;
    return 0 ;
    
}