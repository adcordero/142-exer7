#include <stdio.h>
#include <stdlib.h>

int main(){

    int size, k;
    printf("Enter size of the array: ");
    scanf("%d", &size);
    
    int S[size];
    printf("Enter %d integers: ", size);
    for(int i = 0; i < size; i++){
        scanf("%d", &S[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    int temp = 0;
    int two_dimensional[size][k+1];

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

    // column 0 is initialized to 1 aka empty set
    for(int i = 0; i < size; i++){
        for(int j= 0; j < k+1; j++){
            if(j==0){
                two_dimensional[i][j] = 1;
            }else{
                two_dimensional[i][j] = 0;
            }
        }
    }

    for(int curr = 0; curr < size; curr++){
        if(curr==0){
            for(int j = 1; j < k+1; j++){
                if(S[curr] == j){
                    two_dimensional[curr][j] = 1;
                }else{
                    two_dimensional[curr][j] = 0;
                }
            }
        }else{
            for(int j = 1; j < k+1; j++){
                if(S[curr] != j){
                    two_dimensional[curr][j] = 0;
                }
                if((j-S[curr]) < 0){ 
                    two_dimensional[curr][j] = two_dimensional[curr-1][j];
                }else{
                    int prevJ = two_dimensional[curr-1][j];
                    int moved_left = two_dimensional[curr-1][j-S[curr]];
                    if(prevJ > moved_left){
                        two_dimensional[curr][j] = prevJ;
                    }else{
                        two_dimensional[curr][j] = moved_left;
                    }
                }
            }
        }
    }
    // print for two_dimensional
    printf("\n");
    printf("  :");
    for(int i = 0; i <= k; i++){
        printf("\t%d",i);
    }
    printf("\n");
    for(int i = 0; i < size; i++){
        printf("%d : ", S[i]);
        for(int j= 0; j < k+1; j++){
            printf("\t%d", two_dimensional[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    if(two_dimensional[size-1][k] == 1){
        int curr_index, sub_index = 0;
        for(int i = size-1; i >= 0; i--){
            if (two_dimensional[i][k] == 0){
                curr_index = i + 1;
                break;
            }
        }
        int sub_size = size - curr_index;
        int subset[sub_size];
        subset[sub_index] = S[curr_index];
        sub_index++;

        int new_k = k - S[curr_index];
        while(new_k > 0){
            for(int i = curr_index-1; i >= 0; i--){
                if (two_dimensional[i][new_k] == 0){
                    curr_index = i + 1;
                    subset[sub_index] = S[curr_index];
                    sub_index++;
                    break;
                }
                if(i == 0){
                    if (new_k - S[i] >= 0){
                        subset[sub_index] = S[i];
                        sub_index++;
                    }
                }
            }
            new_k = new_k - S[curr_index];
        }
        printf("The solution set for k = %d is {", k);
        for(int i=sub_index-1; i > 0; i--){
            printf("%d, ", subset[i]); 
        }
        printf("%d}.\n", subset[0]);
    }else{
        printf("There is no solution.\n");
    }
}