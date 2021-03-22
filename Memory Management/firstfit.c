/*
 Program for first fit algorithm in Memory management

*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int block_no, process_no; 
    printf("Enter the number of processes: "); 
    scanf("%d", &process_no); 
    printf("Enter the number of blocks: "); 
    scanf("%d", &block_no); 

    int processes[process_no], blocks[block_no], flag[block_no], allocation[block_no]; 

    // set flag array to 0 as initially all the blocks are free and set allocation array to -1
    for (int i = 0; i < block_no; i++)
    {
        flag[i] = 0; 
        allocation[i] = -1; 
    }
    
    // get block sizes 
    for (int i = 0; i < block_no; i++)
    {
        printf("Enter the block size of block %d: ", i+1); 
        scanf("%d", &blocks[i]); 
    }
    
    // get process sizes 
    for (int i = 0; i < process_no; i++)
    {
        printf("Enter the process size of process %d: ", i+1); 
        scanf("%d", &processes[i]);
    }
    
    // first fit allocation 
    for (int i = 0; i < process_no; i++)
    {
        for (int j = 0; j < block_no; j++)
        {
            if (flag[j] == 0 && blocks[j] >= processes[i])
            {
                allocation[j] = i; 
                flag[j] = 1; 
                break;
            }
            
        }
        
    }
    
    // print allocation table 
    printf("Block no\t\tBlock size\t\t Process no\t\tFragmentation\n"); 
    for (int i = 0; i < block_no; i++)
    {
        printf("%d\t\t\t%d\t\t\t%d\t\t\t%d (%s)\n", i+1, blocks[i], allocation[i] == -1 ? -1: allocation[i] + 1, allocation[i] == -1? blocks[i]:blocks[i]-processes[i], allocation[i] == -1?"external":"internal");
    }
    
    return 0;
}
