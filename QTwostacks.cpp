#include <stdio.h>
#include <bits/stdc++.h>
#define MAX 10000
using namespace std;

struct stack{
	int capacity;
	int top;
	int arr[MAX];
};

int main(){
struct stack* S1 = (struct stack*)malloc(sizeof(struct stack));
struct stack* S2 = (struct stack*)malloc(sizeof(struct stack));;
S1.capacity=10;
S2.capacity = 10;
S1.top =-1;
S2.top = -1;
int arr[10]={0,1,2,3,4,5,6,7,8,9};
return 0;
}

void push(struct stack* S,int val){
	if(S->top+1==S->capacity)
		return;
	else{
		S->arr[++S->top]= val;
	}
}

int  pop(struct stack* S){
	if(S->top==-1)
		return -1;
	else{
		return S->arr[S->top--];
	}
}

void enqueue(struct stack* S1,struct stack* S2){

}
