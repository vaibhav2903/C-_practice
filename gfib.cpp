#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int gfib(int f0,int f1,int n);
int igfib(int f0,int f1,int n);
int main(){
	int f0,f1,n;
	cin>>f0;
	cin>>f1;
	cin>>n;
	cout<<gfib(f0,f1,n)<<endl;
	cout<<igfib(f0,f1,n)<<endl;

	return 0;
}

int gfib(int f0,int f1,int n){
	if(n==0)
		return f0;
	else if(n==1)
		return f1;
	else
		return gfib(f0,f1,n-1)+gfib(f0,f1,n-2);
}

int igfib(int f0,int f1,int n){
	if(n==0)
		return f0;
	else if(n==1)
		return f1;
	else{
	int i,temp,temp1,temp2;
	temp1 = f0;
	temp2 = f1;
	for(i=2;i<=n;i++){
		temp = temp1 +temp2;
		temp1 = temp2;
		temp2 = temp;
	}
	return temp;
	}

}