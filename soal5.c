#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>


void *cari(void *end){
	FILE *baca;
	baca=fopen("/home/nirmalasari/SoalShift_Modul3_C16/Novel.txt","r");
	char nama[5],isi[300];
	int htg=0;
	strcpy(nama,end);
	while(fscanf(baca,"%s",isi)){
		if(strstr(isi,nama)) htg++;
	}
	printf("%s %d\n",nama,htg);
	fclose(baca);	
}
int main(){
	char nama[2][10];
	int i=0;
	pthread_t ttt[2];
	while(i<2) {scanf("%s",nama[i]); i++;}
 	i=0;
	while(i<2) {pthread_create(&(ttt[i]), NULL, &cari, (void *)nama[i]);i++;}
	i=0;
	while(i<2){pthread_join(ttt[i],NULL); i++;}

}




