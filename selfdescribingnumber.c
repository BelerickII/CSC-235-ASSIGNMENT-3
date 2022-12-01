#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *self = fopen("self.in", "r");

    if(self == NULL){
      printf("Error! opening file");   
      exit(1);
    }

    int test_cases;    
    fscanf(self, "%d", &test_cases);
    
    for (int i = 0; i < test_cases; i++){
        int len;
        char number[15];
        fscanf(self, "%s", number);       
        len = strlen(number);
        char number_count[len];
        
        //printf("%s\n\n", number);
        for(int j = 0; j < len; j++){
            int counter = 0;
            for(int k = 0; k < len; k++){
                //printf("%c\n", number[k]);  
                char num = j +'0';
                if (num == number[k]){
                    counter++;
                }             
            }
            //printf("%d\n", counter);
            number_count[j] = counter +'0';
        }
        //converting the strings to integers
        if (atoi(number) == atoi(number_count))
        {
            printf("self_describing\n\n");
        }else{
            printf("Not self_describing\n\n");
        }    
    }
    fclose(self);
    return 0;
}