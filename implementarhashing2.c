 /*Implementar as funções hashing: 
(1) Extração,
(2) Enlaçamento Deslocado,
(3) Enlaçamento Limite,
(4) Dobra.

As funções devem ser com o seguinte protótipo:
                             int <nome_funcao> (<tipo> chave, int M).

Onde: <nome_funcao> representará a função implementada e retornará um inteiro (representa o índice da tabela.
          "chave" é o valor a ser calculado, que pode ser um int, char[], long int etc (dependerá do valor a ser passado para a função.
          "M" é o tamanho da tabela. */
          
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


int extracao (int chave, int M){
	/*pode transformar a chave em uma string (vetor de char)
	pega o pedaço que quiser (os dois primeiros os dois ultimos o primeiro e o ultimo) mas tem q comparar com M(ver se cabe), e esse é seu indice!
	vou fazer pegando os dois priemrios 
	para M=100 -> 0 a 99 entao de acordo com o tamho de M o indice return tem q ser aqui dentro
	*/
char x[15]; //digito
itoa(chave, x, 10);
//sprintf(x,"%d",chave);
//printf("%c%c",x[0],x[1]);

char dois_primeiros[3]; // três caracteres mais o terminador de linha
// copia os três primeiros caracteres de um array para o outro
memcpy( dois_primeiros, &x[0], 2); 
dois_primeiros[2] = '\0'; // adiciona o terminador de linha
//printf("%s", dois_primeiros);
//transformo string para int
int num = atoi(dois_primeiros);
return num; 

}

int enlacamento_deslocado(int chave, int M){
	/*divido a chave em blocos iguaus e somo todos esses bloquinho e se a so ma for um indice valido ok se nao aplico divisao inteira
	ta netao vou recber um int..transformo pra string e divido essa string pego a srten e dividio?*/
	//para indice igual a 2 vou dividir de 2 em dois
	char x[15]; //digito
    itoa(chave, x, 10); //x agora eh uma string
    int d=strlen(x);
	//sprintf(x,"%d",chave);
	if( d%2 != 0 )
	 x[d] = '0'; //ok preciso ver se eh um numero par ou impar pq se for impar tenho q add um 0 no final

//colocar em uma estrutura de repetição
char dois_primeiros[3]; // 2 caracteres mais o terminador de linha
// copia os 2 primeiros caracteres de um array para o outro
memcpy( dois_primeiros, &x[0], 2); 
dois_primeiros[2] = '\0'; // adiciona o terminador de linha
//printf("%s", dois_primeiros); //agora tneho os dois primeiros nessa string mas tenho q fazer isso enquanto nao acabar o numero de digitos pra depois somar tudo..	
//printf("\t");

char dois_segundos[3];
memcpy( dois_segundos, &x[2], sizeof(dois_segundos)); 
dois_segundos[2] = '\0'; 
//printf("%s", dois_segundos);
//printf("\t");

char dois_terceiros[3];
memcpy( dois_terceiros, &x[4], sizeof(dois_terceiros)); 
dois_terceiros[2] = '\0'; 
//printf("%s", dois_terceiros);*/

char dois_quartos[3];
memcpy( dois_quartos, &x[6], sizeof(dois_quartos)); 
dois_quartos[2] = '\0'; 

//considerando só oito numeros...
int num1 = atoi(dois_primeiros);
int num2 = atoi(dois_segundos);
int num3 = atoi(dois_terceiros);
int num4 = atoi(dois_quartos);
//printf("%d + %d +%d + %d = %d",num1,num2,num3,num4,num1+num2+num3+num4);

//agora verifico se eh um indice valido
int soma= num1+num2+num3+num4;
//printf ("\n%d",soma%M);
return (soma%M);
}

int enlacamento_limite(int chave, int M){
/*esse tb divide a chave em varios bloquinhos de 2..dai somo o primeiro nomral com o segundo invertido e vou intercaladno...*/	

	char x[15];
    itoa(chave, x, 10); 
    int d=strlen(x);
	
	if( d%2 != 0 )
	 x[d] = '0'; 

//colocar em uma estrutura de repetição
char dois_primeiros[3]; 
memcpy( dois_primeiros, &x[0], 2); 
dois_primeiros[2] = '\0'; 

//esse aqui tenho q inverter...ja tive bloco 0 esse eh o bloco 1
char dois_segundos[3];
memcpy( dois_segundos, &x[2], sizeof(dois_segundos)); 
dois_segundos[2] = '\0'; 
char invertido[3];
  invertido[0] = dois_segundos[1];
   invertido[1] = dois_segundos[0];
  // printf("%s",invertido);

char dois_terceiros[3]; //bloco 2
memcpy( dois_terceiros, &x[4], sizeof(dois_terceiros)); 
dois_terceiros[2] = '\0'; 


char dois_quartos[3]; //bloco3
memcpy( dois_quartos, &x[6], sizeof(dois_quartos)); 
dois_quartos[2] = '\0'; 
char invertido2[3];
invertido2[0] = dois_quartos[1];
invertido2[1] = dois_quartos[0];

//considerando só oito numeros...
int num1 = atoi(dois_primeiros);
int num2 = atoi(invertido);
int num3 = atoi(dois_terceiros);
int num4 = atoi(invertido2);
//printf("%d + %d +%d + %d = %d",num1,num2,num3,num4,num1+num2+num3+num4);

int soma= num1+num2+num3+num4;
//printf ("\n%d",soma%M);
return (soma%M);

}

int dobra(int chave, int M){
/*tenho que passar pra string essa chave
pra ir pegando de dois em dois (pq eh 100)
pego os primeiros dois transformo pra int
os prosimos dois eu inverto e transfomro pra int
soma esses 4 (2 bloquinhos) dai dividdo por digito
*/
	

}

int main(){
    int chave;
  	printf("\t\t\tIMPLEMENTACAO HASHING II \n Digite um numero:");
	scanf("%d",&chave);
    printf("\n\t\tExtracao: \n");
	printf("Indice: %d", extracao(chave,100));
	printf("\n\t\tEnlacamento deslocado:\n");
	printf("Indice: %d",enlacamento_deslocado(chave,100));
	printf("\n\t\tEnlacamento limite:\n");
	printf("Indice: %d ",enlacamento_limite(chave,100));
	
getch();
}
