#include <stdio.h>
#include <ctype.h>  // para isalpha, isdigit, isspace
#include <string.h> // para strcmp

// Função auxiliar para verificar se um identificador é palavra reservada
int ehPalavraReservada(char *palavra) {
    char *reservadas[] = {"else", "if", "int", "return", "void", "while"};
    int i;
    for (i = 0; i < 6; i++) {
        if (strcmp(palavra, reservadas[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    FILE *arquivo;
    char nomeArquivo[100];
    char c;

    arquivo = fopen("exemplo.c", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while ((c = fgetc(arquivo)) != EOF) {
        // Ignora espaços, tabulações e quebras de linha
        if (isspace(c))
            continue;

        // Verifica se é letra -> possível identificador ou palavra reservada
        if (isalpha(c)) {
            char id[50];
            int i = 0;
            id[i++] = c;

            // continua lendo letras e dígitos
            while ((c = fgetc(arquivo)) != EOF && (isalpha(c) || isdigit(c))) {
                id[i++] = c;
            }
            id[i] = '\0';
            ungetc(c, arquivo); // devolve o último caractere lido

            if (ehPalavraReservada(id))
                printf("PALAVRA RESERVADA: %s\n", id);
            else
                printf("IDENTIFICADOR: %s\n", id);
        }

        // Verifica se é dígito -> número
        else if (isdigit(c)) {
            char num[50];
            int i = 0;
            num[i++] = c;

            while ((c = fgetc(arquivo)) != EOF && isdigit(c)) {
                num[i++] = c;
            }
            num[i] = '\0';
            ungetc(c, arquivo);

            printf("NÚMERO: %s\n", num);
        }

        // Verifica se é início de comentário
        else if (c == '/') {
            char proximo = fgetc(arquivo);
            if (proximo == '*') {
                // Comentário iniciado
                char anterior = 0;
                while ((c = fgetc(arquivo)) != EOF) {
                    if (anterior == '*' && c == '/')
                        break;
                    anterior = c;
                }
                printf("COMENTÁRIO: /* ... */\n");
            } else {
                ungetc(proximo, arquivo);
                printf("SÍMBOLO: /\n");
            }
        }

        // Caso geral para símbolos especiais
        else {
            switch (c) {
                case '+': printf("SÍMBOLO: +\n"); break;
                case '-': printf("SÍMBOLO: -\n"); break;
                case '*': printf("SÍMBOLO: *\n"); break;
                case '<': {
                    char prox = fgetc(arquivo);
                    if (prox == '=')
                        printf("SÍMBOLO: <=\n");
                    else {
                        printf("SÍMBOLO: <\n");
                        ungetc(prox, arquivo);
                    }
                    break;
                }
                case '>': {
                    char prox = fgetc(arquivo);
                    if (prox == '=')
                        printf("SÍMBOLO: >=\n");
                    else {
                        printf("SÍMBOLO: >\n");
                        ungetc(prox, arquivo);
                    }
                    break;
                }
                case '=': {
                    char prox = fgetc(arquivo);
                    if (prox == '=')
                        printf("SÍMBOLO: ==\n");
                    else {
                        printf("SÍMBOLO: =\n");
                        ungetc(prox, arquivo);
                    }
                    break;
                }
                case '!': {
                    char prox = fgetc(arquivo);
                    if (prox == '=')
                        printf("SÍMBOLO: !=\n");
                    else {
                        printf("ERRO: símbolo '!' isolado\n");
                        ungetc(prox, arquivo);
                    }
                    break;
                }
                case ';': printf("SÍMBOLO: ;\n"); break;
                case ',': printf("SÍMBOLO: ,\n"); break;
                case '(': printf("SÍMBOLO: (\n"); break;
                case ')': printf("SÍMBOLO: )\n"); break;
                case '[': printf("SÍMBOLO: [\n"); break;
                case ']': printf("SÍMBOLO: ]\n"); break;
                case '{': printf("SÍMBOLO: {\n"); break;
                case '}': printf("SÍMBOLO: }\n"); break;
                default:
                    printf("SÍMBOLO DESCONHECIDO: %c\n", c);
            }
        }
    }

    fclose(arquivo);
    return 0;
}
