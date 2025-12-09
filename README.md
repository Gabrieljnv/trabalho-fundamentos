# Hotel Descanso Garantido


Trabalho interdisciplinar das disciplinas **Fundamentos de Engenharia de Software** e **Algoritmos e Estruturas de Dados I**.
Este projeto implementa um sistema de gerenciamento para o hotel *Descanso Garantido*, incluindo cadastro de clientes, funcionários, quartos, estadias, baixa de estadias e geração de relatórios simples.


O desenvolvimento segue práticas de Engenharia de Software, utilizando Scrum, backlog evolutivo, sprints e testes automatizados com **munit**.


---


## 🎯 Objetivo Geral
Implementar um sistema em **C**, utilizando arquivos binários para persistência, aplicando conceitos de estruturas de dados, modularização, testes e boas práticas de engenharia.


---


## 📌 Funcionalidades Implementadas
- Cadastro de clientes
- Cadastro de funcionários
- Cadastro de quartos
- Registro de estadias
- Baixa de estadias (com cálculo automático do valor)
- Atualização automática do status dos quartos (ocupado/desocupado)
- Persistência dos dados em arquivos binários
- Testes automatizados com munit
- Estrutura modular (`cliente.c`, `quarto.c`, `estadia.c`, etc.)


---
## 📂 Estrutura do Projeto
hotel-descanso/ ├─ src/ │ ├─ cliente/ │ │ ├─ cliente.c │ │ └─ cliente.h │ ├─ funcionario/ │ ├─ quarto/ │ ├─ estadia/ │ ├─ utils/ │ ├─ tipos.h │ └─ main.c ├─ tests/ │ ├─ test_cliente.c ├─ data/ │ ├─ clientes.dat │ ├─ funcionarios.dat │ ├─ quartos.dat │ └─ estadias.dat ├─ doc/ │ ├─ backlog.md │ ├─ casos_de_teste.md │ └─ relatorio_testes.md ├─ Makefile └─ README.md

---


## 🛠️ Como Compilar
Certifique-se de que o **gcc** está instalado.


No terminal (PowerShell, CMD ou Git Bash):

---


## ▶️ Como Executar o Programa

---


## 🧪 Executando os Testes Automatizados

Os testes utilizam a biblioteca **munit**, que verifica o comportamento correto das funções.


---


## 📘 Como Usar o Sistema
Menu principal:

Cada opção solicita os campos necessários e grava nos arquivos binários.


---


## 🧱 Persistência de Dados
O sistema utiliza arquivos `.dat` no diretório `data/`:
- `clientes.dat`
- `quartos.dat`
- `estadias.dat`


Todos são manipulados com `fread` / `fwrite` e possuem registros fixos.


---


## 🧪 Relatórios de Testes
Os testes são documentados em:

Esse relatório traz:
- Entradas dos testes
- Saída esperada
- Saída real
- PASS / FAIL


---


## 📝 Backlog e Scrum
O backlog do projeto está em:

Cada sprint contém:
- tarefas planejadas
- responsável
- progresso
- funcionalidades entregues


---


## 📦 Como Popular Dados de Teste
Use o programa `seed_data.c`:

Isso cria dados simples para testes.


---


## 👨‍💻 Autores
Projeto desenvolvido por Gabriel Junio Nunes Viana e Lian Vasconcelos