#include "gerenciador_entidades.h"
#include  "../estruturas/array_dinamico.h"
#include <raylib.h>
#include <assert.h>

#include "../componente/componente.h"

static Gerenciador_Entidades gerenciador_entidades = {0};

static size_t contador = 0;

void criar_nova_entidade(Entidade *entidade)
{
    assert(entidade != NULL);

    if (gerenciador_entidades.Entidade_Info == NULL) //primeira vez que criamos uma nova entidade
    {
        gerenciador_entidades.Entidade_Info = criar_array_dinamico(sizeof(Entidade_Info));
        gerenciador_entidades.Retangulo = criar_array_dinamico(sizeof(Rectangle));
        gerenciador_entidades.Corpo = criar_array_dinamico(sizeof(Corpo));


        assert(gerenciador_entidades.Entidade_Info != NULL);
        assert(gerenciador_entidades.Retangulo != NULL);
        assert(gerenciador_entidades.Corpo != NULL);
    }

    adicionar_item_array_dinamico(gerenciador_entidades.Entidade_Info, gerenciador_entidades.Entidade_Info->tamanho, &(Entidade_Info){.id = contador++, .bit_set_componentes = 0});
    adicionar_item_array_dinamico(gerenciador_entidades.Retangulo, gerenciador_entidades.Retangulo->tamanho, &(Rectangle){0});
    adicionar_item_array_dinamico(gerenciador_entidades.Corpo, gerenciador_entidades.Corpo->tamanho, &(Corpo){0});

    pegar_posicao_array_dinamico(gerenciador_entidades.Entidade_Info, gerenciador_entidades.Entidade_Info->tamanho - 1, &entidade->Entidade_Info);
    pegar_posicao_array_dinamico(gerenciador_entidades.Retangulo, gerenciador_entidades.Retangulo->tamanho - 1, &entidade->Retangulo);
    pegar_posicao_array_dinamico(gerenciador_entidades.Corpo, gerenciador_entidades.Corpo->tamanho - 1, &entidade->Corpo);
}

static size_t indice_da_entidade(Entidade *entidade)
{
    size_t indice;
    int achou = 0;
    Entidade_Info entidade_info;
    assert(entidade != NULL);
    for(size_t i = 0; i < gerenciador_entidades.Entidade_Info->tamanho; i++)
    {
        pegar_posicao_array_dinamico(gerenciador_entidades.Entidade_Info, i, &entidade_info);
        if (entidade_info.id == entidade->Entidade_Info.id)
        {
            indice = i;
            achou = 1;
            break;
        }
    }
    assert(achou); // está procurando uma entidade que não existe

    return indice;
}

void pegar_entidade(Entidade *entidade, size_t id)
{
    assert(entidade != NULL);

    entidade->Entidade_Info.id = id;

    size_t indice = indice_da_entidade(entidade);

    pegar_posicao_array_dinamico(gerenciador_entidades.Entidade_Info, indice, &entidade->Entidade_Info);
    pegar_posicao_array_dinamico(gerenciador_entidades.Retangulo, indice, &entidade->Retangulo);
    pegar_posicao_array_dinamico(gerenciador_entidades.Corpo, indice, &entidade->Corpo);
}
