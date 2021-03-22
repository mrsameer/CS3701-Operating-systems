/*
 Program for first fit algorithm in Memory management

*/

#include <stdio.h>
#include <limits.h>

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
        printf("Enter the block size of block %d: ", i + 1);
        scanf("%d", &blocks[i]);
    }

    // get process sizes
    for (int i = 0; i < process_no; i++)
    {
        printf("Enter the process size of process %d: ", i + 1);
        scanf("%d", &processes[i]);
    }

    // first fit allocation
    int block; 
    int currentblock_size; 
    for (int i = 0; i < process_no; i++)
    {
        block = -1;
        currentblock_size = INT_MAX;
        for (int j = 0; j < block_no; j++)
        {
            if (flag[j] == 0 && blocks[j] >= processes[i] && currentblock_size > blocks[j])
            {
                block = j; 
                currentblock_size = blocks[j];
            }
        }
        if (block >= 0)
        {
            allocation[block] = i;
            flag[block] = 1;
        }
    }

    // print allocation table
    printf("Block no\t\tBlock size\t\t Process no\t\t Process size\t\tFragmentation\n");
    for (int i = 0; i < block_no; i++)
    {
        printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d (%s)\n", i + 1, blocks[i], allocation[i] == -1 ? -1 : allocation[i] + 1, allocation[i] == -1 ? -1 : processes[allocation[i]], allocation[i] == -1 ? blocks[i] : (blocks[i] - processes[allocation[i]]), allocation[i] == -1 ? "external" : "internal");
    }

    return 0;
}
