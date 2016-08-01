#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int binary_search(int[],int,int);
int main(){
	
	int A[]={1,2,3,4,5,6,7,8,9,10};
	int k,i;
		int B[]={0,1,5,11};
	 for(i=0;i<4;i++){
	 k = binary_search(A,10,B[i]);
	if(k==-1)
		cout<<"Not found"<<endl;
	else{
		cout<<A[k]<<endl;
	}
	}
	return 0;
}
int binary_search(int A[],int n,int k){
	int i;
	int low =0;
	int high=n-1;
	for(i=high;low<high,i>0;i=i/2){
		
		if(k>A[(high+low)/2])
		{
			low =(low+high)/2;
			//cout<<"low = "<<low<<endl;
		}
		else if(k<A[(high+low)/2])
				{high = (low+high)/2;
					//cout<<"high = "<<high<<endl;
				}
		else if(k==A[(high+low)/2])
				//cout<<(high+low)/2<<endl;
				return (high+low)/2;
	}
	return -1;
	}