#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class StockSpanner {
    
    private :
    stack<pair<int,int>> st;
    int index;

    public:
    StockSpanner() {
        index = 0;
    }
    int next (int price){
        while(!st.empty() && st.top().first <=price){
            st.pop();
        }
        int span ;
        if(st.empty()){
            span = index +1;
        }
        else{
            span = index - st.top().second;
        }

        st.push({price,index});
        index++;
        return span;
    }
};

int main (){
     StockSpanner obj;

    cout << obj.next(100) << endl; //1
    cout << obj.next(80) << endl;  //1
    cout << obj.next(60) << endl;  //1
    cout << obj.next(70) << endl;  //2
    cout << obj.next(60) << endl;  //1
    cout << obj.next(75) << endl;  //4
    cout << obj.next(85) << endl;  //6

    return 0;
}