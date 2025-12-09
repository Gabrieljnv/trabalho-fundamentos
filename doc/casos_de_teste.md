# Casos de Teste - resumo


## CT01 - cadastrar_cliente - sucesso
Entrada: Cliente{codigo=1, nome=Joao}
Saida esperada: retorno 0; registro gravado em data/clientes.dat


## CT02 - cadastrar_cliente - duplicado
Entrada: Cliente{codigo=1, nome=Outro}
Saida esperada: retorno -1


## ET01 - cadastrar_estadia - sucesso
Entrada: Estadia{codigo_estadia=1, codigo_cliente=1, numero_quarto=101, qtd_diarias=2}
Saida esperada: retorno 0; quarto 101 marcado como ocupado