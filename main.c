#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxProdutos 10
#define Tamanho 50

void menu()
{
    printf("1 - Cadastrar Produto\n2 - Visualizar Produtos Cadastrados\n3 - Sair\n\n");
}

void CadastrarProduto(char nome[MaxProdutos][Tamanho], int quantidade[], double valor[], int indice)
    {

    printf("\nQuantidade do Produto: ");
    scanf("%d", &quantidade[indice]);
    printf("Valor do Produto: ");
    scanf("%lf", &valor[indice]);
    getchar();
    printf("Nome do Produto: ");
    fgets(nome[indice], Tamanho, stdin);
    nome[indice][strcspn(nome[indice], "\n")] = '\0';
    printf("\n");
    system("cls||clear"); // Clears screen both on Windows and Unix systems
    }

void visualizarProdutos(char nome[MaxProdutos][Tamanho], int quantidade[], double valor[], int indice)
{
    printf("\n%-12s|%-14s|%-14s|%-14s|%-14s|" , "Produtos" , "Nome" , "Quantidade" , "Valor Unidade", "Valor Total");
    for(int i = 0; i < indice; i++)
    {
        printf("\n----------------------------------------------------------------------\n");
        printf("Produto %d   |%-14s|%-14d|%-14.2lf|R$%-12.2lf|\n", i + 1, nome[i], quantidade[i], valor[i], valor[i]*quantidade[i]);
    }
}

void AlterarProdutos(char nome[MaxProdutos][Tamanho], int quantidade[], double valor[], int indice)
{
printf("\nDigite o Numero do Produto a Ser Alterado (1 a %d): ", MaxProdutos);
scanf("%d", &indice);
}
void ErroDeEntrada()
{
    printf("\nDigito Invalido, Tente Novamente.\n\n");
}
int main()
{
    int entrada, indice = 0;
    int quantidade[MaxProdutos];
    double valor[MaxProdutos];
    char nome[MaxProdutos][Tamanho];

    do
    {
        menu();
        scanf("%d", &entrada);
        switch(entrada){

        case 1:
        {
            system("cls||clear"); // Clears screen both on Windows and Unix systems
            CadastrarProduto(nome, quantidade, valor, indice);
            indice++;
            break;
        }
        case 2:
        {
            if(indice != 0)
            {
                system("cls||clear"); // Clears screen both on Windows and Unix systems
                visualizarProdutos(nome, quantidade, valor, indice);
            }
            else
            {
                system("cls||clear"); // Clears screen both on Windows and Unix systems
                printf("\nSem Produtos Cadastrados.\n");
            }
            printf("\n");
            break;
        }
        case 3:
            break;

        default :
        {
            system("cls||clear"); // Clears screen both on Windows and Unix systems
            ErroDeEntrada();
        }
        }
    }while(entrada != 3 && indice < MaxProdutos);

        if(indice == MaxProdutos)
        {
            visualizarProdutos(nome, quantidade, valor, MaxProdutos);
        }
    while(entrada != 3)
    {
        printf("\n1 - Substituir Produto Previamente Cadastrado\n2 - Visualizar Produtos cadastrados\n3 - Sair\n\n");
        scanf("%d", &entrada);
        switch(entrada){
        case 1:
            do{
                AlterarProdutos(nome, quantidade, valor, MaxProdutos);
                if(indice < 1 || indice > MaxProdutos)
                ErroDeEntrada();
            }while(indice < 1 || indice > MaxProdutos);

            CadastrarProduto(nome, quantidade, valor, indice - 1);
            break;

        case 2:
            visualizarProdutos(nome, quantidade, valor, MaxProdutos);
            break;

        case 3:
            break;

        default :
            ErroDeEntrada();
    }
    }
    return 0;
}
