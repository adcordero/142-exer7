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

    // printf("%d\n", size);
    // for(int i = 0; i < size; i++){
    //     printf("%d ", S[i]);
    // }
    // printf("\n");

    // int S[5] = {3, 7, 2, 9, 5};
    // int k = 10;
    int temp = 0;
    // int size = sizeof(S)/sizeof(S[0]);
    int two_dimensional[size][k+1];

    // for(int i=0; i < size; i++){
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

    // print for two_dimensional
    printf("\n");
    for(int i = 0; i < size; i++){
        for(int j= 0; j < k+1; j++){
            printf("%d ", two_dimensional[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    if(two_dimensional[size-1][k] == 1){
        int curr_index, sub_index = 0;

        // printf("There is a solution.\n");

        // traceback
        for(int i = size-1; i >=0; i--){
            if (two_dimensional[i][k] == 0){
                curr_index = i + 1;
                // subset[sub_index] = S[curr_index];
                // sub_index++;
                break;
            }
        }
        int sub_size = size - curr_index;
        int subset[sub_size];
        subset[sub_index] = S[curr_index];
        sub_index++;
        // printf("%d - %d = %d\n", size, curr_index, size-curr_index);
        
        int new_k = k - S[curr_index];
        while(new_k > 0){
            printf("new_k = %d\n", new_k);
            // printf("%d\n", curr_index);

            for(int i = curr_index-1; i >=0; i--){
                // printf("i = %d\n", curr_index);

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
                        // break;
                    }
                }
            }
            // printf("curr_index = %d\n", curr_index);
            new_k = new_k - S[curr_index];

            // subset[sub_index] = S[curr_index];
            // curr_index--;
            // sub_index++;
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