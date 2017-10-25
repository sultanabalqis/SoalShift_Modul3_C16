#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

int hewan[2];
void* lohangabut(void *end){
	while(1){
		sleep(10);
		hewan[0]-=15;
	}
}

void* kepitinggabut(void *end){
	while(1){
		sleep(20);
		hewan[0]-=20;
	}
}

int main(void){
    hewan[0]=100; //lohan
    hewan[1]=100; //kepiting

    pthread_t tid[2];

    pthread_create(&(tid[0]),NULL,&lohangabut,NULL);
    pthread_create(&(tid[1]),NULL,&kepitinggabut,NULL);

    return 0;
}
