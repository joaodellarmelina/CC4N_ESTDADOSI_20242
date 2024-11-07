#include <stdio.h>

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;

    printf("Quantos elementos terá o array? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Tamanho inválido.\n");
        return 1;
    }

    int arr[n];
    printf("Digite os %d elementos:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Array original:\n");
    printArray(arr, n);

    shellSort(arr, n);

    printf("Array ordenado:\n");
    printArray(arr, n);

    return 0;
}