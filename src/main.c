#include "raylib.h"

#define LARGURA_TELA 1280
#define ALTURA_TELA 720
#define TITULO_JANELA "PROJETO X"

int main(void)
{
    InitWindow(LARGURA_TELA, ALTURA_TELA, TITULO_JANELA);

    while (!WindowShouldClose())
    {
            BeginDrawing();
            ClearBackground(WHITE);
            EndDrawing();
    }

    CloseWindow();

}
