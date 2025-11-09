#include <stdio.h>
#define MAX 10
int adj[MAX][MAX];
int visited[MAX];
int n;
void createGraph() {
    int i, j;
    printf("Enter number of cities: ");
    scanf("%d", &n);
printf("Enter adjacency matrix (0 or 1):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
}

void DFS(int start) {
    int i;
    visited[start] = 1;
    printf("%d ", start);
    for (i = 0; i < n; i++) {
        if (adj[start][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

void BFS(int start) {
    int queue[MAX], front = 0, rear = -1;
    int i, current;
    for (i = 0; i < n; i++)
        visited[i] = 0;
    queue[++rear] = start;
    visited[start] = 1;
    printf("%d ", start);
    while (front <= rear) {
        current = queue[front++];
        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                printf("%d ", i);
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int start, choice;
    createGraph();
    printf("\nEnter starting city index (0 to %d): ", n - 1);
    scanf("%d", &start);
    do {
        printf("\n\n--- MENU ---");
        printf("\n1. Display all cities reachable using DFS");
        printf("\n2. Display all cities reachable using BFS");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                for (int i = 0; i < n; i++)
                    visited[i] = 0;
                printf("\nCities reachable using DFS: ");
                DFS(start);
                break;
                     case 2:
                printf("\nCities reachable using BFS: ");
                BFS(start);
                break;
            case 3:
                printf("\nExiting Program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid Choice!");
        }
    } while (choice != 3);
    return 0;
}
