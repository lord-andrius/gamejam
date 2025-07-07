#include <stdlib.h>
#include <raylib.h>

#include "../estruturas/array_dinamico.h"
#include "../componente/componente.h"

#ifndef GERENCIADOR_ENTIDADES_H
#define GERENCIADOR_ENTIDADES_H


typedef struct Entidade_Info {
    size_t id;
    size_t bit_set_componentes;
} Entidade_Info;

typedef struct Gerenciador_Entidades {
    Array_Dinamico *Entidade_Info;
    // componentes
    Array_Dinamico *Retangulo;
    Array_Dinamico *Corpo;
    Array_Dinamico *Textura;
} Gerenciador_Entidades;


typedef struct Entidade {
    Entidade_Info Entidade_Info;
    // componentes
    Rectangle     Retangulo;
    Corpo         Corpo;
    Texture       Textura;
} Entidade;



void criar_nova_entidade(Entidade *entidade);
void pegar_entidade(Entidade *entidade, size_t id);
void atualizar_entidade(Entidade *entidade);
Gerenciador_Entidades *pegar_gerenciador_entidades(void);

//void deletar_entidade(Entidade *entidade);


#endif
