#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <climits>
#define for(i,a,b) for(i=a;i<b;i++)
using namespace std;

char findConsecutiveMax(string S);

int main(){
	string S;
	cin>>S;
	cout<<findConsecutiveMax(S)<<endl;
	return 0;
}

char findConsecutiveMax(string S){
	int i,m,l = S.length();
	int maxi=INT_MIN,k=1;
	if(l==1)
		return S[0];
	for(i,1,l){
		if(S[i-1]==S[i])
			k++;
		else{
			if(maxi<k)
				{maxi = k;
					m=i-1;}
			k=1;
				}
				//cout<<k<<endl;
			}
			if(maxi<k)
				{maxi = k;
					m=i-1;}


	return S[m];
}