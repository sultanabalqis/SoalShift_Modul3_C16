#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid1;

int status;

void* faktorial(void *arg){
	status = 0;
	int i;
	int x;
	int fac = 1;

	printf ("./faktorial ");
	scanf ("%d", &x);

	for (i=1; i<=x; i++){
	fac = fac * i;
	}

	printf ("Hasil %d! = %d", x, fac);
	printf ("\n");
	return 0;
}

int main(){

	pthread_create(&(tid1), NULL, &faktorial, NULL);
    	pthread_join(tid1, NULL);
 
      	return 0;
}

