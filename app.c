#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LEN 100

struct Task
{
    int id;
    char description[MAX_LEN];
    bool completed;
};

int findTask(struct Task tasks[], int ID, int task_counter)
{
    int left = 0;
    int right = task_counter - 1;

    while (left <= right)
    {
        int mid = (int) ((left + right) / 2);

        int task_id = tasks[mid].id;

        if (task_id == ID)
        {
            return mid;
        }
        else if (task_id < ID)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

void deleteTask(struct Task tasks[], int *n, int ID) {
  
  	int i = findTask(tasks, ID, *n);
  	
    for (int j = i; j < *n - 1; j++) {
        tasks[j] = tasks[j + 1];
    }
    (*n)--; 
}

int main()
{
    struct Task tasks[MAX_TASKS] = {};

    return 0;
}