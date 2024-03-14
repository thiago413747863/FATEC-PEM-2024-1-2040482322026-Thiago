#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int palindromo(char *palavra) {
    int stt = 0;
    int end = strlen(palavra) - 1;
    while (end > stt) {
        while (!isalpha(palavra[stt]) && stt < end) {
            stt++;
        }
        while (!isalpha(palavra[end]) && end > stt) { 
            end--;
        }
        if (tolower(palavra[stt]) != tolower(palavra[end])) {
            return 0;
        }
        stt++;
        end--;
    }
    return 1; 
}
int main() {
    char frase[1000];
    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);
    char *novaLinha = strchr(frase, '\n');
    if (novaLinha != NULL) {
        *novaLinha = '\0';
    }
    if (palindromo(frase)) {
        printf("A frase é um palíndromo.\n");
    } else {
        printf("A frase não é um palíndromo.\n");
    }
    return 0;
}