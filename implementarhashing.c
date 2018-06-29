/*Implementar as funções hashing: 
(1) Divisão inteira,
(2) Meio Quadrado,
(3) Transformação da raiz.

As funções devem ser com o seguinte protótipo:
int <nome_funcao> (<tipo> chave, int M).

Onde: <nome_funcao> representará a função implementada e retornará um inteiro (representa o índice da tabela.
"chave" é o valor a ser calculado, que pode ser um int, char[], long int etc (dependerá do valor a ser passado para a função.
"M" é o tamanho da tabela.
 */
 
 #include <stdio.h> 
 #include <stdlib.h>
 #include <conio.h>
 #include <string.h>
 
 int div_inteira(int x, int m){
  return (x%m); 
 }
 
 /*int*/void meio_quadrado(int x, int m){
 	//eleva x² transforma o result em string pega o meio volta pra int e ve se é valido
 	int i;
 	i = x*x;
 	char chave[50];
 	itoa(i, chave, 10); 
	 int d = strlen(chave);
	 int meio = d/2;
 	//printf("%d\n",meio);
	   printf("numero do meio = indice =  %c\n", chave[meio]);
 }
 
 int transf_raiz(int x, int m){
 	//aqui é aquele q muda o numero pra outra base
    //tenho q entrar com a base 
 	//e chama a div_inteira no numero con vertido
 	printf("\nDigite a base: ");
int base;
	 scanf("%d",&base);
	 int digito[10];
	 int i=0;
	 int novo=1000;
	 while(novo > base ){
	novo = x/base;
	  digito[i] = x % base ;
	  x = novo;
 	i++;
 	  }
 	  
 	  if(novo <= base){
 	   digito[i] = novo % base;
 	   
}
 	   int j=0;
 	   char stringcompleta[20]="";
 	   fflush(stdin);
printf("\nNumero convertido: ");
 char teste[10];
 for(i; i>=0;i--){
  printf("%d",digito[i]);
  
  itoa(digito[i],teste,10) ; 
   	strcat(stringcompleta,teste); 
}
int xyz;
xyz = atoi(stringcompleta); 
  div_inteira(xyz,100);

}
 
  int main(){
  	//usando M=100 em todos os casos
  	char chave[50];
  	printf("\t\t\tIMPLEMENTACAO HASHING I \n Digite um numero:");
	  scanf("%s",&chave);
	  int num = atoi(chave); 
 	printf("\n\t\t\tDivisao Inteira\n");
 	printf("Indice: %d\n",div_inteira(num,100));
 	printf("\n\t\t\tMeio Quadrado\n");
 	//printf("aqui eh o return: %d\n", meio_quadrado(num,100));
 	meio_quadrado(num,100);
	 printf("\n\t\t\tTransformacao da raiz: \n");
 printf("\nIndice: %d",transf_raiz(num,100));
 	
    getch();
 }
