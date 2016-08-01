#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void swap(int* a, int* b);
int partition(int A[],int start,int end);
int kth_smallest(int A[],int start,int end,int k);
int n=8;
int main(){
	int A[10],n,k,i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>A[i];
	cin>>k;
	//int A[] = {0,25,6,7,15,12,51,4,2};
	//cout<<rand()<<endl;
	//for(int i=1;i<=n;i++)
	//cout<<partition(A,1,8)<<endl;
	
	//cout<<"the array is"<<endl;	
	//	for(int i=1;i<=n;i++)
	//		cout<<A[i]<<endl;
	//cout<<"the array ends"<<endl;
	//for(int j=1;j<=8;j++)
	cout<<kth_smallest(A,1,n,k)<<endl;
	return 0;
}

void swap(int* a, int* b){
	int temp;
	temp =*a;
	*a = *b;
	*b = temp; 
}

int partition(int A[],int start,int end){
//int k= start+(rand()%(end-start+1));
//cout<<k<<endl;
int p = A[start];
//cout<<"t"<<endl;
int i=start+1,j=end;
	while(i<=j){
		if(p>A[j] && p<=A[i])
			{swap((A+i),(A+j));
				//cout<<"t"<<endl;
			i++;j--;}
		else if(p>A[j])
			{i++;
			//cout<<"t"<<endl;
			}
		else if(p<=A[i])
			{j--;
				//cout<<"t"<<endl;
			}
		else if(p<=A[j] && p>A[i]){
			i++;j--;
		}
	}
	swap((A+start),(A+j));
	//for(i=1;i<=8;i++)
	//	cout<<A[i]<<" ";
	//cout<<endl;
return j;
}

int kth_smallest(int A[],int start,int end,int k){
	int m= partition(A,start,end);
	//cout<<m<<endl;
		if(m==k)
		return A[k];
	else if(m<k)
		return kth_smallest(A,m+1,end,k);
	else if(m>k)
		return kth_smallest(A,start,m-1,k);
}

