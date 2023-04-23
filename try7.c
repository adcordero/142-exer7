#include <stdio.h>

int main(){
    int S[5] = {3, 7, 2, 9, 5};
    int k = 10, temp = 0;
    int size = sizeof(S)/sizeof(S[0]);

    // for(int i=0; i<size; i++){
    //     printf("%d ", S[i]); 
    // }
    // printf("\n");

    // sorting 
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(S[i] > S[j]){
                temp = S[i];
                S[i] = S[j];
                S[j] = temp;
            }
        }
    }

    // for(int i=0; i<size; i++){
    //     printf("%d ", S[i]); 
    // }
    // printf("\n");
}