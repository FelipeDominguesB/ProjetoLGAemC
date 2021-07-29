//Bibliotecas padr�o da linguagem C
#include <stdio.h>
#include <stdlib.h>

//Biblioteca pra utilizar fun��o getch
#include <conio.h>

//Biblioteca utilizada na manipula��o de strings/sequencias de texto
#include <string.h>

//Biblioteca de localiza��o
#include <locale.h>

//declarando o nome e prontu�rio como vari�veis globais, para que possa ser utilizado de maneira abrangente pelo c�digo
char nome[50], prontuario[14];

int sobreOTeste();
char menu(void);
void realizarTeste();
void gravarQuestionario();
void mostrarMenuMaster();

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



reregFrases  VariavelRegistro [5] = {

	{1,"Eu tomo decis�es importantes baseadx em",0, "intui��o",0,"o que me soa melhor",0,"o que me parece melhor",0,"um estudo preciso e minucioso do assunto"},
	{2, "Durante uma discuss�o sou mais influenciadx por",0,"se eu entro em contato ou n�o com o sentimentos reais do outro",0,"o tom de voz da outra pessoa",0,
        "se eu posso ou n�o ver o argumento da outra pessoa",0,"a l�gica do argumento da outra pessoa"},
    {3,"Eu comunico mais facilmente o que passa comigo",0,"pelos sentimentos que compartilho",0,"pelo tom da minha voz",0,"do modo como me visto ou aparento",0,
       "pelas palavras que escolho"},
    {4,"� muito f�cil pra mim",0,"escolher os m�veis mais confort�veis",0,"achar o volume e sintonia ideais num sistema de som",0,
	   "escolher a combina��o de cores mais ricas e atraentes",0,"selecionar o ponto mais relevante relativo a um assunto interessante"},
	{5, "Eu me percebo assim",0,"eu sou muito sens�vel � maneira como a roupa veste meu corpo",0,"se estou muito em sintonia com os sons dos ambientes",0,
	    "se eu respondo formente �s cores e apar�ncia de uma sala",0,"se sou muito capaz de raciocinar com os fatos e dados novos"}
};




int main()
{

    //Definindo a localiza��o do console como Portugu�s
    setlocale(LC_ALL, "Portuguese");

    //Pegando o nome do usu�rio atrav�s do fgets e limpando o buffer do teclado
    printf("\n\nINFORME SEU NOME: ");
    fgets(nome, 50, stdin);
    fflush(stdin);

    //Pegando o prontu�rio do usu�rio atrav�s do fgets e limpando o buffer do teclado
    printf("\nINFORME SEU PRONTU�RIO: ");
    fgets(prontuario, 14, stdin);
    fflush(stdin);

    //Caso o ultimo digito seja uma quebra de linha (ou seja, \n), remove ela
    if ((strlen(nome) > 0) && (nome[strlen (nome) - 1] == '\n')) nome[strlen (nome) - 1] = '\0';

    if ((strlen(prontuario) > 0) && (prontuario[strlen (prontuario) - 1] == '\n')) prontuario[strlen (prontuario) - 1] = '\0';

    //Se o usu�rio for Master, mostra o Menu, se n�o, realiza o teste
    if(strcmp(nome, "MASTER") == 0)
    {
        printf("Voc� logou como master!");
        getch();
        system("cls");
        mostrarMenuMaster();

    }
    else{

        realizarTeste();
    }
    return 0;
}



