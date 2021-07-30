//Bibliotecas padrão da linguagem C
#include <stdio.h>
#include <stdlib.h>

//Biblioteca pra utilizar função getch
#include <conio.h>

//Biblioteca utilizada na manipulação de strings/sequencias de texto
#include <string.h>

//Biblioteca de localização
#include <locale.h>

//declarando o nome e prontuário como variáveis globais, para que possa ser utilizado de maneira abrangente pelo código
char nome[50], prontuario[14];

//Prototipação das funções
char menu();
void realizarTeste();
void gravarQuestionario();
void mostrarMenuMaster();
void visualizarQuestionario();
int sobreOTeste();


//Estrutura pra registrar cada pergunta do teste
typedef struct
{
	int nroFrases;
	char Frase [100];
	int cinestesico;
	char item_1 [100];
	int auditivo;
	char item_2 [100];
	int visual;
	char item_3 [100];
	int digital;
	char item_4 [100];
}
reregFrases;


//Istanciando todas as frases de cada questão através da struct de registro
reregFrases  VariavelRegistro [5] = {

    //Cada registro está entre chaves
	{1,"Eu tomo decisões importantes baseadx em",0, "intuição",0,"o que me soa melhor",0,"o que me parece melhor",0,"um estudo preciso e minucioso do assunto"},
	{2, "Durante uma discussão sou mais influenciadx por",0,"se eu entro em contato ou não com o sentimentos reais do outro",0,"o tom de voz da outra pessoa",0,
        "se eu posso ou não ver o argumento da outra pessoa",0,"a lógica do argumento da outra pessoa"},
    {3,"Eu comunico mais facilmente o que passa comigo",0,"pelos sentimentos que compartilho",0,"pelo tom da minha voz",0,"do modo como me visto ou aparento",0,
       "pelas palavras que escolho"},
    {4,"É muito fácil pra mim",0,"escolher os móveis mais confortáveis",0,"achar o volume e sintonia ideais num sistema de som",0,
	   "escolher a combinação de cores mais ricas e atraentes",0,"selecionar o ponto mais relevante relativo a um assunto interessante"},
	{5, "Eu me percebo assim",0,"eu sou muito sensível à maneira como a roupa veste meu corpo",0,"se estou muito em sintonia com os sons dos ambientes",0,
	    "se eu respondo formente às cores e aparência de uma sala",0,"se sou muito capaz de raciocinar com os fatos e dados novos"}
};



//Método principal, faz o login no sistema
int main()
{

    //Definindo a localização do console como Português
    setlocale(LC_ALL, "Portuguese");

    //Pegando o nome do usuário através do fgets e limpando o buffer do teclado
    printf("\n\nINFORME SEU NOME: ");
    fgets(nome, 50, stdin);
    fflush(stdin);

    //Pegando o prontuário do usuário através do fgets e limpando o buffer do teclado
    printf("\nINFORME SEU PRONTUÁRIO: ");
    fgets(prontuario, 14, stdin);
    fflush(stdin);

    //Caso o ultimo digito seja uma quebra de linha (ou seja, \n), remove ela
    if ((strlen(nome) > 0) && (nome[strlen (nome) - 1] == '\n')) nome[strlen (nome) - 1] = '\0';

    if ((strlen(prontuario) > 0) && (prontuario[strlen (prontuario) - 1] == '\n')) prontuario[strlen (prontuario) - 1] = '\0';

    //Se o usuário for Master, mostra o Menu, se não, realiza o teste
    if(strcmp(nome, "MASTER") == 0)
    {
        printf("Você logou como master!");
        getch();
        system("cls");
        mostrarMenuMaster();

    }
    else{

        realizarTeste();
    }
    return 0;
}

//Função para exibição do menu caso o usuário seja master
char menu (void)
{
    //Declara um caractér que vai ser retornado como resposta das escolhas do menu
    char opc;
    printf ("\n=========================================");
    printf ("\nTESTE DE SISTEMAS REPRESENTACIONAIS");
    printf ("\n=========================================");
    printf ("\n1. Cadastrar questinário");
    printf ("\n2. Visuaizar questinário");
    printf ("\n3. Realizar teste");
    printf ("\n4. Sobre o teste");
    printf ("\nF. FIM");
    printf ("\n=========================================");
    printf ("\n                   Escolha sua opção:\t");
    opc = getche ();
    fflush (stdin);

    //Retorna um caractér
    return opc;

}

