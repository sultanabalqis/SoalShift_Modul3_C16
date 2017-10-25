#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid1;
pthread_t tid2;
int status;
FILE *bacaan;
void *cariIfah(void *end){
	bacaan=fopen("/home/nirmalasari/SoalShift_Modul3_C16/Novel.txt","r");
	int count=0;
	char isi[1024];
//	while (fscanf(bacaan,"%s", isi)!=EOF){
	fgets(isi,sizeof(isi),bacaan);
//		if(strstr(isi,"ifah")) count++;
//	}
    	printf("iniIfah %d\n",count);
//	fclose(bacaan);
}
void *cariFina(void *end){
	printf("ini fina\n");
}
int main(){	
    pthread_create(&(tid1), NULL, &cariIfah, NULL);
    pthread_create(&(tid2), NULL, &cariFina, NULL);
 
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
 
    return 0;
}




