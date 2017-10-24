#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
pthread_t tid1,tid2;
 
void* cariFina(void *arg){
    	printf("cie masuk ke fungsi ");
    	return NULL;
}

void* cariIfah(void *arg){
	printf("cie cie");
	return NULL;
}
int main(){

	pthread_create(&(tid1), NULL, &cariFina, NULL);
	pthread_create(&(tid2),NULL, &cariIfah,NULL);
    	pthread_join(tid1, NULL);
    	pthread_join(tid2, NULL);
 
    return 0;
}