void visualizarQuestionario()
{

    FILE * arq;
    arq = fopen ("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "r");

    FILE * arquivoTexto;
    arquivoTexto = fopen ("Questionario1.txt", "w");

    if(arquivoTexto == NULL)
    {
        printf("Erro ao abrir ao visualizar o texto");
        exit(0);
    }
    reregFrases newFrases[5];
    reregFrases regaux;
    if(arq == NULL)
    {
        printf("Não há registro do teste no sistema");
        getch();
        exit(0);

    }
    int counter = 0;
    char nrofrase[] = {"NroFrase"};
    char frase[] = {"Frase"};
    char Cinestesico[] = {"C"};
    char Auditivo[] = {"A"};
    char Visual[] = {"V"};
    char Digital[] = {"D"};

    char item1[] = {"item_1"};
    char item2[] = {"item_2"};
    char item3[] = {"item_3"};
    char item4[] = {"item_4"};


    fprintf(arquivoTexto, "%-8s  %-80s %s  %-80s %s  %-80s %s  %-80s %s  %-80s\n",
            nrofrase, frase,
            Cinestesico, item1,
            Auditivo, item2,
            Visual, item3,
            Digital, item4
            );
    while(!feof(arq))
    {
        fread ( &regaux, sizeof(regaux), 1, arq );
		if (ferror(arq))
		{
			printf ("\nErro ao ler o registro do CADASTRO.DAT");
			getch();
			break;
		}

		/* Testar se leu EOF */
		if ( !feof(arq) )
		{
		    newFrases[counter] = regaux;
		   /* Mostra na tela */
            fprintf(arquivoTexto, "%-8d  %-80s %d  %-80s %d  %-80s %d  %-80s %d  %-80s\n",
                    newFrases[counter].nroFrases,
                    newFrases[counter].Frase,
                    newFrases[counter].cinestesico,
                    newFrases[counter].item_1,
                    newFrases[counter].auditivo,
                    newFrases[counter].item_2,
                    newFrases[counter].visual,
                    newFrases[counter].item_3,
                    newFrases[counter].digital,
                    newFrases[counter].item_4
            );
            counter++;
	   }

    }
    printf("%d", counter);
    fclose (arq);
    fclose(arquivoTexto);
    printf ("\n\aSeu arquivo foi gerado com sucesso!");


    system("Questionario1.txt");
    getch ();
}


//Método para realizar o teste
void realizarTeste (void)
{

    //Limpa a tela antes de exibir qualquer coisa
    system("cls");

    //Instancia uma variável pra pegar o tipo de perfil do usuário e um contador para controlar repetições
    char tipoPerfil[15];
    int counter = 0;

    //Define um ponteiro de arquivo, onde leremos a informação do teste para poder exibir
    FILE * arq;
    arq = fopen ("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "r");

    /*
        Instanciamos dois registros referentes ao questionário,
        um para podermos armazenar as frases e respostas de cada questão
        outro para servir de registro auxiliar
    */
    reregFrases newFrases[5];
    reregFrases regaux;

    //Se não houver arquivo de registro ou dar falha, para a função
    if(arq == NULL)
    {
        printf("Não há registro ou não foi possível ler o teste no sistema");
        getch();
        exit(0);

    }

    //Loop para ler até o fim do arquivo
    while(!feof(arq))
    {
        //Lê o registro da linha e coloca na variável auxiliar
        fread ( &regaux, sizeof(regaux), 1, arq );

        //Se houver erro ao ler o arquivo, o loop é parado
		if (ferror(arq))
		{
			printf ("\nErro ao ler o registro do CADASTRO.DAT");
			getch();
			break;
		}
		/* Testar se leu EOF */
		if ( !feof(arq) )
		{
		    //Se não, o registro auxiliar passa seus valores para o vetor de registros no contador especifico e vai pro próximo
		    newFrases[counter] = regaux;
            counter++;
	   }
    }
    //Repete até ler o arquivo inteiro e fecha
    fclose (arq);


    //Declara variáveis auxiliares para pegar o valor de cada pergunta e variáveis para acrescentar no total de cada área
    int aux1, aux2, aux3, aux4;
    int totalAuditivo = 0, totalCinestesico = 0, totalDigital = 0, totalVisual = 0;

    //Loop do teste, uma vez pra cada pergunta
    for(counter = 0; counter < 5; counter++)
    {
        //Exibe cada uma das frases
        printf("\n%d - %s\n", newFrases[counter].nroFrases, newFrases[counter].Frase);
        printf("a) %s\n", newFrases[counter].item_1);
        printf("b) %s\n", newFrases[counter].item_2);
        printf("c) %s\n", newFrases[counter].item_3);
        printf("d) %s\n", newFrases[counter].item_4);

        //Pega cada uma das alternativas, não deixa elas sairem do range e também garante que não há repetições
        do{
	    	printf("\n[a] -->");
	    	scanf ("%d", &aux1);

		}while  ((aux1 >4 || aux1 <1 ));

        do{
	   	     printf ("\n[b] -->");
	   	     scanf("%d", &aux2);

	    }while  ((aux2 >4 || aux2 <1 ) || (aux2 == aux1));


	    do{
            printf ("\n[c] -->");
            scanf("%d", &aux3);

	    }while((aux3 > 4 || aux3 <1 ) || (aux3 == aux1 || aux3 == aux2));

	    do{
            printf ("\n[d] -->");
            scanf("%d", &aux4);

	    }while ((aux4 > 4 || aux4 < 1) || (aux4 == aux1 || aux4 == aux2 || aux4 == aux3));

        //Adiciona ao total de cada caracteristica
	    totalCinestesico += aux1;
	    totalAuditivo += aux2;
	    totalVisual += aux3;
	    totalDigital += aux4;
    }

    //Tira o percentual total de cada uma das caracteristicas e pega a maior
    totalCinestesico *= 2;
    strcpy(tipoPerfil, "Cinestésico");

    totalAuditivo *= 2;
    if(totalAuditivo > totalCinestesico) strcpy(tipoPerfil, "Auditivo");

    totalVisual *= 2;
    if(totalVisual > totalCinestesico && totalVisual > totalAuditivo) strcpy(tipoPerfil, "Visual");

    totalDigital *= 2;
    if(totalDigital > totalCinestesico && totalDigital > totalAuditivo && totalDigital > totalVisual) strcpy(tipoPerfil, "Digital");

    printf("%d\n", totalAuditivo);
    printf("%d\n", totalCinestesico);
    printf("%d\n", totalVisual);
    printf("%d\n", totalDigital);

    //Variáveis para armazenar o nome do arquivo txt
    char pathFileName[50];
    char filepath[256];

    //Monta o nome do arquivo
    strcat(pathFileName, "Resultado_");
    strcat(pathFileName, nome);
    strcat(pathFileName, "_");
    strcat(pathFileName, prontuario);
    strcat(pathFileName, ".txt");


    //Após terminar de montar, cria um arquivo com o nome no formato especificado
    snprintf (filepath, sizeof(filepath), "%s", pathFileName);
    FILE * file = fopen(filepath, "w");

    //Caso não seja possível gravar o arquivo, é exibido o perfil representacional no próprio console
    if (!file) {
        printf("Não foi possível registrar o arquivo.\nResultado: \n");
        printf("\nPorcentagem cinestesico: %d %%\n", totalCinestesico);
        printf("Porcentagem auditivo: %d %%\n", totalAuditivo);
        printf("Porcentagem visual: %d %%\n", totalVisual);
        printf("Porcentagem digital: %d %%\n", totalDigital);
        printf("Seu perfil: %s\n", tipoPerfil);
        getch();
        return;
    }

    //Escreve o material do arquivo
    fprintf(file, "==================== PERFIL REPRESENTACIONAL DE %s ====================\n", nome);
    fprintf(file, "%d Visual    %d Auditivo    %d Cinestésico   %d Digital\n", totalVisual, totalAuditivo, totalCinestesico, totalDigital);
    fprintf(file, "=============================================================================\n");

    fprintf(file, "Algumas pessoas captam melhor as mensagens do mundo exterior através da audição, são as pessoas chamadas auditivas.\n");
    fprintf(file, "Outras pessoas sentem necessidade de perguntar muito, necessitam de muitas informações e fatos. Estas são as digitais.\n");
    fprintf(file, "As cinestésicas aprendem melhor por meio das sensações táteis, como o tato, à temperatura, a umidade, as sensações internas e as emoções.\n");
    fprintf(file, "Já as pessoas visuais aprendem melhor quando se valendo da visão.\n\n");

    fprintf(file, "==============================================================================\n");
    fprintf(file, "Seu perfil é %s\n", tipoPerfil);
    fprintf(file, "==============================================================================\n");

    //Termina a gravação e exibe o arquivo
    fclose(file);
    system(filepath);
    getch();
}

//Função pra exibir documento que fala sobre o teste
int sobreOTeste()
{

    fflush(stdin);
    system("cls");


    //Cria referencia de arquivo, sai do método caso não consiga criar
    FILE  * arq;
    arq = fopen ("REFERENCIAL_TEORICO.txt" , "w+");
    if(arq == NULL)
    {
        printf("Erro ao criar o arquivo\n");
        return 1;

    }

    //Imprime o conteúdo no arquivo
    fprintf (arq , "\n===================================");
    fprintf (arq , "\nSOBRE O TESTE");
    fprintf (arq , "\n===================================");
    fprintf (arq , "\nSegundo Albert Merabian,");
    fprintf (arq,  "em seu livro “Silent Messages”,");
    fprintf(arq ,  "o poder de influência das palavras não passa de 7%%,");
    fprintf (arq , "\nenquanto a forma como as palavras são ditas e a fisiologia representam 38%% e 55%% deste poder, respectivamente.");
    fprintf (arq , "\nPara Merabian 55%% do impacto da comunicação é não-verbal. Corresponde à postura, gestos e contato visual da");
    fprintf (arq , "\npessoa enquanto se comunica.");
    fprintf (arq , "\nO tom da voz representa 38%% do impacto da comunicação.");
    fprintf (arq , "\nPor fim, as palavras propriamente ditas detêm 7%% do impacto da comunicação.");
    fprintf (arq , "\nAssim sendo, conclui Merabian, não é o que dizemos, mas como dizemos que faz a diferença na comunicação.");
    fprintf (arq , "\nAs portas da percepção são os nossos sentidos, nossos olhos, nariz, ouvidos, boca e pele, nossos únicos pontos de");
    fprintf (arq , "\ncontato com o mundo exterior. Da mesma forma que utilizamos os sentidos para filtrarmos as experiências,");
    fprintf (arq , "\nutilizamos os sentidos para estruturar nosso pensamento e nossa comunicação.");
    fprintf (arq , "\nDe acordo com a Programação Neurolinguística existem os seguintes sistemas representacionais.");
    fprintf (arq , "\n- Auditivo");
    fprintf (arq , "\n- Digital");
    fprintf (arq , "\n- Cinestésico");
    fprintf (arq , "\n- Visual");
    fprintf (arq , "\nAlgumas pessoas captam melhor as mensagens do mundo exterior através da audição, são as pessoas chamadas");
    fprintf (arq , "\nauditivas.");
    fprintf (arq , "\nOutras pessoas sentem necessidade de perguntar muito, necessitam de muitas informações e fatos. Estas são as");
    fprintf (arq , "\ndigitais.");
    fprintf (arq , "\nAs cinestésicas aprendem melhor por meio das sensações táteis, como o tato, a temperatura, a umidade, as");
    fprintf (arq , "\nsensações internas e as emoções.");
    fprintf (arq , "\nJá as pessoas visuais aprendem melhor quando se valendo da visão.");
    fprintf (arq , "\nCada pessoa tem um sistema representacional predominante e adequar a comunicação ao sistema representacional");
    fprintf (arq , "\ndominante dela é fundamental para diálogos eficientes.");



    printf ("==========================================================");
    printf ("\n\n\nInformações sobre o teste abertas com sucesso!\n\n\n");
    printf ("==========================================================");

    //Fecha o arquivo e abre no Notepad
    fclose (arq);
    system ("REFERENCIAL_TEORICO.txt");
    return 0;
}

//Função para gravar o questionário no sistema
void gravarQuestionario()
{
    //Cria o indice pra percorrer os registros
    int indice;

    //Faz referencia ao arquivo ponto dat e cria em modo escrita
    FILE * arq;
    arq = fopen ("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "w");

    //Checa se abriu, se não, sai do programa
    if ( arq == NULL )
	{
		printf ("\nErro ao abrir o arquivo!!!!!");
		getch();
		exit(0);
	}

    //Grava cada um dos registros do vetor de struct em um arquivo
    for (indice=0 ; indice <5 ; indice++)
    {
        fwrite ( &VariavelRegistro [indice], sizeof (VariavelRegistro)[indice],1,arq);
    }

    //Fecha o arquivo e retorna

    fclose (arq);
    printf ("\n\aSeu arquivo foi gerado com sucesso!");
    getch ();

}

//Mostra o menu caso o usuário seja o master
void mostrarMenuMaster()
{
    //Char para a escolha do usuário
    char escolha;
    do{
        //Chama o menu e armazena o retorno na variável
        escolha = menu();

        //Switch para prosseguir de acordo com a escolha do usuário
        switch(escolha)
        {
            case '1': gravarQuestionario(); break;
            case '2': visualizarQuestionario(); break;
            case '3': realizarTeste(); break;
            case '4': sobreOTeste(); break;
            case 'F':
            case 'f':
                printf("\nVocê escolheu sair.\n");
                break;

            default:
                printf("Escolha um valor válido!");
        }


        fflush(stdin);
        getchar();
        system("cls");

    //Repete enquanto não for dado o valor de sair
    }while(escolha != 'f' && escolha != 'F');

}

