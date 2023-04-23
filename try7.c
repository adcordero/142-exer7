#include <stdio.h>
#include <stdlib.h>

int main(){
    int S[5] = {3, 7, 2, 9, 5};
    int k = 10, temp = 0;
    int size = sizeof(S)/sizeof(S[0]);
    int two_dimensional[size][k+1];

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

    // column 0 is initialized to 1 aka empty set
    for(int i = 0; i < size; i++){
        for(int j= 0; j < k+1; j++){
            if(j==0){
                two_dimensional[i][j] = 1;
            }else{
                two_dimensional[i][j] = S[i];
            }
        }
    }

    for(int curr = 0; curr < size; curr++){
        if(curr==0){
            for(int j = 1; j < k+1; j++){
                if(S[curr] > j || S[curr] < j){
                    two_dimensional[curr][j] = 0;
                }else{
                    two_dimensional[curr][j] = 1;
                }
            }
        }else{
            int total = 0;

            for(int l = curr; l >=0; l--){
                total = total + S[l];
            }

            for(int j = 1; j < k+1; j++){
                if(S[curr] > j || S[curr] < j){
                    two_dimensional[curr][j] = 0;
                }

                if((j-S[curr]) < 0){
                    two_dimensional[curr][j] = 0;
                }else{
                    int prevJ = two_dimensional[curr-1][j];
                    int moved_left = two_dimensional[curr-1][j-S[curr]];

                    if(prevJ > moved_left){
                        two_dimensional[curr][j] = prevJ;
                    }else{
                        two_dimensional[curr][j] = moved_left;
                    }
                }

                for(int l = curr; l >=0; l--){
                    if(j == S[l]){
                        two_dimensional[curr][j] = 1;
                    }
                }

                if(j == total){
                    two_dimensional[curr][j] = 1;
                }
            }
        }
    }

    for(int i = 0; i < size; i++){
        for(int j= 0; j < k+1; j++){
            printf("%d ", two_dimensional[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}