char menu (void)
{
    char opc;
    printf ("\n=========================================");
    printf ("\nTESTE DE SISTEMAS REPRESENTACIONAIS");
    printf ("\n=========================================");
    printf ("\n1. Cadastrar questin�rio");
    printf ("\n2. Visuaizar questin�rio");
    printf ("\n3. Realizar teste");
    printf ("\n4. Sobre o teste");
    printf ("\nF. FIM");
    printf ("\n=========================================");
    printf ("\n                   Escolha sua op��o:\t");
    opc = getche ();
    fflush (stdin);
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
        printf("N�o h� registro do teste no sistema");
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

void realizarTeste (void)
{
    system("cls");


    char tipoPerfil[15];

    FILE * arq;
    arq = fopen ("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "r");
    int counter = 0;

    reregFrases newFrases[5];
    reregFrases regaux;
    if(arq == NULL)
    {
        printf("N�o h� registro do teste no sistema");
        getch();
        exit(0);

    }

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
            counter++;
	   }
    }
    fclose (arq);

    int aux1, aux2, aux3, aux4;
    int totalAuditivo = 0, totalCinestesico = 0, totalDigital = 0, totalVisual = 0;
    for(counter = 0; counter < 5; counter++)
    {
        printf("\n%d - %s\n", newFrases[counter].nroFrases, newFrases[counter].Frase);
        printf("a) %s\n", newFrases[counter].item_1);
        printf("b) %s\n", newFrases[counter].item_2);
        printf("c) %s\n", newFrases[counter].item_3);
        printf("d) %s\n", newFrases[counter].item_4);

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

	    newFrases[counter].cinestesico = aux1;
	    newFrases[counter].auditivo = aux2;
	    newFrases[counter].visual = aux3;
	    newFrases[counter].digital = aux4;

	    totalCinestesico += aux1;
	    totalAuditivo += aux2;
	    totalVisual += aux3;
	    totalDigital += aux4;
    }

    totalCinestesico *= 2;
    strcpy(tipoPerfil, "Cinest�sico");

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
    char pathFile[50];
    char filepath[256];

    strcat(pathFile, "Resultado_");
    strcat(pathFile, nome);
    strcat(pathFile, "_");
    strcat(pathFile, prontuario);
    strcat(pathFile, ".txt");
    printf("%s", pathFile);


    snprintf (filepath, sizeof(filepath), "%s", pathFile);
    FILE * file = fopen(filepath, "w");
    if (!file) {
        printf("N�o foi poss�vel registrar o arquivo.\nResultado: \n");
        printf("\nPorcentagem cinestesico: %d %%\n", totalCinestesico);
        printf("Porcentagem auditivo: %d %%\n", totalAuditivo);
        printf("Porcentagem visual: %d %%\n", totalVisual);
        printf("Porcentagem digital: %d %%\n", totalDigital);
        printf("Seu perfil: %s\n", tipoPerfil);
    }


    fprintf(file, "==================== PERFIL REPRESENTACIONAL DE %s ====================\n", nome);
    fprintf(file, "%d Visual    %d Auditivo    %d Cinest�sico   %d Digital\n", totalVisual, totalAuditivo, totalCinestesico, totalDigital);
    fprintf(file, "=============================================================================\n");

    fprintf(file, "Algumas pessoas captam melhor as mensagens do mundo exterior atrav�s da audi��o, s�o as pessoas chamadas auditivas.\n");
    fprintf(file, "Outras pessoas sentem necessidade de perguntar muito, necessitam de muitas informa��es e fatos. Estas s�o as digitais.\n");
    fprintf(file, "As cinest�sicas aprendem melhor por meio das sensa��es t�teis, como o tato, � temperatura, a umidade, as sensa��es internas e as emo��es.\n");
    fprintf(file, "J� as pessoas visuais aprendem melhor quando se valendo da vis�o.\n\n");

    fprintf(file, "==============================================================================\n");
    fprintf(file, "Seu perfil � %s\n", tipoPerfil);
    fprintf(file, "==============================================================================\n");

    fclose(file);

    printf("%s\n", filepath);
    system(filepath);
    getch();
}

