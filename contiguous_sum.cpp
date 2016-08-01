#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
int i,A[10],n;
	int n;
	for(i=1;i<n;i++)
		cin>>A[i];

	return 0;
}
int max_contiguous_sum(int A[],int i,int j,int* last){
	if(i==j)
		return A[i];
	else{
		return maxi(max_contiguous_sum(A,i,(i+j)/2),max()
	}

}