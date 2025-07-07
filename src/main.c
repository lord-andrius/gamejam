#include "raylib.h"

#define LARGURA_TELA 1280
#define ALTURA_TELA 720
#define TITULO_JANELA "PROJETO X"

#include "entidade/gerenciador_entidades.h"
#include "entidade/jogador.h"
#include "sistemas/sistema_grafico.h"
#include "sistemas/sistema_fisico.h"

int main(void)
{
    Entidade jogador;

    criar_jogador(&jogador);

    InitWindow(LARGURA_TELA, ALTURA_TELA, TITULO_JANELA);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
            atualizar_jogador();
            sistema_fisico();
            BeginDrawing();
            ClearBackground(WHITE);
            sistema_grafico();
            EndDrawing();
    }

    CloseWindow();

}
