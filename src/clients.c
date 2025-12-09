#include "clients.h"
#include <stdio.h>
#include <string.h>


int cadastrar_cliente(const Cliente *c, const char *path) {
// verifica duplicado por codigo
FILE *f = fopen(path, "ab+");
if (!f) return -1;
Cliente tmp;
rewind(f);
while (fread(&tmp, sizeof(Cliente), 1, f) == 1) {
if (tmp.codigo == c->codigo) { fclose(f); return -1; }
}
fwrite(c, sizeof(Cliente), 1, f);
fclose(f);
return 0;
}


int pesquisar_cliente_por_codigo(int codigo, Cliente *out, const char *path) {
FILE *f = fopen(path, "rb");
if (!f) return -1;
Cliente tmp;
while (fread(&tmp, sizeof(Cliente), 1, f) == 1) {
if (tmp.codigo == codigo) { *out = tmp; fclose(f); return 0; }
}
fclose(f);
return -1;
}