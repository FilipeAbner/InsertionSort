#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <time.h>

using namespace std;

#define MAX_ELEMENTOS 100 // define o max de elementos na lista/ tamanho do vetor

class Lista
{ // criaçaõ da classe lista

public:
    unsigned tamanho; // declaração de variaveis
    int inteiros[MAX_ELEMENTOS];

    Lista()
    {
        tamanho = 0; // construtor da lista
    }

    ~Lista()
    { // destrutor
    }

    void imprime()
    { // imprime os elementos da lista

        for (unsigned u = 0; u < tamanho; u++)
            cout << inteiros[u] << endl;

        cout << "\n"
             << endl;
    }

    void insere(unsigned posicao, int inteiro)
    {
        // verifica se a posicao solicitada é inválida (maior que a lista)
        if (posicao > tamanho)
        {
            cout << "posicao invalida" << endl;
            return;
        }

        // verifica se a lista está cheia
        if (MAX_ELEMENTOS == tamanho)
        {
            cout << "lista cheia" << endl;
            return;
        }

        // desloca todos os inteiros, a partir da posicao, uma posicao a diante

        for (int i = tamanho; i > posicao; i--)
        {
            inteiros[i] = inteiros[i - 1];
        }

        // inserindo novo valor
        inteiros[posicao] = inteiro;
        tamanho++;
    }


    int InsertionSort(bool etapas){
        int contadorAcessos =0; 
        //{70[1], 1[70][12], 12[1][70], 8, 99, 72, 5, 15, 20, 91, 14, 61, 66, 41, 81, 88, 16, 21, 34, 90}
    
        for(int i=1;i<=tamanho-1 ;i++){

            int j= i-1; //j=0 //j=1
            int valor = inteiros[i];    //valor =1 //valor =12

            while((j>=0) && (valor<inteiros[j])){ //1<70 //(12<70  12<1)  
                inteiros[j+1]=inteiros[j]; //inteiros[posicao 1]=70 //inteiros[posicao 2][12]=70
                j--; //j=-1 //j=0
                contadorAcessos+=1;
            }
            inteiros[j+1]=valor; //inteiros[posicao 0][70]= 1 //inteiros[posicao 1]=12
            if (etapas == true){
                imprime();      // metodo imprime
            }
        }
        return contadorAcessos;
    }

    void geraLista(int tam)
    { // recebe o tamanho da lista
        int numero;
        srand(time(NULL)); // define a semente como null(cada lista tera valores independentes das listas passadas)
        for (unsigned j = 0; j <= tam; j++)
        { // gera os elemen-tos para a lista de acordo com o tamanho da lista com valores aleatorios entre 1 e 1000
            numero = rand() % 1000 + 1;
            insere(j, numero); // insere os elementos na lista
        }
    }

    void deletaLista()
    { // deleta todos os elementos da lista

        tamanho = 0;
    }
};

#endif