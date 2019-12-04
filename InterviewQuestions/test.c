#include<stdio.h>
#include<stdlib.h>
#include<string.h>

extern int g;
void f2(void);
void f1(void){
	g += 10;
}

void main(){
	
	printf("g %d \n", g);
	f1();
	f2();
	printf("g %d \n", g);
}
void f2(void){
	g++;
}
int g = 10;