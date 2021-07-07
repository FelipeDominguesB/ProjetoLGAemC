//Bibliotecas padr�o da linguagem C
#include <stdio.h>
#include <stdlib.h>

//Biblioteca utilizada na manipula��o de strings/sequencias de texto
#include <string.h>

//Biblioteca de localiza��o
#include <locale.h>

//declarando o nome e prontu�rio como vari�veis globais, para que possa ser utilizado de maneira abrangente pelo c�digo
char nome[50], prontuario[14];

void mostrarMenuMaster()
{

}
void realizarTeste()
{

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
    if ((strlen(nome) > 0) && (nome[strlen (nome) - 1] == '\n')) nome[strlen (nome) - 1] = '\0';
    if ((strlen(prontuario) > 0) && (prontuario[strlen (prontuario) - 1] == '\n')) nome[strlen (nome) - 1] = '\0';

    //Se o usu�rio for Master, mostra o Menu, se n�o, realiza o teste
    if(strcmp(nome, "MASTER") == 0)
    {
        mostrarMenuMaster();

    }
    else{
        void realizarTeste();
    }
    return 0;
}
