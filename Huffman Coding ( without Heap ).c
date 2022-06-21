#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void swapFonksiyonu(int* xp, int* yp);
void bubbleSort(int dizi[SIZE] , int diziBoyut);
void bubbleSortHarf(int dizi[SIZE] , int Harfler[SIZE] , int diziBoyut);
int frekansBul(char karakterDizisi[SIZE] , int frekansDizi[SIZE] );
int countBul(int frekansDizi[SIZE] , int diziBoyut);
int frekansSirala(int frekansDizi[SIZE] , int siraliFrekans[SIZE] , int Harfler[SIZE] , int diziBoyut);
int frekansYazdir(int frekansDizi[SIZE]);
void agacOlusturma(int frekansDizi[SIZE] , int Harfler[SIZE] , int diziBoyut);
void kodYazdir(int karakterUzunluk , char karakterDizisi[SIZE]);
void diziSifirla(char dizi[SIZE]);
void koddanKarakter(char kodDizisi[SIZE] , int uzunlukDizi);

int main() {
	int frekansArr[SIZE]={0};
	int siraliFrekans[SIZE]={0};
	int Harfler[SIZE];
	char charArr[SIZE] , charKod[SIZE];
	int diziBoyut;
	int uzunluk1 , uzunluk2;
	printf("Karakter Dizisini Giriniz:  ");
	scanf("%[^\n]s",&charArr);
	uzunluk1 = strlen(charArr);
	frekansBul(charArr,frekansArr);
	frekansYazdir(frekansArr);
	printf("\n\n");
	diziBoyut = countBul(frekansArr,26);
	frekansSirala(frekansArr,siraliFrekans,Harfler,26);
//	printf("Count = %d",diziBoyut);
	printf("\nDevam Etmek Icin Enter'a Basiniz...");
	getch();
	printf("\n\n-------------------\n");
	agacOlusturma(siraliFrekans,Harfler,diziBoyut);
	printf("Karakter Dizisinin Donusturulmus Hali :\n\n");
	kodYazdir(uzunluk1,charArr);
	printf("\n\nDevam Etmek Icin Enter'a Basiniz...");
	getch();
	system("cls");
	printf("\n\nKarakter Dizisini Bulmak Istediginiz Kodu Giriniz : \n");
	scanf("%s",&charKod);
//	printf("%s",charKod);
	printf("\n\n");
	uzunluk2 = strlen(charKod);
	koddanKarakter(charKod , uzunluk2);
	
	
	return 0;
}
void swapFonksiyonu(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int dizi[SIZE] , int diziBoyut){
	int i,j;
	
	for(i=0 ; i<diziBoyut-1 ;i++){
		for(j=0 ; j<diziBoyut-1 ; j++){
			if(dizi[j] > dizi[j+1]){
				swapFonksiyonu(&dizi[j],&dizi[j+1]);
			}
		}
	}
}
void bubbleSortHarf(int dizi[SIZE] , int Harfler[SIZE] , int diziBoyut){
	int i,j;
	
	for(i=0 ; i<diziBoyut-1 ;i++){
		for(j=0 ; j<diziBoyut-1 ; j++){
			if(dizi[j] > dizi[j+1]){
				swapFonksiyonu(&dizi[j],&dizi[j+1]);
				swapFonksiyonu(&Harfler[j],&Harfler[j+1]);
			}
		}
	}
}
int frekansBul(char karakterDizisi[SIZE] , int frekansDizi[SIZE] ){
	
	int i,temp;
	i=0;
	while(karakterDizisi[i] != '\0'){
		if((karakterDizisi[i] >= 97) && (karakterDizisi[i] <= 122)){
			temp = karakterDizisi[i] - 97;
			frekansDizi[temp]++;
		}
		else if(karakterDizisi[i] == 32){
			frekansDizi[26]++;
		}
		i++;
	}

}
int countBul(int frekansDizi[SIZE] , int diziBoyut){
	int i;
	int count=0;
	for(i=0 ; i<diziBoyut ; i++){
		if(frekansDizi[i] != 0){
			count++;
		}
	}
	
	return count;
}
int frekansSirala(int frekansDizi[SIZE] , int siraliFrekans[SIZE] , int Harfler[SIZE] , int diziBoyut){
	int i;
	int count=0;
	for(i=0 ; i<diziBoyut ; i++){
		if(frekansDizi[i] != 0){
			siraliFrekans[count] = frekansDizi[i];
			Harfler[count] = i+97;
			count++;
		}
	}
	bubbleSortHarf(siraliFrekans , Harfler , count);
	printf("\n");
	for(i=0 ; i<count ; i++){
		
		printf("%d ",siraliFrekans[i]);
		printf("(%c)   ",Harfler[i]);
	}
	return count;
}
int frekansYazdir(int frekansDizi[SIZE]){
	int i;
	for(i=0 ; i<=26 ; i++){
		if(frekansDizi[i] != 0){
			if(i != 26){
				printf("%c : %d\n",(i+97),frekansDizi[i]);
			}
			else{
				printf("Space : %d",frekansDizi[i]);
			}
		}
	}
}
void agacOlusturma(int frekansDizi[SIZE] , int Harfler[SIZE] , int diziBoyut){
	int i,j;
	int temp1 = diziBoyut;
	int temp = diziBoyut;
	for(j=0 ; j<temp ; j++){
//		printf("%c  ",Harfler[j]);
		printf("%d  ",frekansDizi[j]);
	}
	printf("\n-------------------\n");
	for(i=0 ; i<temp1-1 ; i++){
		frekansDizi[0] = frekansDizi[0] + frekansDizi[1] ;
		for(j=1 ; j<temp-1 ; j++){
			frekansDizi[j] = frekansDizi[j+1];
			
		}
		temp=temp-1;
		bubbleSortHarf(frekansDizi,Harfler,temp);
		
		for(j=0 ; j<temp ; j++){
//			printf("%c  ",Harfler[j]);
			printf("%d  ",frekansDizi[j]);
		}
		printf("\n-------------------\n");	
	}	
}
void kodYazdir(int karakterUzunluk , char karakterDizisi[SIZE]){
	int i;
	for(i=0 ; i<karakterUzunluk ; i++){
		if(karakterDizisi[i] == 'c'){
			printf("0");
		}
		else if(karakterDizisi[i] == 'd'){
			printf("11");
		}
		else if(karakterDizisi[i] == 'a'){
			printf("100");
		}
		else if(karakterDizisi[i] == 'b'){
			printf("1010");
		}
		else if(karakterDizisi[i] == 'g'){
			printf("1011");
		}
	}
}
void diziSifirla(char dizi[SIZE]){
	int i;
	for(i=0 ; i<SIZE ; i++){
		dizi[i] = '2';
	}
}
void koddanKarakter(char kodDizisi[SIZE] , int uzunlukDizi){
	int i=0 , loopControl , count = 0;
	char tempDizi[SIZE];
	printf("Girdiginiz Kodun Donusturulmus Hali : \n");
	while( i !=  uzunlukDizi){
		loopControl = 1;
		count = 0;
		diziSifirla(tempDizi);
		while ( loopControl == 1 ){
			tempDizi[count] = kodDizisi[i];
			if(tempDizi[0] == '0'){
				printf("c");
				loopControl = 0;
			}
			else if(tempDizi[0] == '1' && tempDizi[1] == '1'){
				printf("d");
				loopControl = 0;
			}
			else if(tempDizi[0] == '1' && tempDizi[1] == '0' && tempDizi[2] == '0'){
				printf("a");
				loopControl = 0;
			}
			else if(tempDizi[0] == '1' && tempDizi[1] == '0' && tempDizi[3] == '0'){
				printf("b");
				loopControl = 0;
			}
			else if (tempDizi[0] == '1' && tempDizi[1] == '0' && tempDizi[3] == '1'){
				printf("g");
				loopControl = 0;
			}
			i++;
			count++;
		}
	}
}
