#include <stdio.h>
#include <assert.h>
#include "testes_entidade.h"
#include "../entidade/gerenciador_entidades.h"

int teste_entidades(void)
{

    Entidade e1;
    Entidade e2;

    criar_nova_entidade(&e1);
    criar_nova_entidade(&e2);

    assert(e1.Entidade_Info.id == 0);
    assert(e2.Entidade_Info.id == 1);


    Entidade e3;
    pegar_entidade(&e3, e1.Entidade_Info.id);

    assert(e1.Entidade_Info.id == e3.Entidade_Info.id); // o pegar entidade não está funcionando

    e3.Retangulo = (Rectangle){100, 100, 100, 100};

    atualizar_entidade(&e3);

    pegar_entidade(&e1, e1.Entidade_Info.id);

    assert(e1.Retangulo.x == 100 && e1.Retangulo.y == 100 && e1.Retangulo.width == 100 && e1.Retangulo.height == 100); // não atualizou a entidade

    return 0;
}
