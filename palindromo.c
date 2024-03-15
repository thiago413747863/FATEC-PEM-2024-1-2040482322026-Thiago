#include <stdio.h>
#include <string.h>
#include <ctype.h>

int palindromo(char *palavra) {
    int com = strlen(palavra);
    for (int i = 0; i < com / 2; i++) {
        if (tolower(palavra[i]) != tolower(palavra[com - i - 1])) {
            return 0;
        }
    }
    return 1;
}
int main() {
    char frase[100];
    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);
    char *lim = " ,.!?\n";
    printf("Palíndromos encontrados: \n");
    for (char *token = strtok(frase, lim); token != NULL; token = strtok(NULL, lim)) {
        if (strlen(token) > 2 && !strstr("o a os as de da do das dos para por com sem", token)) {
            printf("%s\n", (palindromo(token)) ? token : "");
        }
    }
    return 0;
}