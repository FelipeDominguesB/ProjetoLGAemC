//Bibliotecas padrão da linguagem C
#include <stdio.h>
#include <stdlib.h>

//Biblioteca utilizada na manipulação de strings/sequencias de texto
#include <string.h>

//Biblioteca de localização
#include <locale.h>

//declarando o nome e prontuário como variáveis globais, para que possa ser utilizado de maneira abrangente pelo código
char nome[50], prontuario[14];

void mostrarMenuMaster()
{

}
void realizarTeste()
{

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
    if ((strlen(nome) > 0) && (nome[strlen (nome) - 1] == '\n')) nome[strlen (nome) - 1] = '\0';
    if ((strlen(prontuario) > 0) && (prontuario[strlen (prontuario) - 1] == '\n')) nome[strlen (nome) - 1] = '\0';

    //Se o usuário for Master, mostra o Menu, se não, realiza o teste
    if(strcmp(nome, "MASTER") == 0)
    {
        mostrarMenuMaster();

    }
    else{
        void realizarTeste();
    }
    return 0;
}
