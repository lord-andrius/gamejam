#include <stdio.h>
#include <raylib.h>
#include <assert.h>
#include "../entidade/gerenciador_entidades.h"
#include "../componente/componente.h"
#include "sistema_fisico.h"
#include "../assets/assets.h"
#include <math.h>


#define GRAVIDADE 10

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

        Vector2 posicaoAnterior = (Vector2){retangulos[i].x,retangulos[i].y};

        corpos[i].Aceleracao.y += GRAVIDADE * corpos[i].Peso;

        float tempo = GetFrameTime();


        retangulos[i].y = retangulos[i].y + corpos[i].Velocidade.y * tempo + (corpos[i].Aceleracao.y * (tempo * tempo) / 2);

        corpos[i].Velocidade.y += corpos[i].Aceleracao.y * tempo;

        int tileX = 0;
        int tileY = 0;


        for(const char *caractere = *cenarios; *caractere != '\0'; caractere++)
        {
            if (*caractere == '-')
            {
                Rectangle tile = (Rectangle){tileX, tileY, 80, 80};

                if (CheckCollisionRecs(retangulos[i], tile))
                {
                    Rectangle colisao = GetCollisionRec(retangulos[i], tile);

                    if (tile.y < retangulos[i].y && corpos[i].Velocidade.y < 0)
                    {
                        corpos[i].Aceleracao.y = 0;
                        corpos[i].Velocidade.y = 0;
                        retangulos[i].y += colisao.height;
                        continue;
                    }

                    if (tile.y > retangulos[i].y && corpos[i].Velocidade.y > 0)
                    {
                        corpos[i].Aceleracao.y = 0;
                        corpos[i].Velocidade.y = 0;
                        retangulos[i].y -= colisao.height;
                        continue;
                    }




                    if (tile.x < retangulos[i].x)
                    {
                        corpos[i].Aceleracao.x = 0;
                        corpos[i].Velocidade.x = 0;
                        retangulos[i].x += colisao.width;
                        continue;
                    }

                    if (tile.x > retangulos[i].x)
                    {
                        corpos[i].Aceleracao.x = 0;
                        corpos[i].Velocidade.x = 0;
                        retangulos[i].x -= colisao.width;
                        continue;
                    }

                }

            }
            else if (*caractere == '\n')
            {
                tileY += 80;
                tileX = 0;
                continue;
            }
            tileX += 80;
        }


    }
}
