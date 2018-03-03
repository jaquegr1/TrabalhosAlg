#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <dirent.h>
#define F1 59

struct data{
  int dia, mes, ano;
};  

struct Dados {
  int numero;
  char nome[30];
  int estoque;
  float preco;
  struct data d;
  int existe;
};

struct Dados registro;

//----------------------------------

void menu (char *opcao) { 
  system("cls"); 
  printf ("\n \t M E N U");     
  printf ("\n1 - Cadastrar produto");
  printf ("\n2 - Mostrar todos os produtos");
  printf ("\n3 - Procura e altera(ou nao) determinado produto pelo codigo"); 
  printf ("\n4 - Procura determinado produto pelo nome"); 
 printf ("\n5 - Excluir");
  printf ("\n6 - Ajuda");
  printf ("\n7 - Sair");
 
  printf ("\nSua opcao: ");
  do {
    *opcao = getch();
  } while (*opcao < '1' || *opcao > '7'); 
  printf ("%c",*opcao);   
  printf ("\n--------------------------------------------------------\n");   
}  
//----------------------------------
void cadastra (char nomearq[]) {
  char resp;
  FILE *arquivo;
  if ((arquivo = fopen(nomearq, "r+b")) == NULL)
    if ((arquivo = fopen(nomearq, "wb")) == NULL) {               
      printf("\n Erro de abertura de arquivo");
      return;
    }
  fseek (arquivo,0,SEEK_END);  
  do {
    registro.existe =1;
	printf("\n\n Codigo do produto: ");
    scanf ("%d",&registro.numero);
    printf(" Nome do produto: ");
   fflush (stdin); //limpa o buffer ja descarrega/salva?
    gets(registro.nome);
    printf(" Preco: R$");
    scanf ("%f",&registro.preco);
	printf(" Quantos disponiveis em estoque:  : ");
    scanf ("%d",&registro.estoque);
    printf(" Data da ultima operacao: ");
    scanf ("%d %d %d",&registro.d.dia,&registro.d.mes,&registro.d.ano);
    fwrite(&registro, sizeof(registro), 1, arquivo);
    printf("\n Adicionar outro produto (s/n)?: ");
    do {
      resp = toupper(getch());
    } while (resp != 'S' && resp != 'N');
  } while (resp == 'S');
  fclose (arquivo); //toda função abre e fecha arquivo
}
//----------------------------------
void mostra (char nomearq[]) {
  FILE *arquivo;
  if ((arquivo = fopen(nomearq, "rb")) == NULL) {
    printf("\n Erro de abertura de arquivo");
    getch();
	return;
  }
  
  while (fread(&registro, sizeof(registro), 1, arquivo) == 1) {
    if (registro.existe) {
	printf("\n\n Codigo do produto: %d",registro.numero);
    printf("\n Nome do produto: %s",registro.nome);
    printf("\n Preco:  R$%.2f ",registro.preco);
	printf("\n Disponivel em estoque: %d ",registro.estoque);
    printf("\n Data da ultima operacao: %d/%d/%d",registro.d.dia,registro.d.mes,registro.d.ano);
  } 
  }
  fclose (arquivo);
  getch();
}
//----------------------------------
void procura (char nomearq[]) {
 char resp;
  FILE *arquivo;
  int num_produto, achou = 0;
  if ((arquivo = fopen(nomearq, "rb+")) == NULL) {
    printf("\n Erro de abertura de arquivo");
    return;
  }      
  //pelo codigo
  printf ("\nCodigo do produto que sera consultado: ");
  scanf ("%d",&num_produto);
  while (fread(&registro, sizeof(registro), 1, arquivo) == 1) 
    if (registro.numero == num_produto) {
      printf("\n\n Codigo do produto: %d",registro.numero);
      printf("\n Nome do produto: %s",registro.nome);
      printf("\n Preco do produto: R$%.2f",registro.preco);
      printf("\n Disponivel em estoque: %d ",registro.estoque);
	  printf("\nData da ultima operacao: %d/%d/%d",registro.d.dia,registro.d.mes,registro.d.ano);
      achou = 1;
    
    //ALTERAR ----------------------------------------------------------------------------------------------------
    printf("\n\nDeseja alterar tal produto?");  
  do {
      resp = toupper(getch());
    } while (resp != 'S' && resp != 'N'); 
  
  if(resp=='S') {
   fflush (stdin); // "Limpa" o buffer de entrada - teclado
      printf("\n\n Codigo do produto: ");
    scanf ("%d",&registro.numero);
    printf(" Nome do produto: ");
   fflush (stdin); //limpa o buffer ja descarrega/salva?
    gets(registro.nome);
    printf(" Preco: R$");
    scanf ("%f",&registro.preco);
	printf(" Quantos disponiveis em estoque:  : ");
    scanf ("%d",&registro.estoque);
    printf(" Data da ultima operacao: ");
    scanf ("%d %d %d",&registro.d.dia,&registro.d.mes,&registro.d.ano);
      // Volta o ponteiro
      fseek (arquivo,-sizeof(registro),SEEK_CUR);
      // Grava os dados lidos
      fwrite(&registro,sizeof(registro),1,arquivo);
	
}
	}
  if (!achou) 
    printf ("Produto %d nao cadastrado.",num_produto); 
  
  fclose (arquivo);
  
  getch();
}
//----------------------------------
void procuraNome (char nomearq[]){
  FILE *arquivo;
  int achou = 0;
  char nome[30];
  
  if ((arquivo = fopen(nomearq, "rb")) == NULL) {
    printf ("\n Erro de abertura de arquivo.\n\n");
    getch();
    return;
  }
  
  printf ("\nQual o nome do produto que deseja consultar? ");
  scanf("%s",&nome);
   
  while (fread (&registro, sizeof(registro), 1, arquivo) == 1 && !achou){ 
	if (registro.existe && strcmp(registro.nome,nome)==0) { 
      printf("\n\n Codigo do produto: %d",registro.numero);
      printf("\n Nome do produto: %s",registro.nome);
      printf("\n Preco do produto: R$%.2f",registro.preco);
      printf("\n Disponivel em estoque: %d ",registro.estoque);
	  printf("\nData da ultima operacao: %d/%d/%d",registro.d.dia,registro.d.mes,registro.d.ano);
      achou = 1;
    }}
  if (!achou)
    printf ("Produto %s nao esta cadastrado.\n\n",nome);
  fclose (arquivo);
  getch();
}
//---------------------------------------------------------------------------------------------------------------
void excluiLogica(char nomearq[]){
	FILE *arquivo;
  int numero, achou = 0;
  char numstr[30];
  // Abertura do arquivo
  if ((arquivo = fopen(nomearq, "r+b")) == NULL) {
    printf ("\n Erro de abertura de arquivo.\n\n");
    getch();
    return;
  }
  printf ("\nQual o codigo do produto que deseja apagar? ");
  scanf ("%d",&numero);
  // Leitura dos registros  
  while (fread (&registro, sizeof(registro), 1, arquivo) == 1 && !achou)
    if (registro.existe && registro.numero == numero) {
        printf("\n\n Codigo do produto: %d",registro.numero);
      printf("\n Nome do produto: %s",registro.nome);
      printf("\n Preco do produto: R$%.2f",registro.preco);
      printf("\n Disponivel em estoque: %d ",registro.estoque);
	  printf("\nData da ultima operacao: %d/%d/%d",registro.d.dia,registro.d.mes,registro.d.ano);
      
	  fflush (stdin); // "Limpa" o buffer de entrada - teclado
      char resp;
	  do{
	  printf("\n Tem certeza que deseja excluir o produto?(s/n)");
       resp = toupper(getch());
  } while (resp != 'S' && resp != 'N');
  
	  if (resp == 'S') {
	    registro.existe = 0; 
        // Volta o ponteiro
        fseek (arquivo,-sizeof(registro),SEEK_CUR);
        // Grava os dados lidos - alterados
        fwrite(&registro,sizeof(registro),1,arquivo);
        fflush (arquivo);
        printf ("\n\n %s removido do controle de estoque.\n\n",registro.nome);  
      }
      else
        printf ("\n\n%s nao removido do estoque.\n\n",registro.nome);  
      achou = 1;
    }
  if (!achou)
    printf ("Nao ha produto cadastrado com o codigo %d.\n\n",numero);
  fclose (arquivo);
  getch();
}
//----------------------------------------------------------------------------------------------------------
void remocaoFisica (char nomearq[]){ 
  FILE *arquivo, *arqaux;

  // Abertura do arquivo
  if ((arquivo = fopen(nomearq, "rb")) == NULL) {
    printf ("\n Erro na realizacao da remocao fisica.\n\n");
    getch();
    return;
  }
  
  arqaux = fopen("NOME.BAK", "wb"); //hmmmmm
  
  while (fread (&registro, sizeof(registro), 1, arquivo) == 1)
    if (registro.existe)
      fwrite (&registro, sizeof(registro), 1, arqaux);
  
  fclose (arquivo);
  fclose (arqaux);
  
  remove(nomearq);
  rename ("NOME.BAK",nomearq); //eita
  printf ("\n\nRemocao fisica realizada.");
  getch();
}  

