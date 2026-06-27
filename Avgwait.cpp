#include<iostream>
using namespace std ;

double avgWaitTime(int n , int bt[],int wt[]){
       double totalWaitTime = 0;
       for(int i = 0 ; i < n ; i++){
              totalWaitTime += wt[i];
       }
       return totalWaitTime/n;

}
int main(){
       int n;
       cout << "Enter the number of processes: ";
       cin >> n;
       int bt[n], wt[n];
       cout << "Enter the burst time for each process: ";
       for(int i = 0 ; i < n ; i++){
              cin >> bt[i];
       }
       wt[0] = 0; // waiting time for first process is 0
       for(int i = 1 ; i < n ; i++){
              wt[i] = bt[i-1] + wt[i-1]; // waiting time for each process
       }
       double avgWait = avgWaitTime(n, bt, wt);
       cout << "Average waiting time: " << avgWait << endl;
}