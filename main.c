#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int *arr, int baixo, int alto) {
    int pivo = arr[alto]; 
    int i = (baixo - 1), j; 

    for (j = baixo; j <= alto - 1; j++) {
       
        if (arr[j] <= pivo) {
            i++; 
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void quickSort(int *arr, int baixo, int alto) {
    if (baixo < alto) {
        
        int pi = particionar(arr, baixo, alto);

        quickSort(arr, baixo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

void imprimirArray(int *arr, int tamanho) {
	int i;
    for (i = 0; i < tamanho; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "portuguese");
    int tamanho, i;

    printf("Digite o número de elementos do array: ");
    scanf("%d", &tamanho);

    int *arr = (int *)malloc(tamanho * sizeof(int));
    if (arr == NULL) {
        printf("Erro de alocação de memória!\n");
        return 1;
    }

    printf("Digite os elementos do array:\n");
    for (i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Array original:\n");
    imprimirArray(arr, tamanho);

    quickSort(arr, 0, tamanho - 1);

    printf("Array ordenado:\n");
    imprimirArray(arr, tamanho);

    free(arr);

    return 0;
}
