# Sistema de Varredura para C–

Este projeto contém um **sistema de varredura** simples para a linguagem C–.  
O sistema lê um arquivo de código-fonte (`.c`) e identifica **palavras reservadas, identificadores, números, símbolos e comentários**.

---
# Membros do Grupo

Rafaela Beatriz Gutierrez Oliveira

---

## Estrutura do projeto

- `sistema_varredura.c` → código do sistema de varredura em C que lê o arquivo de entrada e exibe os tokens.
- `exemplo.c` → exemplo de código-fonte que será varrido pelo sistema de varredura.  
  - Contém um programa simples que atribui um valor a uma variável `x`, verifica com `if/else` e retorna o resultado.

---

## Linguagem e compilação

- Código escrito em **C**, compatível com compiladores GCC/MinGW.  
- Funciona no **Google Colab**, sem necessidade de instalar compilador local.

---

## Como rodar no Google Colab

Para rodar no Colab, você não precisa enviar arquivos diretamente.  
Basta criar novas células e usar o comando `%%writefile` para criar os arquivos.

Por exemplo:

1. Abra um notebook novo no [Google Colab](https://colab.research.google.com).  

2. Criar o arquivo do código-fonte (`exemplo.c`)
    - Copie o código do arquivo exemplo.c e cole em uma célula no colab:
    - no inicio do código escreva `%%writefile exemplo.c"`
    - Execute a célula e o arqivo será criado

- Exemplo:

```c
%%writefile exemplo.c
int main(void) {
    int x;
    x = 10;
    if (x >= 5) {
        x = x + 1;
    } else {
        x = x - 1;
    }
    return x;
}
```

3. Faça o mesmo para o arquivo do sistema_varreduta.c em uma nova célula:
    - Use no inicio do código: `%%writefile sistema_varredura.c`
    
4. Compilar o sistema de varredura:

`!gcc sistema_varredura.c -o sistema_varredura`

5. Executar o sistema de varredura:

`!./sistema_varredura`
 
 ---

O ssistema vai ler o arquivo exemplo.c e exibir os tokens encontrados.

No exemplo, identifica palavras reservadas (int, if, else, return), identificadores (x), números (10, 5, 1), símbolos (=, +, -, ;, {, }).

---
