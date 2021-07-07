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
            case 5: printf("Você escolheu sair.\n"); break;

            default:
                printf("Escolha um valor válido!");
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

    fclose (arq);
    system ("REFERENCIAL_TEORICO.txt");
    return 0;
}

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
    if ((strlen(nome) > 0) && (nome[strlen (nome)] == '\n')) nome[strlen (nome) - 1] = '\0';
    if ((strlen(prontuario) > 0) && (prontuario[strlen (prontuario) - 1] == '\n')) nome[strlen (nome) - 1] = '\0';
    //Se o usuário for Master, mostra o Menu, se não, realiza o teste
    if(strcmp(nome, "MASTER") == 0)
    {
        printf("Você logou como master!");
        getch();
        system("cls");
        mostrarMenuMaster();

    }
    else{

        void realizarTeste();
    }
    return 0;
}