int sobreOTeste()
{

    fflush(stdin);
    system("cls");

    FILE  * arq;
    arq = fopen ("REFERENCIAL_TEORICO.txt" , "w+");
    if(arq == NULL)
    {
        printf("Erro ao criar o arquivo\n");
        return 1;

    }
    fprintf (arq , "\n===================================");
    fprintf (arq , "\nSOBRE O TESTE");
    fprintf (arq , "\n===================================");
    fprintf (arq , "\nSegundo Albert Merabian,");
    fprintf (arq,  "em seu livro �Silent Messages�,");
    fprintf(arq ,  "o poder de influ�ncia das palavras n�o passa de 7%%,");
    fprintf (arq , "\nenquanto a forma como as palavras s�o ditas e a fisiologia representam 38%% e 55%% deste poder, respectivamente.");
    fprintf (arq , "\nPara Merabian 55%% do impacto da comunica��o � n�o-verbal. Corresponde � postura, gestos e contato visual da");
    fprintf (arq , "\npessoa enquanto se comunica.");
    fprintf (arq , "\nO tom da voz representa 38%% do impacto da comunica��o.");
    fprintf (arq , "\nPor fim, as palavras propriamente ditas det�m 7%% do impacto da comunica��o.");
    fprintf (arq , "\nAssim sendo, conclui Merabian, n�o � o que dizemos, mas como dizemos que faz a diferen�a na comunica��o.");
    fprintf (arq , "\nAs portas da percep��o s�o os nossos sentidos, nossos olhos, nariz, ouvidos, boca e pele, nossos �nicos pontos de");
    fprintf (arq , "\ncontato com o mundo exterior. Da mesma forma que utilizamos os sentidos para filtrarmos as experi�ncias,");
    fprintf (arq , "\nutilizamos os sentidos para estruturar nosso pensamento e nossa comunica��o.");
    fprintf (arq , "\nDe acordo com a Programa��o Neurolingu�stica existem os seguintes sistemas representacionais.");
    fprintf (arq , "\n- Auditivo");
    fprintf (arq , "\n- Digital");
    fprintf (arq , "\n- Cinest�sico");
    fprintf (arq , "\n- Visual");
    fprintf (arq , "\nAlgumas pessoas captam melhor as mensagens do mundo exterior atrav�s da audi��o, s�o as pessoas chamadas");
    fprintf (arq , "\nauditivas.");
    fprintf (arq , "\nOutras pessoas sentem necessidade de perguntar muito, necessitam de muitas informa��es e fatos. Estas s�o as");
    fprintf (arq , "\ndigitais.");
    fprintf (arq , "\nAs cinest�sicas aprendem melhor por meio das sensa��es t�teis, como o tato, a temperatura, a umidade, as");
    fprintf (arq , "\nsensa��es internas e as emo��es.");
    fprintf (arq , "\nJ� as pessoas visuais aprendem melhor quando se valendo da vis�o.");
    fprintf (arq , "\nCada pessoa tem um sistema representacional predominante e adequar a comunica��o ao sistema representacional");
    fprintf (arq , "\ndominante dela � fundamental para di�logos eficientes.");



    printf ("==========================================================");
    printf ("\n\n\nInforma��es sobre o teste abertas com sucesso!\n\n\n");
    printf ("==========================================================");

    fclose (arq);
    system ("REFERENCIAL_TEORICO.txt");
    return 0;
}

void gravarQuestionario()
{
    int indice;
    FILE * arq;
    arq = fopen ("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "w");

    if ( arq == NULL )
	{
		printf ("\nErro ao abrir o arquivo!!!!!");
		getch();
		exit(0);
	}
    for (indice=0 ; indice <5 ; indice++)
    {
        fwrite ( &VariavelRegistro [indice], sizeof (VariavelRegistro)[indice],1,arq);
    }

    fclose (arq);
    printf ("\n\aSeu arquivo foi gerado com sucesso!");
    getch ();

}

void mostrarMenuMaster()
{
    char escolha;
    do{

        escolha = menu();
        switch(escolha)
        {
            case '1': gravarQuestionario(); break;
            case '2': visualizarQuestionario(); break;
            case '3': realizarTeste(); break;
            case '4': sobreOTeste(); break;
            case 'F':
            case 'f':
                printf("\nVoc� escolheu sair.\n");
                break;

            default:
                printf("Escolha um valor v�lido!");
        }

        fflush(stdin);
        getchar();
        system("cls");


    }while(escolha != 'f' && escolha != 'F');

}

