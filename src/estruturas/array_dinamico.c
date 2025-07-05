#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include "array_dinamico.h"


Array_Dinamico *criar_array_dinamico(size_t tamanho_tipo)
{
    assert(tamanho_tipo > 0); // não podemos guardar um tipo sem tamanho

    Array_Dinamico *array = malloc(sizeof(struct Array_Dinamico));
    assert(array != NULL);


    array->tamanho = 0;
    array->capacidade = CAPACIDADE_INICIAL;
    array->tamanho_tipo = tamanho_tipo;
    array->buffer = malloc(array->capacidade * tamanho_tipo);
    assert(array->buffer != NULL);


    return array;

}

void deletar_array_dinamico(Array_Dinamico **array)
{
    assert(array != NULL);
    assert(*array != NULL);

    if((*array)->buffer != NULL) {
        free((*array)->buffer);
    }

    free(*array);
    *array = NULL;
}

void pegar_posicao_array_dinamico(Array_Dinamico *array, size_t posicao, void *item)
{
    assert(array != NULL);
    assert(array->tamanho > posicao); // garantido que não haverá acesso fora da memória do array
    assert(item != NULL);
    memcpy(item, (void *)((char *)array->buffer + (array->tamanho_tipo * posicao)), array->tamanho_tipo);
}

void atualizar_posicao_array_dinamico(Array_Dinamico *array, size_t posicao, void *item_novo)
{
    assert(array != NULL);
    assert(array->tamanho > posicao); // garantido que não haverá acesso fora da memória do array

    memcpy(
        (void *)((char *)array->buffer + (array->tamanho_tipo * posicao)),
        item_novo,
        array->tamanho_tipo
    );

}

void deletar_posicao_array_dinamico(Array_Dinamico *array, size_t posicao, void *item_antigo)
{
    assert(array != NULL);
    assert(array->tamanho > posicao); // garantido que não haverá acesso fora da memória do array

    if (item_antigo != NULL)
        pegar_posicao_array_dinamico(array, posicao, item_antigo);

    if (posicao != array->tamanho - 1) // se não for a última posição
    {
        memmove(
            (void *)((char *)array->buffer) + (array->tamanho_tipo * posicao),
            (void *)((char *)array->buffer) + (array->tamanho_tipo * (posicao + 1)),
            (array->tamanho - (posicao + 1)) * array->tamanho_tipo
        );
    }
    array->tamanho--;
}

static void crescer_array_buffer_se_houver_necessidade(Array_Dinamico *array)
{
    assert(array != NULL);



    if (array->tamanho == array->capacidade)
    {
        array->capacidade *= 2;

        array->buffer = realloc(array->buffer, array->tamanho_tipo * array->capacidade);
        assert(array->buffer != NULL);

    }
}

void adicionar_item_array_dinamico(Array_Dinamico *array, size_t posicao, void *novo_item)
{

    assert(array != NULL);
    
    if (posicao > array->tamanho) assert(1); // garantido que não haverá acesso fora da memória do array
    crescer_array_buffer_se_houver_necessidade(array);
    if (posicao < array->tamanho ) {
        memmove(
            (void *)(((char *)array->buffer) + (array->tamanho_tipo * (posicao + 1))),
            (void *)(((char *)array->buffer) + (array->tamanho_tipo * posicao)),
            (array->tamanho - (posicao + 1 )) * array->tamanho_tipo
        );
    }
    array->tamanho++;
    atualizar_posicao_array_dinamico(array, posicao, novo_item);
}
