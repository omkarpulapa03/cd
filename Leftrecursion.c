#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

int main(){
    char pro[SIZE], alpha[SIZE], beta[SIZE];
    char nt;
    int i = 0, j = 0, index = 3;

    printf("Enter the production (e.g., A->Aalpha|beta): ");
    scanf("%s", pro);
    nt = pro[0];

    if(nt == pro[index]){
        // Extracting alpha
        for(i = index + 1, j = 0; pro[i] != '|' && pro[i] != '\0'; i++, j++){
            alpha[j] = pro[i];
        }
        alpha[j] = '\0';

        if(pro[i] == '|'){
            i++; // Skip the '|'
            // Extracting beta
            for(j = 0; pro[i] != '\0'; i++, j++){
                beta[j] = pro[i];
            }
            beta[j] = '\0';

            printf("Grammar without left recursion:\n");
            printf("%c -> %s%c\'\n", nt, beta, nt);
            printf("%c\' -> %s%c\'|ε\n", nt, alpha, nt);
        } else {
            printf("Grammar cannot be reduced.\n");
        }
    } else {
        printf("Grammar has no left recursion.\n");
    }

    return 0;
}
