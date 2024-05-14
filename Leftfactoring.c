#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 20

void leftFactor(char* production) {
    char alpha[SIZE], beta[SIZE];
    int index = 2, alpha_index = 0, beta_index = 0;
    while (production[index] != '|' && production[index] != '\0') {
        alpha[alpha_index++] = production[index++];
    }
    alpha[alpha_index] = '\0';
    if (production[index] == '|') {
        index++;
        while (production[index] != '\0') {
            beta[beta_index++] = production[index++];
        }
        beta[beta_index] = '\0';
        printf("After left factoring: \n");
        printf("%c->%c%s'\n", production[0], production[0], beta);
        printf("%c'->%s\n", production[0], alpha);
    } else {
        printf("No left factoring needed.\n");
    }
}

int main() {
    char production[SIZE];
    printf("Enter the production: ");
    scanf("%s", production);
    leftFactor(production);
    return 0;
}
