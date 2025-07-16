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

void addTask(struct Task tasks[], int* task_counter, int ID, char desc[MAX_LEN])
{
    if (*task_counter >= MAX_TASKS)
    {
        printf("TASKS ARE FULL PLEASE DELETE ONE!");
        return;
    }

    tasks[*task_counter].id = ID;
    strncpy(tasks[*task_counter].description, desc, MAX_LEN - 1);
    tasks[*task_counter].description[MAX_LEN - 1] = '\0';
    tasks[*task_counter].completed = false;
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