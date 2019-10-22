#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct process
{
    int burst;
    int id;
    int priority;
    int rem;
    int pos;
};

void main()
{
    int n, a = 0,j, i = 0;
    int timeelapsed = 0, wait = 0;
    float avgw = 0, avgt = 0;
    int x, z;
    int quantum;
    int timeused;

    srand(time(0));
    n = rand() % 10 + 1;
    struct process p[n];

    z = n;

    int waitarray[n];
    int turnarray[n];

    while (a < n)
    {
        p[i].id = i;

        p[i].burst = rand() % 10 + 1;
        p[i].rem = p[i].burst;
        a++;
        i++;
    }

    quantum = rand() % 3 + 1;
    printf("\nTime Quantum %d \n", quantum);
    printf("PROCESS_ID          BURST(ms)");
    for (j = 0; j < i; j++)
    {
        printf("\n%d           %d", p[j].id,p[j].burst);
    }
    


    

    printf("\nSchedule \n");
    for (x = 0; x < n; x++)
    {

        waitarray[x] = 0;
        turnarray[x] = 0;
    }
    printf("PROCESS_ID          EXECUTED(ms)");
    while (z > 0)
    {
        for (int k = 0; k < n; k++)
        {
            if(p[k].rem!=0)
            {
            if (p[k].rem >= quantum)
            {
                printf("\n   %d                  %d ", p[k].id, quantum);
                timeused = quantum;
            }
            else
            {
                printf("\n   %d                  %d ", p[k].id, p[k].rem);
                timeused = p[k].rem;
            }
            

            for (x = 0; x < n; x++)
            {
                if (x != k && p[x].rem != 0)
                    waitarray[x] += timeused;
            }

            timeelapsed = timeelapsed + timeused;
            ;

            for (x = 0; x < n; x++)
            {
                if (p[x].rem != 0)
                    turnarray[x] += timeused;
            }

            p[k].rem -= timeused;

            if (p[k].rem == 0)
                z--;
        }
        }
    }

    for (x = 0; x < n; x++)
    {
        avgw = avgw + waitarray[x];
        avgt = avgt + turnarray[x];
    }

    printf("\n Total turn around time %f", avgt);
    printf("\n Total wait time %f", avgw);
    printf("\nAverage waiting time is %f", avgw / n);
    printf("\nAverage turnaround time is %f", avgt / n);
}

