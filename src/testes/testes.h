#ifndef TESTES_H
#define TESTES_H
#include "testes_array_dinamico.h"
#include "testes_entidade.h"
typedef struct Teste {
    const char *nome;
    int (*funcao_teste)(void);
} Teste;



Teste *Testes[] = {
  &(Teste){"TESTE ARRAY DINAMICO", testes_array_dinamico},
  &(Teste){"TESTE ARRAY ENTIDADES", teste_entidades},

  NULL,
};

#endif
