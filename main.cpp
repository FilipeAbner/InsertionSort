 
#include <iostream>
#include "ListaEstatica.h"
#include <stdlib.h>
#include <fstream>

using namespace std;
#define MAX_VETOR 100 // define o tamanho maximo do vetor

/*Link Para video no YouTube:
https://youtu.be/l00kpCeBjgw*/

int main()
{
    int valor[20] = {70, 1, 12, 8, 99, 72, 5, 15, 20, 91, 14, 61, 66, 41, 81, 88, 16, 21, 34, 90}, etapa, numero; /*declaraçao de variaveis e do
                                                                                                                   vetor para a etapa 1*/
    Lista Lista1;                                                                                                 // declaracao das listas
    Lista Lista2;
    int acessosEtapa1 = 0, acessosEtapa2 = 0, acessosUnitariosEtapa2 = 0; // variaveis para contar os acessos
    int aux = 0, tam = 0;
    ofstream arquivo; // criaçao de um arquivo para armazenar a quantidade de acessos a memoria de cada lista gerada(etapa 2)

    do
    { // loop para repetição das etapas
        cout << "\nDigite:\n1 - Etapa 1\n2 - etapa 2 \n3 - parar\n"
             << endl;
        cin >> etapa; // recebe o valor para execução das etapas 1 e 2 ou cancelar
        cout << "\n"
             << endl;

        if (etapa == 1)
        {
            for (unsigned i = 0; i < 20; i++)
            {
                Lista1.insere(i, valor[i]); // invoca o metodo insere da lista para inserir os valores do vetor
            }
            Lista1.imprime();                        // invoca o metodo imprime para imprimir os elementos da lista
            acessosEtapa1 = Lista1.InsertionSort(true); // recebe o retorno do metodo bubble sort que ira forncer o numero
                                                     // de acessos a memoria e fara a ordenaçao da lista
            cout << "\n"
                 << "Total de Acessos=" << acessosEtapa1 << endl; // imprime o numero de acessos

            Lista1.deletaLista(); // deleção da lista e zera os acessos obtidos
            acessosEtapa1 = 0;    //(caso rode novamente o loop a lista e a variavel de contagem de acessos necessitam
                                  // estar vazias)
        }
        else if (etapa == 2)
        {
            arquivo.open("TabelaDeAcessos.csv"); // cria o arquivo csv para receber o dados de acessos
            arquivo << "Acessos"
                    << ", "
                    << "Qtd.Elementos" << endl; // adiciona o nome das colunas
            while (tam != MAX_VETOR)
            { // 10   //enquanto o tamanho da lista nao for = 100 o while continuara a rodar

                Lista2.geraLista(tam);          // invocar o metodo gera lista para criar a lista de tamanho (tam)
                aux = Lista2.InsertionSort(false); // aux recebe o retorno do metodo bubble sort que ira forncer o numero
                                                // de acessos a memoria e fara a ordenaçao da lista

                acessosEtapa2 = acessosEtapa2 + aux; // contagem do total de acessos a memoria
                acessosUnitariosEtapa2 = aux;        // contagem dos acessos a memoria de cada lista gerada

                cout << "\n"        // imprime os acessos a memoria de cada lista gerada
                     << "Acessos[tamanho=" << tam + 1 << "]" << acessosUnitariosEtapa2 << endl;
                
                Lista2.deletaLista(); // deleta a lista
                tam++;                // incrementa o tamanho para gerar uma nova lista

                arquivo << acessosUnitariosEtapa2 << ", " << tam << endl; // imprime a quantidade de acessos a memoria
                                                                          // de cada lista gerada dentro do arquivo csv
            } 
            cout << "\n"
                 << "Total de Acessos=" << acessosEtapa2 << endl; // imprime a quantidade total de acessos no
                                                                  // final da geração das 100 listas
            arquivo.close(); // fecha o arquivo

            acessosEtapa2 = 0, aux = 0, acessosUnitariosEtapa2 = 0, tam = 0; //(caso rode novamente o loop a lista e a variavel de
                                                                             // contagem de acessos necessitam estar vazias)
        }
        else if (etapa == 3)
        {
        }
        else
        {
            cout << "numero invalido" << endl; // se algum outro numero for digitado imprimira a mensagem
        }
    } while (etapa != 3);

    return 0;
};