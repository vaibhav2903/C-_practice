//VAIBHAV SAVALA 

#include <iostream>
#include <climits>
#include <algorithm>
#include "bits/stdc++.h"
using namespace std;


pair<double,double> points[1000000];
//Calculating y= ax^2 +bx+c
double y_val(int a,int b,int c,double x){
	double y=0;
	y = a*x;
	y =y*x;
	y+= b*x +c;
	return y;
}
//Finding nearest point x index in the input greater than the the local maxima or local minima 
int axis_point(pair<double,double> x[],int a,int b, int n){
	b = (-1)*b/(2*a);
	int i = 0;
	while(x[i].first<=b && i<n){
		i++;	
	}
	return i;
}

//Reversing an array of pairs
void rev(pair<double,double> *A, int i,int j)
{

	if(j<=i)
		return;
	for(int k=i;k<=(i+j)/2;k++){

		swap(A[k],A[j-k+i]);
	}
}
// We compare two pairs based on the second value as we have to sort in order based on the y value.
int comp(pair<double,double> a,pair<double,double> b)
{
	if(a.second<=b.second)
		return true;
	return false;
}
int main(){
	int a,b,c;
	int i=0;
	cin>>a>>b>>c;
	while(cin.peek()!='\n'){
		cin>>points[i].first;
		points[i].second = y_val(a,b,c,points[i].first);
		i++;
	}
	int k = axis_point(points,a,b,i);
	if (a>0)
	{	
		rev(points,0,k-1);
		std::inplace_merge(points,points+k,points+i,comp); //Merge has a time complexity of O(n)
	}
	else{
		rev(points,k,i-1);
		std::inplace_merge(points,points+k,points+i,comp);
	}
	for(int j=0;j<i;j++)
		cout<<points[j].first<<","<<points[j].second<<" ";
	cout<<endl;
	return 0;
}