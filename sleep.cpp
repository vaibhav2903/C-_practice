#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool A[10];
bool sleep_true(bool A[]){
	int i=0;
	while(i<10){
		if(A[i]==false)
			return false;
		i++;
	}
	return true;
}
void digit_exist(int N){
	int temp = N;
	int t = 0;
	while(temp!=0){
		t = temp%10;
		temp = temp/10;
		if(!A[t])
			A[t] = true;
	}
	//cout<<"DISCO"<<endl;
	return;
}

int main(){
	
	int T,N,i,j,temp;
	cin>>T;
	for(i=0;i<T;i++){
		cin>>N;
		if(N==0)
			{cout<<"Case #"<<i+1<<": ";
			cout<<"INSOMNIA"<<endl;
			}
		else{
		j = 1;
		while(!sleep_true(A)){
			temp = j*N;
			digit_exist(temp);
			j++;
			}
			cout<<"Case #"<<i+1<<": ";
			cout<<temp<<endl;
		}
		std::fill_n(A, 10, 0);
	}
	return 0;
}