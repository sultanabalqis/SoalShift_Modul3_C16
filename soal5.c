#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t ttt[10]; 

void* cari(void *end){
	FILE *baca;
	baca=fopen("/home/dell/SoalShift_Modul3_C16/Novel.txt","r");
    char nama[10],isi[300];
	int htg=0;
	strcpy(nama,end);
	while(fscanf(baca,"%s",isi)!=EOF){
     //  printf("%s ",isi);
		if(strstr(isi,nama)!=NULL) htg++;
	}
	printf("%s  : %d\n",nama,htg);
	fclose(baca);
}


int main(int argc, char *argv[]){
//    for (int i=0;i<argc;i++) printf("%s\n", argv[i]);
	for(int i=1;i<argc;i++) {
        pthread_create(&(ttt[i]), NULL, &cari, (void*)argv[i]);
    }
	for(int i=1;i<argc;i++){
        pthread_join(ttt[i],NULL);
    }
}
