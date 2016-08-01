#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int binary_seq(int prev,int pres,int n);
int main(){
	int n;
	cin>>n;
	cout<<binary_seq(0,0,n-2)+binary_seq(1,0,n-2)+binary_seq(0,1,n-2)<<endl;
	return 0;
}

int binary_seq(int prev,int pres,int n){
	if(n==0)
		return 1;
	else if(prev==0 && pres==1)
		return binary_seq(pres,0,n-1);
	else if(prev ==1 && pres ==1)
		return 0;
	else if(prev ==1 && pres ==0)
		return binary_seq(pres,0,n-1) + binary_seq(pres,1,n-1);
	else if(prev == 0 && pres ==0)
		return binary_seq(prev,1,n-1)+ binary_seq(pres,0,n-1);
}