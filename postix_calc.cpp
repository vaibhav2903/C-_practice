#include <iostream>
#include <bits/stdc++.h>
#define MAX 100
using namespace std;
struct Stack{
int capacity;
int  A[MAX];
int top;
};

int main(){
struct Stack* S = (struct Stack*)malloc(sizeof(struct Stack));
S->top =-1;
union{
	int a;
	char k;
}temp;
int i=0;
while(temp!='\0')
{
	cin>>temp;
	S->A[S->top++]=temp;

}
return 0;
}

//postfix_calc(int A)