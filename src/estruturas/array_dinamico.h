#ifndef ARRAY_DINAMICO_H
#define ARRAY_DINAMICO_H

#define CAPACIDADE_INICIAL 8

typedef struct Array_Dinamico {
    size_t tamanho;
    size_t capacidade;
    size_t tamanho_tipo;
    void * buffer;
} Array_Dinamico;


Array_Dinamico *criar_array_dinamico(size_t tamanho_tipo);
void deletar_array_dinamico(Array_Dinamico **array);
void pegar_posicao_array_dinamico(Array_Dinamico *array, size_t posicao, void *item);
void atualizar_posicao_array_dinamico(Array_Dinamico *array, size_t posicao, void *item_novo);
void deletar_posicao_array_dinamico(Array_Dinamico *array, size_t posicao, void *item_antigo);
void adicionar_item_array_dinamico(Array_Dinamico *array, size_t posicao, void *novo_item);

#endif
