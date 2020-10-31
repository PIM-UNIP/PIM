#include <conio.h> //para usar a fun��o getchar fflush
#include <stdio.h>  //biblioteca para utilizar fun��es comuns como (printF, scanf etc)
#include <String.h> //biblioteca que permite a adi��o de fun��es dentro de outras fun��es...
#include <stdlib.h> //biblioteca que serve de emulador para que quando altere de MAC, para LINUX, WINDOWNS E ETC, os codigos s�o convertidos!
#include <locale.h> //biblioteca que permite fazer o programa entender o idioma do sistema operacional
#include <math.h> //permite utilizar algumas fun��es matematicas de maneira mais simples (quadrado, potencia, raiz e etc)
#define SIZE 200 //Variavel constante de 200, em momento nenhum esse valor pode ser mudado

///ESTRUTURA QUE ARMAZENA DADOS DE UM MEDICO
typedef struct{
   char nome [SIZE] [50];
   char email [SIZE];
   char cpf[SIZE];
   char rg[SIZE];
   int telefone;
   char senha[9];
   char senhacomp[9];
}pessoa; pessoa l;


typedef struct dados DADOS;
   struct dados{
   char cpf[SIZE];
   char senha[9];
   char nome[SIZE]
};


///ESTRUTURA QUE ARMAZENA DADOS DE PACIENTES
typedef struct Cliente Cliente;
   struct Cliente{
   char nome [SIZE] [50];
   char email [SIZE];
   char cpf[20];
   char rg[20];
   int telefone;
   char consulta[SIZE];
   char data[12];
   char carteirinha[22];
};


///VARI�VEIS GLOBAIS FORA DE UMA ESTRUTURA
int direct = 0; //variavel comum inteiro
FILE* arquivo;//Variavel FILE para apontar arquivo aba funcion�rio
DADOS login_dados; // strutura de login
Cliente cad;

///PROT�TIPO DE FUN��ES
void cadastro(); //prot�tipo da fun��o de cadastro funcion�rio
void login(); //prot�tipo da fun��o de login
void areatrab(); //para menu de funcion�rios
void cadclient(); //fun��o de cadastro de clientes
void agenda(); //fun��o para agendamento de consultas
void cadmedic(); //fun��o de cadastro de m�dicos
void pesquisa(); //prot�tipo da area de pesquisar clientes
void feedback(); //fun��o de feedback
void cancela(); //fun��o para cancelamentos de consultas
void listar_dados(); //fun��o de lista de clientes
void cabecalho(); // fun��o para retorna mensaens por meio ode parametros
void mensagem_cmd(); // fun�o para imprimir mensagens por parametros

/* =============================================================================================================================================== */

void cabecalho(int opcao){
   switch (opcao){
      case 1:
         printf("\n=======================================\n");
         printf("*                                     *\n");
         printf("*             Menu Inicio             *\n");
         printf("*                                     *\n");
         printf("=======================================\n");
         break;  
      case 2:
         printf("\n=======================================\n");
         printf("*                                     *\n");
         printf("*            Menu Cadastro            *\n");
         printf("*                                     *\n");
         printf("=======================================\n");
         break;
      case 3:
         printf("\n=======================================\n");
         printf("*                                     *\n");
         printf("*             Menu Login              *\n");
         printf("*                                     *\n");
         printf("=======================================\n");
         break;
      case 4:
         printf("\n=======================================\n");
         printf("*                                     *\n");
         printf("*             Menu Op��es             *\n");
         printf("*                                     *\n");
         printf("=======================================\n");
         break;
      case 5:
         printf("\n=======================================\n");
         printf("*                                     *\n");
         printf("*        Cadastro de Cliente          *\n");
         printf("*                                     *\n");
         printf("=======================================\n");
         break;
      case 6:
         printf("\n=======================================\n");
         printf("*                                     *\n");
         printf("*          Menu de Listagem           *\n");
         printf("*                                     *\n");
         printf("=======================================\n");
         break;
      case 7:
         printf("\n=======================================\n");
         printf("*                                     *\n");
         printf("*         Lista de Pacientes          *\n");
         printf("*                                     *\n");
         printf("=======================================\n");
         break;
      case 8:
         printf("\n=======================================\n");
         printf("*                                     *\n");
         printf("*          Lista de Medicos           *\n");
         printf("*                                     *\n");
         printf("=======================================\n");
      break;

   }
}

