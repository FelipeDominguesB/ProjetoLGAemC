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

void mostrarMenuMaster()
{
    int escolha = 0;

    do{

        printf("Menu lorem ipsum\n4) Sobre o teste.\n5) Sair\nEscolha: ");
        scanf("%d", &escolha);

        switch(escolha)
        {

            case 4: sobreOTeste(); break;
            case 5: printf("Voc� escolheu sair.\n"); break;

            default:
                printf("Escolha um valor v�lido!");
        }

        fflush(stdin);
        getchar();
        system("cls");


    }while(escolha != 5);

}
void realizarTeste()
{

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
    if ((strlen(nome) > 0) && (nome[strlen (nome)] == '\n')) nome[strlen (nome) - 1] = '\0';
    if ((strlen(prontuario) > 0) && (prontuario[strlen (prontuario) - 1] == '\n')) nome[strlen (nome) - 1] = '\0';
    //Se o usu�rio for Master, mostra o Menu, se n�o, realiza o teste
    if(strcmp(nome, "MASTER") == 0)
    {
        printf("Voc� logou como master!");
        getch();
        system("cls");
        mostrarMenuMaster();

    }
    else{

        void realizarTeste();
    }
    return 0;
}
