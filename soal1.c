#include<stdio.h>
#include<string.h>

void penjual();
void pembeli();
void pilihmode();
int senjata[6]={0,0,0,0,0,0};int pilihan;

int main(){
	int i,input;
	printf ("===SISTEM INFORMASI KHAWARI STORE===\n\n");
	pilihmode();
}

void pilihmode(){
	printf("PILIH MODE\n");
	printf("1. PENJUAL\n");
	printf("2. PEMBELI\n");
	printf("INPUT: ");

	scanf("%d",&pilihan);
	if(pilihan==1) penjual();
	else pembeli();
}

void penjual(){
	printf("MODE PENJUAL\n");
	printf("1. Lihat Stock Senjata\n");
	printf("2. Tambah Stock Senjata\n");
	printf("3. Ganti Mode\n");
	printf("INPUT: ");
	scanf("%d",&pilihan);
	
	if(pilihan==1){
		printf("cie ngeliat\n");
		penjual();
	}
	else if(pilihan==2){
		printf("cie mo ganti\n");
		penjual();
	}
	else pilihmode();
}

void pembeli(){
	printf("MODE PEMBELI\n");
//return NULL;*/	
}

