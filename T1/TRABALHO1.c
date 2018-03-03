#include<conio.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

void contagemNotas(int k,int i, float valor,float vetor[]);
void atenov(int a, int b, int c);
void inicio();

int main(){

float numero,decimal ,numi;
float vet[12] = {100.00,50.00,20.00,10.00,5.00,2.00,1.00,0.50,0.25,0.10,0.01};
char num[20],numcent[20],senha[20];
int i,t,h,g,k,j,p,e,f,d,u,numinteiro,centavos,cont=0;
char resposta;

inicio();
system("cls");

printf("B$: "); 
scanf("%f",&numero);


contagemNotas(k,i,numero,vet);
printf("\n");
  //separando a parte inteira dos centavos:
  decimal = numero - (int)numero;
  numi=numero - decimal; 

decimal = decimal*100;
centavos = (int) decimal; //agor meus centavos estao nessa variavel int

sprintf(num, "%.f", numi); //passei float p string a parte inteira 
cont=strlen(num); //qtos algarismos o numero inteiro tem
numinteiro = atoi(num); //passei string para inteiro

/* verificando se ta armazenado: printf("\n%d\n",numinteiro); //ok
printf("%d\n",centavos); //ok */

if(cont == 3 || cont == 2){ 
f = numinteiro/100; 
numinteiro=numinteiro%100; 
d=numinteiro/10;
numinteiro=numinteiro%10;
u=numinteiro/1;
atenov(f,d,u);
}

if(cont == 4){ 
e = numinteiro/1000;
numinteiro=numinteiro%1000;
f = numinteiro/100; 
numinteiro=numinteiro%100; 
d=numinteiro/10;
numinteiro=numinteiro%10;
u=numinteiro/1;
atenov(0,0,e); 
printf(" mil ");
atenov(f,d,u);
}

if(cont == 5){ 
p = numinteiro/10000;                         //(divide por 10 elevado a contagem-1);
numinteiro=numinteiro%10000;
e = numinteiro/1000;                       
numinteiro=numinteiro%1000;
f = numinteiro/100; 
numinteiro=numinteiro%100; 
d=numinteiro/10;
numinteiro=numinteiro%10;
u=numinteiro/1;
atenov(0,p,e);
printf(" mil ");
atenov(f,d,u);
}

if(cont == 6){ 
j = numinteiro/100000;
numinteiro=numinteiro%100000;
p = numinteiro/10000;                         
numinteiro=numinteiro%10000;
e = numinteiro/1000;                       
numinteiro=numinteiro%1000;
f = numinteiro/100; 
numinteiro=numinteiro%100; 
d=numinteiro/10;
numinteiro=numinteiro%10;
u=numinteiro/1;
atenov(j,p,e);
printf(" mil ");
atenov(f,d,u);
}

printf(" bits ");
//chamando os centavos:

printf(" e ");
t=centavos/10;
centavos=centavos%10;
g=centavos/1;
atenov(0,t,g); 
printf(" centbits");

getch();
}

void inicio(){
	char senha[10];
    int i;
		printf("\n\t\t\t\t\tBEM VINDO AO BANCO ALGORITMOS II");
	printf("\n\t\t\t\t\t Senha(5 digitos): ");

	for (i = 0; i < 5; i++) {
         senha[i]=getch();    
		printf("*");
    }
getch();
}

void contagemNotas(int k,int i, float valor,float vetor[]) {
	
	for(i=0;i<12;i++){	
	k = valor/vetor[i];
	  if(k>0){
		valor = valor-(k*vetor[i]);
		printf("%d bits de %.2f\n",k,vetor[i]); }                                    
    }
}

void atenov(int a, int b, int c){
	switch(a){
		
	  	case 1:
	  	    if(b==0 && c==0)
		  	 printf("cem ");
		  	else
	         printf("cento");
			break;       
	   
	    case 2:
	    	printf("duzentos");break;
        case 3:
	    	printf("trezentos");break;
        case 4:
	    	printf("quatrocentos");break;
        case 5:
	    	printf("quinhentos");break;
        case 6:
	    	printf("seiscentos");break;
        case 7:
	    	printf("setecentos");break;
        case 8:
	    	printf("oitocentos");break;
        case 9:
	    	printf("novecentos");break;
            
      }

if(a>0 && b>0)
 printf(" e ");
 if(b==1){
 switch(c){
	 if(c==0)
		  	 printf("dez");
	  	case 1:
	         printf("onze");break;       
	    case 2:
	    	printf("doze");break;
         case 3:
	    	printf("treze");break;
         case 4:
	    	printf("catorze");break;
         case 5:
	    	printf("quinze");break;
         case 6:
	    	printf("dezesseis");break;
         case 7:
	    	printf("dezessete");break;
         case 8:
	    	printf("dezoito");break;
         case 9:
	    	printf("dezenove");break;     
      } 
        
}
else{
	switch(b){      
	   
	    case 2:
	    	printf("vinte");break;
         case 3:
	    	printf("trinta");break;
         case 4:
	    	printf("quarenta");break;
         case 5:
	    	printf("cinquenta");break;
         case 6:
	    	printf("sessenta");break;
         case 7:
	    	printf("setenta");break;
         case 8:
	    	printf("oitenta");break;
         case 9:
	    	printf("noventa");break;
      }
}

if(b>1 || b==0){
	if( (a>0 || b>0 ) || c>0){
	 printf(" e ");
	
	 switch(c){
        case 1:
	         printf("um");break;       
	    case 2:
	    	printf("dois");break;
         case 3:
	    	printf("tres");break;
         case 4:
	    	printf("quatro");break;
         case 5:
	    	printf("cinco");break;
         case 6:
	    	printf("seis");break;
         case 7:
	    	printf("sete");break;
         case 8:
	    	printf("oito");break;
         case 9:
	    	printf("nove");break;
	 }
}
}

}
