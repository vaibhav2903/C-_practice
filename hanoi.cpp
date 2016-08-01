#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void hanoitowers(int n,char frompeg,char topeg,char auxpeg);
int main(){
	int n;
	cin>>n;
	hanoitowers(n,'A','C','B');
	return 0;
}
void hanoitowers(int n,char frompeg,char topeg,char auxpeg){
	if(n==1)
		cout<<"Move disk 1 "<<"from "<<frompeg<<" to "<<topeg<<endl;
	else{
		hanoitowers(n-1,frompeg,auxpeg,topeg);
		cout<<"Move disk "<<n<<" from "<<frompeg<<" to "<<topeg<<endl;
		hanoitowers(n-1,auxpeg,topeg,frompeg);
	}
}