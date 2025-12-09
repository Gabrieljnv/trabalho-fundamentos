#ifndef QUARTO_H
#define QUARTO_H


#include "tipos.h"


int cadastrar_quarto(const Quarto *q, const char *path);
int atualizar_status_quarto(int numero_quarto, int novo_status, const char *path);
int encontrar_quarto_disponivel(int capacidade_desejada, int *numero_out, const char *path);


#endif