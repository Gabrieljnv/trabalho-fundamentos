#ifndef CLIENTE_H
#define CLIENTE_H


#include "tipos.h"


int cadastrar_cliente(const Cliente *c, const char *path);
int pesquisar_cliente_por_codigo(int codigo, Cliente *out, const char *path);


#endif