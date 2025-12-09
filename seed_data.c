#include <stdio.h>
#include "src/tipos.h"


int main() {
// garante diretório data existente
system("mkdir -p data");
FILE *f;


f = fopen("data/clientes.dat", "wb");
Cliente c = { .codigo = 1 };
snprintf(c.nome, MAX_NOME, "Joao Silva");
snprintf(c.endereco, MAX_END, "Rua A, 100");
snprintf(c.telefone, MAX_TEL, "3199999");
fwrite(&c, sizeof(Cliente), 1, f);
fclose(f);


f = fopen("data/quartos.dat", "wb");
Quarto q = { .numero = 101, .capacidade = 2, .diaria = 120.0f, .status = 0 };
fwrite(&q, sizeof(Quarto), 1, f);
fclose(f);


return 0;
}