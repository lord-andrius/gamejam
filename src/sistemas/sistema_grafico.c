#include <raylib.h>
#include <assert.h>
#include "../entidade/gerenciador_entidades.h"
#include "../componente/componente.h"

void sistema_grafico(void)
{
    Gerenciador_Entidades *gerenciador_entidades = pegar_gerenciador_entidades();
    assert(gerenciador_entidades->Entidade_Info != NULL);

    int qtd_entidades = gerenciador_entidades->Entidade_Info->tamanho;

    Entidade_Info *info = (Entidade_Info *)gerenciador_entidades->Entidade_Info->buffer;
    Rectangle *retangulos = (Rectangle *)gerenciador_entidades->Retangulo->buffer;

    for (size_t i = 0; i < qtd_entidades; i++)
    {
        if ((info[i].bit_set_componentes & BIT_RETANGULO) == 0) // se a entidade não houver retangulo
        {
            continue;
        }
        DrawRectangleLinesEx(retangulos[i], 1.0, RED);
    }
}
