#include<iostream>
using namespace std ;

int  Duplication(int a[],int size ,int dup[]){
	int k =0;
	for(int i =1;i<size;i++){
		for(int j =0;j<i;j++){
			if(a[j]==a[i]){
				dup[k]=a[i];
				k++;
				break;
			}
		}
		
	}
	return k ;
}


int main(){
	int size ;
	cin>>size;
	int arr[100];
	for(int i =0;i<size;i++){
		cin>>arr[i];
	}
	
	int dup[100];
    int count=Duplication(arr,size,dup);
	cout<<"Duplicate array is  : "<<endl;
	for(int k =0;k<count;k++){
		cout<<dup[k]<<endl;
	}
	
	return 0;
}
