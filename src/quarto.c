#include "quarto.h"
#include <stdio.h>
#include <string.h>


int cadastrar_quarto(const Quarto *q, const char *path) {
FILE *f = fopen(path, "ab+");
if (!f) return -1;
Quarto tmp;
rewind(f);
while (fread(&tmp, sizeof(Quarto), 1, f) == 1) {
if (tmp.numero == q->numero) { fclose(f); return -1; }
}
fwrite(q, sizeof(Quarto), 1, f);
fclose(f);
return 0;
}


int atualizar_status_quarto(int numero_quarto, int novo_status, const char *path) {
FILE *f = fopen(path, "r+b");
if (!f) return -1;
Quarto tmp;
while (fread(&tmp, sizeof(Quarto), 1, f) == 1) {
if (tmp.numero == numero_quarto) {
tmp.status = novo_status;
fseek(f, -((long)sizeof(Quarto)), SEEK_CUR);
fwrite(&tmp, sizeof(Quarto), 1, f);
fclose(f);
return 0;
}
}
fclose(f);
return -1;
}


int encontrar_quarto_disponivel(int capacidade_desejada, int *numero_out, const char *path) {
FILE *f = fopen(path, "rb");
if (!f) return -1;
Quarto tmp;
while (fread(&tmp, sizeof(Quarto), 1, f) == 1) {
if (tmp.capacidade >= capacidade_desejada && tmp.status == 0) {
*numero_out = tmp.numero;
fclose(f);
return 0;
}
}
fclose(f);
return -1;
}