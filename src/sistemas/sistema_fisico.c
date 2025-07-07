#include <stdio.h>
#include <raylib.h>
#include <assert.h>
#include "../entidade/gerenciador_entidades.h"
#include "../componente/componente.h"
#include "sistema_fisico.h"

#define GRAVIDADE 125

void sistema_fisico(void)
{
    Gerenciador_Entidades *gerenciador_entidades = pegar_gerenciador_entidades();
    assert(gerenciador_entidades->Entidade_Info != NULL);

    int qtd_entidades = gerenciador_entidades->Entidade_Info->tamanho;

    Entidade_Info *info = (Entidade_Info *)gerenciador_entidades->Entidade_Info->buffer;
    Corpo *corpos = (Corpo *)gerenciador_entidades->Corpo->buffer;
    Rectangle *retangulos = (Rectangle *)gerenciador_entidades->Retangulo->buffer;


    for (size_t i = 0; i < qtd_entidades; i++)
    {
        if ((info[i].bit_set_componentes & (BIT_CORPO || BIT_RETANGULO)) == 0) // se a entidade não houver retangulo
        {
            continue;
        }

        corpos[i].Aceleracao.y += GRAVIDADE * corpos[i].Peso;

        float tempo = GetFrameTime();


        retangulos[i].y = retangulos[i].y + corpos[i].Velocidade.y * tempo + (corpos[i].Aceleracao.y * (tempo * tempo) / 2);

        corpos[i].Velocidade.y += corpos[i].Aceleracao.y * tempo;
    }
}
