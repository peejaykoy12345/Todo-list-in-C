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
        int mid = (left + right) / 2;
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
        printf("TASKS ARE FULL PLEASE DELETE ONE!\n");
        return;
    }

    tasks[*task_counter].id = ID;
    strncpy(tasks[*task_counter].description, desc, MAX_LEN - 1);
    tasks[*task_counter].description[MAX_LEN - 1] = '\0';
    tasks[*task_counter].completed = false;

    (*task_counter)++; // fix this (was postfix, didn't actually increase the value)
    printf("Task added!\n");
}

void deleteTask(struct Task tasks[], int *n, int ID)
{
    int i = findTask(tasks, ID, *n);
    if (i == -1)
    {
        printf("Task with ID %d not found.\n", ID);
        return;
    }

    for (int j = i; j < *n - 1; j++)
    {
        tasks[j] = tasks[j + 1];
    }
    (*n)--;
    printf("Task deleted!\n");
}

void printAllTasks(struct Task tasks[], int* task_counter)
{
    setvbuf(stdout, NULL, _IONBF, 0);

    if (*task_counter == 0)
    {
        printf("No tasks yet.\n");
        return;
    }

    for (int i = 0; i < *task_counter; i++)
    {
        printf("%d. Task Description: %s | Task ID: %d\n", i + 1, tasks[i].description, tasks[i].id);
    }
    printf("DONE\n");
}

int main()
{
    struct Task tasks[MAX_TASKS] = {};
    int task_counter = 0;

    while (true)
    {
        printf("Input a mode: ");
        char mode[6];
        scanf("%5s", mode);

        if (strcmp(mode, "add") == 0)
        {
            int id;
            char desc[MAX_LEN];
            printf("Enter task ID: ");
            scanf("%d", &id);
            getchar(); 

            printf("Enter task description: ");
            fgets(desc, MAX_LEN, stdin);
            desc[strcspn(desc, "\n")] = '\0'; 

            addTask(tasks, &task_counter, id, desc);
        }
        else if (strcmp(mode, "del") == 0)
        {
            int id;
            printf("Enter task ID to delete: ");
            scanf("%d", &id);
            deleteTask(tasks, &task_counter, id);
        }
        else if (strcmp(mode, "print") == 0)
        {
            printAllTasks(tasks, &task_counter);
        }
        else if (strcmp(mode, "exit") == 0)
        {
            break;
        }
        else
        {
            printf("Invalid input\n");
        }
    }
    return 0;
}
