#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILE_SIZE 10485760 // Tamanho do arquivo (10 MB)

// Função para gerar números aleatórios de 0 a 255..
int generateRandomNumber() {
    return rand() % 256;
}

// Função para gerar números não aleatórios.
int generateNonRandomNumber() {
    static int num = 0;
    num = (num + 1) % 256;
    return num;
}

int main() {
    FILE *randomFile, *restrictedRandomFile, *nonRandomFile;
    int i;

    // Abrir arquivos para escrita em modo binário.
    randomFile = fopen("random.bin", "wb");
    restrictedRandomFile = fopen("restricted_random.bin", "wb");
    nonRandomFile = fopen("non_random.bin", "wb");

    if (randomFile == NULL || restrictedRandomFile == NULL || nonRandomFile == NULL) {
        printf("Erro ao abrir arquivos.");
        return 1;
    }

    // Semente para o gerador de números aleatórios.
    srand(time(NULL));

    // Gerar arquivo completamente aleatório.
    for (i = 0; i < FILE_SIZE; i++) {
        unsigned char randomNumber = generateRandomNumber();
        fwrite(&randomNumber, sizeof(unsigned char), 1, randomFile);
    }

    // Gerar arquivo aleatório restrito.
    for (i = 0; i < FILE_SIZE; i++) {
        unsigned char randomNumber = generateRandomNumber();
        if (randomNumber < 26) {
            fwrite(&randomNumber, sizeof(unsigned char), 1, restrictedRandomFile);
        }
    }

    // Gerar arquivo não aleatório (sequências repetidas).
    for (i = 0; i < FILE_SIZE; i++) {
        unsigned char nonRandomNumber = generateNonRandomNumber();
        fwrite(&nonRandomNumber, sizeof(unsigned char), 1, nonRandomFile);
    }

    // Fechar arquivos.
    fclose(randomFile);
    fclose(restrictedRandomFile);
    fclose(nonRandomFile);

    printf("Arquivos gerados com sucesso.\n");

    return 0;
}
