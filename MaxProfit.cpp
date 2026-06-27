#include<iostream>
#include<vector>
using namespace std ;

int maxProfit(vector<int>&prices){
    int minPrice=prices[0];
    int maxProfit=0;
    int n  = prices.size();
    for( int i =1 ; i<n;i++){
        int profit = prices[i] - minPrice;
        maxProfit = max(maxProfit,profit);
        minPrice = min(minPrice,prices[i]);
    }
    return maxProfit;
}

int main(){
    vector<int>prices;
    int n ;
    cout<<"Enter the number of days : ";
    cin>>n;
    for(int i = 0 ;i<n ;i++){
        int x ;
        cout<<"Enter price of stock on "<<i<<"th day : ";
        cin>>x;
        prices.push_back(x);
    }
    cout<<"Maximum profit is : "<<maxProfit(prices)<<endl;
}