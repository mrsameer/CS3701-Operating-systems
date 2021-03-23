/*
Process scheduling algorithm: First Come First Out (FCFS)
*/

#include <stdio.h>

// process stucture
typedef struct 
{
    int pno; 
    int pat; 
    int pbt; 
    int pct; 
    int ptat; 
    int pwt; 
}process;


int main(int argc, char const *argv[])
{
    int n; 
    printf("Enter the number of processes: "); 
    scanf("%d", &n); 

    process p[n]; 
    for (int i = 0; i < n; i++)
    {
        p[i].pno = i+1; 
        printf("Enter the process %d arrival time: ", i+1); scanf("%d", &p[i].pat); 
        printf("Enter the process %d burst time: ", i+1); scanf("%d", &p[i].pbt); 
    }

    // sort the processes based on their arrival time 
    process temp; 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (p[j].pat > p[j+1].pat)
            {
                temp = p[j]; 
                p[j] = p[j+1]; 
                p[j+1] = temp;
            }
            
        }
        
    }
    
    // find the completion time, turnaround time and waiting time of the processes
    int prev = p[0].pat;
    for (int i = 0; i < n; i++)
    {
        if (p[i].pat - prev > 0)
        {
            p[i].pct = p[i].pat - prev; 
        }
        else
        p[i].pct = 0;
        
        p[i].pct += prev + p[i].pbt; 
        p[i].ptat = p[i].pct - p[i].pat;
        p[i].pwt = p[i].ptat - p[i].pbt; 
        prev = p[i].pct; 
    }
    

    printf("PID\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\n"); 
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pno, p[i].pat, p[i].pbt, p[i].pct, p[i].ptat, p[i].pwt);   
    }
    
    
    return 0;
}
