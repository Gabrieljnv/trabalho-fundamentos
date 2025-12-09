#include "estadia.h"
#include "quarto.h"
#include "cliente.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>


int cadastrar_estadia(const Estadia *e, const char *path_estadia, const char *path_quarto, const char *path_cliente) {
// valida cliente
Cliente c;
if (pesquisar_cliente_por_codigo(e->codigo_cliente, &c, path_cliente) != 0) return -2;


// encontra quarto e verifica disponibilidade simples
Quarto qtmp;
FILE *fq = fopen(path_quarto, "r+b");
if (!fq) return -3;
int found = 0;
while (fread(&qtmp, sizeof(Quarto), 1, fq) == 1) {
if (qtmp.numero == e->numero_quarto) { found = 1; break; }
}
if (!found) { fclose(fq); return -4; }
if (qtmp.status == 1) { fclose(fq); return -5; }


// grava estadia
FILE *fe = fopen(path_estadia, "ab+");
if (!fe) { fclose(fq); return -6; }
fwrite(e, sizeof(Estadia), 1, fe);
fclose(fe);


// marca quarto como ocupado
qtmp.status = 1;
fseek(fq, -((long)sizeof(Quarto)), SEEK_CUR);
fwrite(&qtmp, sizeof(Quarto), 1, fq);
fclose(fq);
return 0;
}


int dar_baixa_estadia(int codigo_estadia, float *valor_total_out, const char *path_estadia, const char *path_quarto) {
FILE *fe = fopen(path_estadia, "r+b");
if (!fe) return -1;
Estadia et;
int found = 0;
while (fread(&et, sizeof(Estadia), 1, fe) == 1) {
if (et.codigo_estadia == codigo_estadia) { found = 1; break; }
}
if (!found) { fclose(fe); return -2; }


// calcula valor: procurar diaria do quarto
FILE *fq = fopen(path_quarto, "r+b");
if (!fq) { fclose(fe); return -3; }
Quarto qtmp;
int foundq = 0;
while (fread(&qtmp, sizeof(Quarto), 1, fq) == 1) {
if (qtmp.numero == et.numero_quarto) { foundq = 1; break; }
}
if (!foundq) { fclose(fq); fclose(fe); return -4; }


int dias = et.qtd_diarias;
*valor_total_out = dias * qtmp.diaria;


// libera quarto
qtmp.status = 0;
fseek(fq, -((long)sizeof(Quarto)), SEEK_CUR);
fwrite(&qtmp, sizeof(Quarto), 1, fq);
fclose(fq);


// opcional: marcar estadia como finalizada (não implementado: remoção)
fclose(fe);
return 0;
}