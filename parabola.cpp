#include <iostream>
#include <climits>
#include <algorithm>
#include "bits/stdc++.h"
using namespace std;
//Calculating y= Ax^2 +bx+c
double X[1000000],Y[1000000];
double y_val(int a,int b,int c,double x){
	double y=0;
	y = a*x;
	y =y*x;
	y+= b*x +c;
	return y;
}
//Finding nearest point in the input to the local maxima or local minima
int axis_point(double x[],int a,int b, int n){
	b = (-1)*b/(2*a);
	int i = 0;
	while(x[i]<=b && i<n){
		i++;	
	}
	return i;
}


void rev(double *A, int i,int j)
{

	if(j<=i)
		return;
	for(int k=i;k<=(i+j)/2;k++){

		swap(A[k],A[j-k+i]);
	}
}

int main(){
	int a,b,c;
	int i=0;

	cin>>a>>b>>c;
	while(cin>>X[i]){
		Y[i] = y_val(a,b,c,X[i]);
		i++;
	}
	int k = axis_point(X,a,b,i);
	cout<<k<<endl;
	for(int j=0;j<i;j++)	
		cout<<Y[j]<<" ";
	cout<<endl;
	if (a>0)
	{	
		rev(Y,0,k-1);
		std::inplace_merge(Y,Y+k,Y+i);
	}
	else{
		rev(Y,k,i-1);
		std::inplace_merge(Y,Y+k,Y+i);
	}
	for(int j=0;j<i;j++)
		cout<<Y[j]<<" ";
	return 0;
}