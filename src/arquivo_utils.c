#include "arquivo_utils.h"
#include <stdio.h>


FILE* abrir_arquivo(const char *path, const char *modo) {
FILE *f = fopen(path, modo);
return f;
}


int fechar_arquivo(FILE *f) {
if (!f) return -1;
fclose(f);
return 0;
}