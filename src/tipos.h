#ifndef TIPOS_H
#define TIPOS_H


#define MAX_NOME 100
#define MAX_END 150
#define MAX_TEL 20


typedef struct {
int codigo;
char nome[MAX_NOME];
char endereco[MAX_END];
char telefone[MAX_TEL];
} Cliente;


typedef struct {
int codigo;
char nome[MAX_NOME];
char telefone[MAX_TEL];
char cargo[30];
float salario;
} Funcionario;


typedef struct {
int numero;
int capacidade;
float diaria;
int status; // 0 desocupado, 1 ocupado
} Quarto;


typedef struct {
int codigo_estadia;
char data_entrada[11];
char data_saida[11];
int qtd_diarias;
int codigo_cliente;
int numero_quarto;
} Estadia;


#endif // TIPOS_H