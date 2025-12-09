#include "munit/munit.h"
#include "clients.h"
#include <stdio.h>
#include <stdlib.h>


static void limpar_db(void) {
remove("data/clientes.dat");
}


static MunitResult test_cadastrar_cliente_success(const MunitParameter params[], void* data) {
limpar_db();
Cliente c = { .codigo = 1 };
snprintf(c.nome, MAX_NOME, "Joao");
snprintf(c.endereco, MAX_END, "Rua A");
snprintf(c.telefone, MAX_TEL, "99999");
int r = cadastrar_cliente(&c, "data/clientes.dat");
munit_assert_int(r, ==, 0);
Cliente out;
int rp = pesquisar_cliente_por_codigo(1, &out, "data/clientes.dat");
munit_assert_int(rp, ==, 0);
munit_assert_string(out.nome, "Joao");
return MUNIT_OK;
}


static MunitTest tests[] = {
{ "/cadastrar_cliente_success", test_cadastrar_cliente_success, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};


static const MunitSuite suite = { "/cliente", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };


int main(int argc, char* argv[]) {
return munit_suite_main(&suite, NULL, argc, argv);
}