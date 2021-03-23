/*
Process scheduling algorithm: Shortest Job First (SJF)
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
} process;

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    process p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].pno = i + 1;
        printf("Enter the process %d arrival time: ", i + 1);
        scanf("%d", &p[i].pat);
        printf("Enter the process %d burst time: ", i + 1);
        scanf("%d", &p[i].pbt);
    }

    // sort the processes based on their burst time time
    process temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (p[j].pat > p[j + 1].pat)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
            else if (p[j].pat == p[j + 1].pat)
            {
                if (p[j].pbt > p[j + 1].pbt)
                {
                    temp = p[j]; 
                    p[j] = p[j+1]; 
                    p[j + 1] = temp; 
                }
                
            }
            
        }
    }

    printf("Sequence of schedule: ");
    // find the completion time, turnaround time and waiting time of the processes
    int total_wt = 0; 
    int total_tat = 0; 
    int prev; 
    for (int i = 0; i < n; i++)
    {
       if (i > 0)
       {
           for (int j = i + 1; j < n - 1; j++)
           {
               if (p[j].pat <= p[i].pct && p[j].pbt > p[j+1].pbt)
               {
                   temp = p[j];
                   p[j] = p[j + 1];
                   p[j + 1] = temp;
               }
               else
                   break;
           }
       }
       
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

       total_tat += p[i].ptat;
       total_wt += p[i].pwt;
       printf("P%d ", p[i].pno);
    }


    printf("\nPID\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pno, p[i].pat, p[i].pbt, p[i].pct, p[i].ptat, p[i].pwt);
    }

    printf("Average weighting time: %.2f\n", (float)total_wt/n);
    printf("Average turn around time: %.2f\n", (float)total_tat/n);
    return 0;
}