//CRIPTOGRANDO O ARQUIVO DE AJUDA
/*O arquivo de ajuda deve ser do tipo texto e criptografado. 
No programa, a ajuda deve ser ativada pela tecla <F1>.
*/
void Criptografa(){
	FILE *arquivo,*crip,*file;
	int i;
    char leitor[200],tr[200]; 
	/*criptografar um arquivo texto qualquer :
	Ler um arquivo texto, gerar outro arquivo criptografado. 
	Ler o arquivo criptografado e mostrar na tela o arquivo original.*/

//lendo
if ((arquivo = fopen("ajuda.txt", "r")) == NULL) {
      printf("\n Erro de abertura de arquivo");
      exit(1);
    }  

//gerar outro vou escrever aqui o ajuda criptografado
 if ((crip = fopen("ajudacrip.txt", "w")) == NULL) {
    printf("\n Erro de abertura de arquivo");
    exit(1);
  }
  
   //o leitor tem q ter o tamanho exato do arquivo original
 while(fgets(leitor,200,arquivo)!= NULL){//enquanto tiver coisa no arquivo
		for(i=0;i<200;i++){
			 leitor[i] = leitor[i]+1; //criptografou ATENÇAO MINHA CHAVE É SMEPRE UM CARACTE A MAIS DA TABELA ASCII
			}
			 fputs(leitor,crip); //meu arquivo crip agora esta ilegivel
		}
fclose(arquivo);
fclose(crip);

 if ((file = fopen("ajudacrip.txt", "r")) == NULL) {
    printf("\n Erro de abertura de arquivo");
    exit(1);
  }
  
 while(fgets(tr,200,file)!= NULL){
		for(i=0;i<200;i++){
			 tr[i] = tr[i]-1; //descriptografou
			}
			printf("%s",tr); //mostrou o outro arquivo
 }

fclose(file);
getch();
}

