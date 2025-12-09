#include <stdio.h>
#include "tipos.h"
#include "clients.h"
#include "quarto.h"
#include "estadia.h"


#define PATH_CLIENTES "data/clientes.dat"
#define PATH_QUARTOS "data/quartos.dat"
#define PATH_ESTADIAS "data/estadias.dat"


int main() {
int opc = 0;
while (1) {
printf("--- Hotel Descanso Garantido ---\n");
printf("1) Cadastrar cliente\n");
printf("2) Cadastrar quarto\n");
printf("3) Cadastrar estadia\n");
printf("4) Dar baixa em estadia\n");
printf("0) Sair\n");
printf("Opc: ");
if (scanf("%d", &opc) != 1) break;
if (opc == 0) break;
if (opc == 1) {
Cliente c; printf("Codigo: "); scanf("%d", &c.codigo);
printf("Nome: "); scanf(" "); fgets(c.nome, MAX_NOME, stdin);
printf("Endereco: "); fgets(c.endereco, MAX_END, stdin);
printf("Telefone: "); fgets(c.telefone, MAX_TEL, stdin);
if (cadastrar_cliente(&c, PATH_CLIENTES) == 0) printf("Cliente cadastrado.\n");
else printf("Erro ao cadastrar.\n");
} else if (opc == 2) {
Quarto q; printf("Numero: "); scanf("%d", &q.numero);
printf("Capacidade: "); scanf("%d", &q.capacidade);
printf("Diaria: "); scanf("%f", &q.diaria);
q.status = 0;
if (cadastrar_quarto(&q, PATH_QUARTOS) == 0) printf("Quarto cadastrado.\n");
else printf("Erro ao cadastrar quarto.\n");
} else if (opc == 3) {
Estadia e; printf("Codigo estadia: "); scanf("%d", &e.codigo_estadia);
printf("Codigo cliente: "); scanf("%d", &e.codigo_cliente);
printf("Numero quarto: "); scanf("%d", &e.numero_quarto);
printf("Qtd diarias: "); scanf("%d", &e.qtd_diarias);
// datas simplificadas
strcpy(e.data_entrada, "2025-01-01");
strcpy(e.data_saida, "2025-01-01");
int r = cadastrar_estadia(&e, PATH_ESTADIAS, PATH_QUARTOS, PATH_CLIENTES);
if (r == 0) printf("Estadia cadastrada.\n"); else printf("Erro: %d\n", r);
} else if (opc == 4) {
int codigo; printf("Codigo estadia: "); scanf("%d", &codigo);
float total;
int r = dar_baixa_estadia(codigo, &total, PATH_ESTADIAS, PATH_QUARTOS);
if (r == 0) printf("Baixa realizada. Total: %.2f\n", total);
else printf("Erro na baixa: %d\n", r);
}
}
return 0;
}