void mensagem_cmd(char mensagem[SIZE]){
   printf("\n================= %s =================\n", mensagem);
}

///MENU DE OP��ES
void main(){
   char usuario[SIZE];
   char senha[9];
   setlocale(LC_ALL, "");
   cabecalho(1);

   printf("\n1 - LOGIN\n");
   printf("2 - CADASTRO\n");
   printf("\nEscolha sua op��o: ");
   scanf("%d" , &direct);

   switch(direct){
      case 1:
         system("cls");
         login();
         break;
      case 2:
         system("cls");
         cadastro();
         break;
      default:
      printf("Op��o inv�lida") ;
   }
}


///AREA DE TRABALHO
void areatrab(){
   int verifica_opcao = 0;
   do{
      system("cls");   
      cabecalho(4);
      if( verifica_opcao == 1){
         mensagem_cmd("Op��o inv�lida!");
      }
      verifica_opcao = 0;
      printf("\n=============================\n");
      printf("\nInforma��es:\nNome utilizador: %s\nCPF: %s\n", login_dados.nome, login_dados.cpf);
      printf("=============================\n\n");
      printf("\n1 - CADASTRO DE CLIENTES");
      printf("\n2 - CADASTRO DE M�DICOS");
      printf("\n3 - PESQUISA MEDICOS/PACIENTES");
      printf("\n4 - AGENDAMENTOS");
      printf("\n5 - LISTA DE CLIENTES/MEDICOS CADASTRADOS");
      printf("\n6 - CANCELAMENTO DE CONSULTAS");
      printf("\n7 - FeedBack");
      printf("\n=============================\n");
      printf("\nEscolha sua op��o: ");
      scanf("%d" , &direct);
      switch(direct){
         case 1:
            printf("Iniciando CADASTRO DE CLIENTES...\n");
            cadclient();
            break;
         case 2:
            printf("Iniciando CADASTRO DE M�DICOS...\n");
            //cadmedic();
            break;
         case 3:
            printf("\nIniciando PESQUISAR...\n");
            pesquisa_funcionario();
            break;
         case 4:
            printf("Iniciando AGENDAMENTOS...\n");
            //agenda();
            break;
         case 5:
            printf("Iniciando LISTA DE CLIENTES/MEDICOS CADASTRADOS...\n");
            listar_dados();
            break;
         case 6:
            printf("Iniciando CANCELAMENTO DE CONSULTAS...\n");
            //cancela();
            break;
         case 7:
            printf("Iniciando FEEDBACK...\n");
            //feedback();
            break;
         default:
         verifica_opcao = 1;
      }
  }while(direct < 1 || direct >7 );
}


// PARTE CADASTRO UTILIZADOR
void cadastro(){
   arquivo = fopen("Dados/Login.txt", "ab");
   system("cls");
   do{
      cabecalho(2);
      printf("\nDigite nome do utilizador do sistema: ");
      fflush(stdin);
      gets(login_dados.nome);

      printf("\nDigite sua cpf sem pontua��o(servir� como login): ");
      fflush(stdin);
      gets(login_dados.cpf);

      printf("\nDigite sua senha(apenas 8 d�gitos): ");
      fflush(stdin);
      gets(login_dados.senha);

      if(arquivo == NULL){
      printf("Erro na abertura do arquivo");
      }
      fwrite(&login_dados, sizeof(DADOS), 1, arquivo);
      fclose(arquivo);

      system("cls");
      mensagem_cmd("Us�ario cadastrado com sucesso!");
      printf("\n1 - Para cadastrar novamente \n2 - para continuar\nDigite sua op��o: ");
      fflush(stdin);
      scanf("%i", &direct);

   }while(direct==1);

   system("cls");
   printf("\n1 - SEGUIR PARA LOGIN");
   printf("\n2 - SAIR");
   printf("\nDigite sua op��o: ");
   scanf("%i", &direct);
   switch(direct){
      case 1:
         system("cls");
         printf("Seguindo para login...");
         login();
         break;
      case 2:
         printf("Saindo...");
         system("exit");
         break;
      default:
      printf("Op��o inv�lida!");
      main();
   }
} 
// FINAL PARTE CADASTRO UTILIZADOR