//------------------------------------
int main() {
  char opcao, ch, nome_arquivo[15],nome[20];
  FILE *arquivo;
  
  printf ("\nDigite o nome da pasta a ser criada: ");
  gets (nome);
  mkdir (nome); //CRIA UMA PASTA 
  printf ("\nNome do arquivo a ser manipulado: ");
  gets (nome_arquivo);
  //system("cls");
  do {
    system("cls");
	menu(&opcao);
    switch (opcao) {
      case '1': 
	  system("cls");
	  cadastra(nome_arquivo);break;
      
	  case '2': 
	  system("cls");
	  mostra (nome_arquivo);break;
      
	  case '3': 
	  system("cls");
	  procura (nome_arquivo);break;
      
	  case '4': 
	  system("cls");
	  procuraNome (nome_arquivo);break; 
	  
	  case '5': 
	  system("cls");
	  excluiLogica (nome_arquivo);break;
	
	  case '6': 
	  system("cls");
	  Criptografa();break;

      case F1:  //para colocar o texto de ajuda na tela
	  
	  arquivo = fopen("ajuda.txt", "r");
	  while (!feof(arquivo)){ 
	    ch=getc(arquivo);
		printf("%c",ch); 
       }
      fclose(arquivo);
      break;
	  
	}
  } while (opcao != '7');    
  

  remocaoFisica(nome_arquivo);   
}
