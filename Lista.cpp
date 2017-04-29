#include <iostream>
#include <cstdlib>
#include <clocale>
#include <windows.h>

using namespace std;

const int TAM = 7;

int  lista[TAM];
int tamanho = 0;

void insereLista(int valor) {
    system("cls");
    if (tamanho == TAM) {
        cout << "\n\n\n\n\n\n\t\t\tLista Cheia!";
        Sleep(2000);
        return;
    }
    int i;
    for (i = tamanho; i>0 && valor<lista[i-1]; i--) {
        lista[i] = lista[i-1];
    }
    lista[i] = valor;
    tamanho++;
    cout << "\n\n\n\n\n\n\t\tValor inserido na lista com sucesso!";
    Sleep(2000);
}

void removeLista(int posicao) {
    system("cls");
    if (posicao < 0 || posicao >= tamanho) {
        cout << "\n\n\n\n\n\n\t\tPosi��o inv�lida!";
        Sleep(2000);
        return;
    }
    int i;
    if (lista[posicao] > 0) {
        lista[posicao-1] = lista[posicao];
    }
    lista[posicao] = 0;
    tamanho--;
    cout << "\n\n\n\n\n\n\t\tValor removido da lista com sucesso!";
    Sleep(2000);
}

void buscaLista(int valor) {
    system("cls");
    if (tamanho == 0) {
        cout << "\n\n\n\n\n\n\t    Lista Vazia! Insira um novo elemento.";
        Sleep(2000);
        return;
    }
    int i;
    for (i=0; i<TAM; i++) {
        if (lista[i] == valor) {
            cout << "\n\n\n\n\n\t\tValor encontrado na posi��o: " << i+1 << "\n\n\t";
            system("pause");
            return;
        }
        i++;
    }
    cout << "\n\n\n\n\n\n\t  O valor digitador n�o se encontra na lista!";
    Sleep(2500);
}

void imprime() {
    system("cls");
    if (tamanho == 0) {
        cout << "\n\n\n\n\n\n\t    Lista Vazia! Insira um novo elemento.";
        Sleep(2000);
        return;
    }
    int i;
    cout << "\n\n\t\t\t     Posi��o   Valores\n";
    for (i=0; i<TAM; i++) {
        cout << "\t\t\t\t";
        cout << i << "\t[" << lista[i] <<"]\n";
    }
    cout << "\n\n\t\t";
    system("pause");
}

void recuperaLista(int posicao) {
    system("cls");
    if (tamanho == 0) {
        cout << "\n\n\n\n\n\n\t    Lista Vazia! Insira um novo elemento.";
        Sleep(2000);
        return;
    }
    if (posicao < 0 || posicao >= tamanho) {
        cout << "\n\n\n\n\n\n\t\t\tPosi��o inv�lida!";
        Sleep(2000);
        return;
    }
    cout << "\n\n\n\n\n\n\tO valor que est� armazenado na posi��o informada �: " << lista[posicao] << "\n";
    Sleep(2000);
}

void menu() {
    system("cls");
    int aux;
    cout << "\n\n\t   Bem vindo ao sistema de estrutura em lista!\n\n";
    cout << "\tPara inserir um novo elemento na lista digite:  1\n";
    cout << "\tPara remover um elemento da lista digite:       2\n";
    cout << "\tPara buscar um elemento na lista digite:        3\n";
    cout << "\tPara exibir a lista completa digite:            4\n";
    cout << "\tPara recuperar um elemento da lista digite:     5\n";
    cout << "\tPara sair do programa digite                    6\n";
    cout << "\n\t\t\tResposta: ";
    cin >> aux;
    switch (aux) {
    case 1:
        system("cls");
        cout << "\n\n\n\n\n\n\tDigite o valor que deseja inserir na lista: ";
        cin >> aux;
        cout << "\n";
        insereLista(aux);
        menu();
    case 2:
        system("cls");
        cout << "\n\n\n\n\n\n\tDigite a posi��o do valor que deseja remover: ";
        cin >> aux;
        cout << "\n";
        removeLista(aux);
        menu();
    case 3:
        system("cls");
        cout << "\n\n\n\n\n\n\tDigite o valor que deseja buscar na lista: ";
        cin >> aux;
        cout << "\n";
        buscaLista(aux);
        menu();
    case 4:
        imprime();
        menu();
    case 5:
        system("cls");
        cout << "\n\n\n\n\n\n\t\t  Digite a posi��o do elemento\n\t\tque deseja recuperar da lista: ";
        cin >> aux;
        cout << "\n";
        recuperaLista(aux);
        menu();
    case 6:
        system("cls");
        cout << "\n\n\n\n\n\tObrigado pela prefer�ncia, at� a pr�xima!\n";
        exit(0);
    default:
        system("cls");
        cout << "\n\n\n\n\n\n\t    Comando inv�lido, digite outro n�mero!";
        Sleep(2000);
        menu();
    }
}

int main() {
    setlocale(LC_ALL, "");
    menu();

    return 0;
}
