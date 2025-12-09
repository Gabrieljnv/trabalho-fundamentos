#ifndef ARQUIVO_UTILS_H
#define ARQUIVO_UTILS_H


#include <stdio.h>


FILE* abrir_arquivo(const char *path, const char *modo);
int fechar_arquivo(FILE *f);


#endif