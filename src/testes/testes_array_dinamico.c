#include <stdio.h>
#include "testes_array_dinamico.h"
#include <assert.h>
#include "../estruturas/array_dinamico.h"

int testes_array_dinamico(void)
{
    Array_Dinamico *array = criar_array_dinamico(sizeof(int));

    if (array->tamanho != 0) assert(0);// era pra ser zero



    for (int i = 0; i < 100; i++)
    {

        adicionar_item_array_dinamico(array, i, &i);

        if (array->tamanho != i + 1) assert(0);// era pra ter adicionado um elemento

        int valor_adicionado = 0;
        pegar_posicao_array_dinamico(array, i, &valor_adicionado);

        if (valor_adicionado != i) assert(0);
    }



    int valor_antigo = 0;
    deletar_posicao_array_dinamico(array, 50, &valor_antigo);

    if (array->tamanho != 99) assert(0); // era pra ter diminuído o tamanho

    if (valor_antigo != 50) assert(0); // ta deletando errado


    int indice50 = 0;
    pegar_posicao_array_dinamico(array, 50, &indice50);


    if (indice50 != 51) assert(0); // era pra ter movido a segunda parte do vetor

    deletar_array_dinamico(&array);
    if (array != NULL) assert(0); // erro o array deveria estar nulo após ser deletado

    return 0;// zero indica sucesso no teste
}
