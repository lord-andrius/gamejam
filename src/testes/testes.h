#ifndef TESTES_H
#define TESTES_H
#include "testes_array_dinamico.h"

typedef struct Teste {
    const char *nome;
    int (*funcao_teste)(void);
} Teste;



Teste *Testes[] = {
  &(Teste){"TESTE ARRAY DINAMICO", testes_array_dinamico},
  NULL,
};

#endif
