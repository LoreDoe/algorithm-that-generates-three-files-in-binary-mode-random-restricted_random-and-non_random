#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILE_SIZE 10485760 // 10 MB em bytes

// Função para gerar números aleatórios de 0 a 255
unsigned char generateRandomNumber() {
    return rand() % 256;
}

// Função para gerar números aleatórios restritos de 0 a 25
unsigned char generateRestrictedRandomNumber() {
    return rand() % 26;
}

int main() {
    FILE *file_random, *file_restricted, *file_non_random;
    int i;

    // Abrindo arquivos para escrita em modo binário
    file_random = fopen("random.bin", "wb");
    file_restricted = fopen("restricted.bin", "wb");
    file_non_random = fopen("non_random.bin", "wb");

    // Verificando se os arquivos foram abertos corretamente
    if (file_random == NULL || file_restricted == NULL || file_non_random == NULL) {
        printf("Erro ao abrir os arquivos.");
        return 1;
    }

    // Semente para geração de números aleatórios
    srand(time(NULL));

    // Modo completamente aleatório
    for (i = 0; i < FILE_SIZE; i++) {
        unsigned char random_number = generateRandomNumber();
        fwrite(&random_number, sizeof(unsigned char), 1, file_random);
    }

    // Modo aleatório restrito
    for (i = 0; i < FILE_SIZE; i++) {
        unsigned char restricted_number = generateRestrictedRandomNumber();
        fwrite(&restricted_number, sizeof(unsigned char), 1, file_restricted);
    }

    // Modo não aleatório
    while (ftell(file_non_random) < FILE_SIZE) {
        unsigned char byte = ftell(file_non_random) % 256; // Sequência de números de 0 a 255
        fwrite(&byte, sizeof(unsigned char), 1, file_non_random);
    }

    // Fechando os arquivos
    fclose(file_random);
    fclose(file_restricted);
    fclose(file_non_random);

    printf("Arquivos gerados com sucesso.\n");

    return 0;
}