///PARTE DO LOGIN
int api_login(char cpf_login[SIZE], char senha_login[SIZE]){
   arquivo = fopen("Dados/Login.txt", "rb");
   while(fread(&login_dados, sizeof(DADOS), 1, arquivo) == 1){
      if((strcmp(cpf_login, login_dados.cpf) == 0) && (strcmp(senha_login, login_dados.senha) == 0 ) ){
         return 1;
      }
   }
   fclose(arquivo);
   return 0;
}
void login(){
   char login[SIZE];
   char senhalog[9];
   int Verificacao = 0;

   do{
      system("cls");
      cabecalho(3);

      printf("\nDigite o Login(CPF sem pontuacao): ");
      scanf("%s", login);

      printf("Digite sua Senha(MAX 8 Digitos): ");
      scanf("%s", senhalog);

      if(api_login(login, senhalog) == 1 ) {
         Verificacao = 1;
         mensagem_cmd("Usuario Autenticado!");
         sleep(2);
         areatrab();
      }else{
         Verificacao = 0;
         mensagem_cmd("Usuario ou senha incorretos");
         system("pause");
         system("cls");
      }
   }while(Verificacao == 0);
}
// FINAL PARTE DE LOGIN


///FUN��O PARA CADASTRAR CLIENTES
void cadclient(){
   arquivo = fopen("Pacientes/Lista_Pacientes.txt", "ab");
   do{
      system("cls");
      cabecalho(5);

      printf("\nDigite o Nome do Cliente: ");
      fflush(stdin);
      gets(cad.nome);

      printf("\nDigite o Email do Cliente: ");
      scanf("%s", &cad.email);

      printf("\nDigite o CPF do Cliente: ");
      scanf("%s", &cad.cpf);

      printf("\nDigite o RG do Cliente: ");
      scanf("%s", &cad.rg);

      printf("\nDigite o Telefone do cliente: ");
      scanf("%i" , &cad.telefone);

      printf("\nInforme sobre a Consulta Marcada: ");
      fflush(stdin);
      gets(cad.consulta);

      printf("\nInforme a Data da Consulta: ");
      fflush(stdin);
      gets(cad.data);

      printf("\nDigite o N� da Carterinha: ");
      scanf("%s", &cad.carteirinha);

      fwrite(&cad, sizeof(Cliente),  1, arquivo);

      if(arquivo == NULL){
         printf("Erro na abertura do arquivo");
         return 1;
      }
      printf("\ndados salvos com sucesso!");

      fclose(arquivo);
      getch();

      printf("\n\nDigite 1 para continuar ou outro valor para sair: ");
      fflush(stdin);
      scanf("%i", &direct);
      gets(cad.data);
   }while(direct==1);

   system("pause");
   printf("\nAperte enter para voltar...");
   areatrab();
}

// PARTE DE PESQUIESAR FUNCIONARIO
void api_Pfuncionario(char procurar_funcionario[SIZE]){
   char nome_capturado[SIZE];
   char email_capturado[SIZE];
   char cpf_capturado[SIZE];
   char rg_capturado[SIZE];
   char tel_capturado[SIZE];
   arquivo = fopen("Medicos/DADOS_DO_FUNCION�RIO.txt","r");
   while(fscanf(arquivo, "%s %s %s %s %s",nome_capturado, email_capturado, cpf_capturado, rg_capturado, tel_capturado) !=EOF){
      if(!strcmp(nome_capturado, procurar_funcionario)){
         printf("\n***************** DADOS DO FUNCIONARIO *****************\n");
         printf("\n========================================================\n");
         printf("\nNome: %s\nE-Mail: %s\nCPF: %s\nRG: %s\nTelefone: %s \n", nome_capturado, email_capturado, cpf_capturado, rg_capturado, tel_capturado);
         printf("\n========================================================\n\n\n");
      }
   }

   printf("1 - Pesquisar Novamento\n");
   printf("2 - Ir para Menu\n");
   printf("3 - Sair Do Programa\n");
   printf("Escolha sua op��o: ");
   scanf("%d" , &direct);
   switch(direct){
      case 1:
         system("cls");
         pesquisa_funcionario();
         break;
      case 2:
         system("cls");
         areatrab();
         break;
      case 3:
         exit(0);
         break;
      default:
      printf("Op��o inv�lida!\n") ;
   }
}

