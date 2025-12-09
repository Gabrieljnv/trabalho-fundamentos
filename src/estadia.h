#ifndef ESTADIA_H
#define ESTADIA_H


#include "tipos.h"


int cadastrar_estadia(const Estadia *e, const char *path_estadia, const char *path_quarto, const char *path_cliente);
int dar_baixa_estadia(int codigo_estadia, float *valor_total_out, const char *path_estadia, const char *path_quarto);


#endif