#include<iostream>
using namespace std ;

void Reverse(int a[],int size,int temp[]){
	int j =0;
	for(int i =size-1;i>=0;i--){
		temp[j]=a[i];
		j++;
	}
	
}



int main(){
	int size ;
	cin>>size;
	int arr[100];
	for(int i =0;i<size;i++){
		cin>>arr[i];
	}
	
	int Sort[100];
    Reverse(arr,size,Sort);
	cout<<"Sorted arrray is : "<<endl;
	for(int k =0;k<size;k++){
		cout<<Sort[k]<<endl;
	}
	
	return 0;
}