void pesquisa_funcionario(){
   char procurar_funcionario[SIZE];
   arquivo = fopen("Medicos/DADOS_DO_FUNCION�RIO.txt","r");

   system("cls");
   printf("*****************�REA DE PESQUISA*****************\n");
   if(arquivo == NULL){ // Verifica se existe o arquivo TXT para ler os dados, se existe executa void normal, caso n�o exista vai voltar para tela de op��es
      printf("***************** Erro na abertura do arquivo *****************\n" ); // Mostra mensagem de erro para us�ario ficar ciente que tem erro no arquivo
      printf("***************** Voltando para tela de op��es! *****************\n");
      sleep(3); // Agurda 3 segundos
      system("cls"); // Aqui limpamos a tela do CMD com comando "cls"
      areatrab();// Aqui voltamos para tela de op��es
   }
   printf("Infome nome do cliente: ");
   scanf("%s", procurar_funcionario);
   api_Pfuncionario(procurar_funcionario);
} 
//FINAL DA PARTE DE PESQUISAR FUNCIONARIO


//PARTE PARA LISTAR OS DADOS
void api_listarDados(int tipo_dados){
   system("cls");
   int verifica_opcao = 0;
   int vezes = 0;

   if(tipo_dados == 1){
      cabecalho(7);
      arquivo = fopen("Pacientes/Lista_Pacientes.txt", "rb");
      while(fread(&cad, sizeof(Cliente), 1, arquivo) == 1){
         vezes ++;    
         printf("\n\n-----------------------------\n\n");
         printf("Nome: %s \n", cad.nome);
         printf("E-mail: %s \n", cad.email);
         printf("Cpf: %s \n", cad.cpf);
         printf("Rg: %s \n", cad.rg);
         printf("telefone: %d \n", cad.telefone);
         printf("Tipo consulta: %s \n", cad.consulta);
         printf("Data Da Consulta: %s \n", cad.data);
         printf("Numero da carteirinha: %s \n", cad.carteirinha);
         printf("\n\n-----------------------------\n\n");
      }
   }
   if(tipo_dados == 2){
      cabecalho(8);
      arquivo = fopen("Medicos/Lista_Medicos.txt", "rb");
      while(fread(&cad, sizeof(Cliente), 1, arquivo) == 1){
         printf("\n\n-----------------------------\n\n");
         printf("Nome: %s \n", cad.nome);
         printf("E-mail: %s \n", cad.email);
         printf("Cpf: %s \n", cad.cpf);
         printf("Rg: %s \n", cad.rg);
         printf("telefone: %d \n", cad.telefone);
         printf("Tipo consulta: %s \n", cad.consulta);
         printf("Data Da Consulta: %s \n", cad.data);
         printf("Numero da carteirinha: %s \n", cad.carteirinha);
         printf("\n\n-----------------------------\n\n");
      }
   }
   printf("Total de dados: %d \n", vezes);
   fclose(arquivo);

   do{
      if(verifica_opcao == 1){
         printf("Op��o inv�lida!\n");
      }
      verifica_opcao = 0;   
      printf("=============================\n");
      printf("1 - Voltar Menu De listagem\n");
      printf("2 - Ir para Op��es\n");
      printf("=============================\n");
      printf("0 - Para sair\n");
      printf("=============================\n\n");
      printf("Escolha sua op��o: ");
      scanf("%d" , &direct);
      switch(direct){
         case 0:
            printf("Deslogando sistema...");
            sleep(2);
            exit(0);
            break;
         case 1:
            system("cls");
            listar_dados();
            break;
         case 2:
            system("cls");
            areatrab();
            break;
         default:
         verifica_opcao = 1;
         system("cls");
      }
   }while(direct < 0 || direct > 2);
}

void listar_dados(){
   int verifica_opcao = 0;
   do{
      if( verifica_opcao == 1){
         mensagem_cmd("Op��o inv�lida!");
      }
      system("cls");
      cabecalho(6);
      verifica_opcao = 0;   
      printf("\n=============================\n");
      printf("Desejar listar quais dados:\n");
      printf("1 = PACIENTES\n");
      printf("2 = MEDICOS\n");
      printf("=============================\n");
      printf("0 = Voltar ao menu\n");
      printf("=============================\n\n");
      printf("Digite op��o desejada: ");
      scanf("%i", &direct);
      switch(direct){
         case 0:
            areatrab();
            break;
         case 1:
            api_listarDados(direct);
            break;
         case 2:
            api_listarDados(direct);
            break;
         default:
         verifica_opcao = 1;
      }
   }while(direct < 0 || direct > 2);
}