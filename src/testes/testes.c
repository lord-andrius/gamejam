#include <stdio.h>
#include "testes.h"

int main(void)
{
    for (Teste **teste = Testes; *teste != NULL; teste++)
    {
        printf("INICIANDO TESTE: %s\n", (*teste)->nome);
        int resultado = (*teste)->funcao_teste();
        printf(
            "RESULTADO DO TESTE(\"%s\"): %s\n",
            (*teste)->nome,
            resultado == 0 ? "PASSOU" : "FALHOU"
        );
    }
}
