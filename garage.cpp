#include <iostream>
#include <bits/stdc++.h>
#define SIZE 10 
#define for(i,a,b) for(i=a;i<b;i++)
using namespace std;
int garage(struct Stack* S,char a,struct car* i);
void push(struct Stack* S,struct car* a);
struct car* pop(struct Stack* S);
struct car{
int License;
int count;
};
struct Stack{
 	unsigned capacity;
 	int top;
 	struct car* A;
 };
int main(){
	struct Stack* S = (struct Stack*)malloc(sizeof(struct Stack));
	struct car* c = (struct car*)malloc(sizeof(struct car));
	int k,temp,i;
	char a;
	S->capacity = SIZE;	
	S->A = (struct car*)malloc(S->capacity*sizeof(struct car));
	while(temp!=-1){
	cin>>temp>>a;
	c->License =temp;
	c->count =0;
	k = garage(S,a,c);
	if(k!=-1){
		cout<<k<<endl;
	}
		
	}
	return 0;
}

 
 bool isEmpty(struct Stack* S){
	//return (s->top==1)? true:false;
	if(S->top==-1)
		return true;
	else{	
		return false;}
}
void push(struct Stack* S,struct car* a){
	if(S->top>SIZE-1)
		cout<<"NO PLACE IN GARAGE"<<endl;
	else{

	S->A[++S->top]=*a;
	cout<<"THE CAR HAS BEEN PARKED"<<endl;
	}
	return;
}
void push1(struct Stack* S,struct car* a){
	if(S->top==SIZE+1)
		return;
	else{

	S->A[++S->top]=*a;
	}
	return;
}
struct car* pop(struct Stack* S){
	if(isEmpty(S))
		return NULL;
	return (&S->A[S->top--]);
}
int garage(struct Stack* S,char a,struct car* i){
struct Stack *S1 = (struct Stack*)malloc(sizeof(struct Stack));
	S1->capacity = SIZE;
	S1->A = (struct car*)malloc(S1->capacity*sizeof(struct car));
	struct car* k = (struct car*)malloc(sizeof(struct car));
	int j=0;
	int m=-1;
	if(a=='A'){
		push(S,i);
	}
	else if(a=='D')
	{	k=pop(S);
		if(k!=NULL){
		while(k->License != i->License){
			k->count++;
			push1(S1,k);
			k = pop(S);
		}
		m = k->count;
		while(!isEmpty(S1)){
			k = pop(S1);
			push1(S,k);	
		}
		}
	}
	return m;
}