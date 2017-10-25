#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid1;
pthread_t tid2;
int status;
FILE* novel;
void* cariFina(void *arg){
	//status=0;
	novel= fopen("Novel.txt","r");
	int count=0;
	char isi[1000];
	while(fscanf(novel,"%s",isi) != EOF){
 	   	if(strstr(isi,"fina")!=NULL) count++;
		//status=1;
	}
    	return NULL;
}

void* cariIfah(void *arg){
	//while(status!=1){
	
	//}
	novel= fopen("Novel.txt","r");
	int count=0;
	char isi[1000];
	while(fscanf(novel,"%s",isi) != EOF){
 	   	if(strstr(isi,"ifah")!=NULL) count++;//status=1;
	}
    	printf("iniIfah %d\n",count);
	return NULL;
}
int main(){

	pthread_create(&(tid1), NULL, &cariIfah, NULL);
	pthread_create(&(tid2),NULL, &cariFina,NULL);
    	pthread_join(tid1, NULL);
    	pthread_join(tid2, NULL);
 
    return 0;
}




