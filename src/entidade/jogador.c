#include <assert.h>
#include <raylib.h>
#include "gerenciador_entidades.h"
#include "../componente/componente.h"
#include "../componente/corpo.h"


#define VELOCIADE_HORIZONTAL_JOGADOR 5

static int id_do_jogador = 0;

void criar_jogador(Entidade *entidade)
{
    assert(entidade != NULL);

    criar_nova_entidade(entidade);

    id_do_jogador = entidade->Entidade_Info.id;

    entidade->Retangulo = (Rectangle){0,0,250,200};

    entidade->Corpo = (Corpo) {
      .Velocidade  = (Vector2){0,0},
      .Aceleracao  = (Vector2){0,0},
      .Peso        = 10,
    };

    entidade->Entidade_Info.bit_set_componentes = BIT_CORPO | BIT_RETANGULO;

    atualizar_entidade(entidade);
}

void atualizar_jogador(void)
{
    Entidade jogador;
    pegar_entidade(&jogador, id_do_jogador);

    if(IsKeyDown(KEY_LEFT))
    {
        jogador.Corpo.Velocidade.x -= VELOCIADE_HORIZONTAL_JOGADOR * GetFrameTime();
    }
    else if (IsKeyDown(KEY_RIGHT))
    {
        jogador.Corpo.Velocidade.x += VELOCIADE_HORIZONTAL_JOGADOR * GetFrameTime();
    }

    jogador.Retangulo.x += jogador.Corpo.Velocidade.x;

    atualizar_entidade(&jogador);
}
