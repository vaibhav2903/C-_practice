#include <iostream>
#include <bits/stdc++.h>
#define MAX 10
using namespace std;
struct matrix* Minor(struct matrix* mat,int key);
struct Position* search(struct matrix* mat,int key);
int det(struct matrix* mat);
int power(int a ,int b);
struct matrix{
int siz;
int A[MAX][MAX];
};
struct Position{
 		int row;
 		int col;
 };

int main(){
struct matrix* m = (struct matrix*) malloc(sizeof(struct matrix));
//struct matrix* mino = (struct matrix*) malloc(sizeof(struct matrix));
int i,j,key;
cin>>m->siz;
for(i=1;i<=m->siz;i++)
	for(j=1;j<=m->siz;j++)
	 {
	 cin>>m->A[i][j];
	 }
	 //cin>>key;
	// mino = Minor(m,key);
	// for(i=1;i<=mino->siz;i++)
	// 	{for(j=1;j<=mino->siz;j++){
	// 		cout<<mino->A[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// 		}
	 cout<<det(m)<<endl;


return 0;	
}

struct Position* search(struct matrix* mat,int key){
	int i,j;
	struct Position* posi = (struct Position*)malloc(sizeof(struct Position));
	for(i=1;i<=mat->siz;i++)
		for(j=1;j<=mat->siz;j++)
			{if(mat->A[i][j]==key)
				{
					posi->row = i;
					posi->col = j;
					return posi;
				}
			}
} 
struct matrix* Minor(struct matrix* mat,int key){
struct matrix* matr = (struct matrix*)malloc(sizeof(struct matrix));
matr->siz = mat->siz-1;
struct Position *pos= (struct Position*)malloc(sizeof(struct Position));;
pos = search(mat,key);
int i,j,k=1,m=1;
//cout<<pos->row<<" "<< pos->col<<endl;
for(i=1;i<=mat->siz;i++){
	m=1;
	for(j=1;j<=mat->siz;j++){
		if(i==pos->row || j==pos->col)
		{ }
	else{
		matr->A[k][m] = mat->A[i][j];
		m++;
	}
	}
if(i!=pos->row){
	k++;//cout<<endl;
}
}
return matr;
}

int power(int a ,int b){
int i,prod=1;
for(i=0;i<b;i++){
	prod *=a; 
}
return prod;
}
int det(struct matrix* mat){
	if(mat->siz==1)
		return  mat->A[mat->siz][mat->siz];
	else{
		int j,i=1,sum=0;
		for(j=1;i<=mat->siz;i++)
		sum+=pow(-1,i+j)*(mat->A[i][j])*(det(Minor(mat,mat->A[i][j])));
	return sum;
	}
}