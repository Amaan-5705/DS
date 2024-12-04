#include <stdio.h>
#include <stdlib.h> // For system("cls") in place of clrscr()

// Function prototype for DFS
void dfs(int v);

// Global variables for graph representation
int n, i, j, a[10][10], vis[10];

int main() {
    // Clear the screen (specific to Turbo C, use system("cls") for modern compilers)
    system("cls");

    // Input the number of vertices
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
        vis[i] = 0; // Initialize visited array to 0
    }

    // Perform DFS Traversal
    printf("DFS Traversal:\n");
    for (i = 0; i < n; i++) {
        if (vis[i] == 0) { // Check if the vertex is not visited
            dfs(i); // Call dfs for unvisited vertex
        }
    }

    // Wait for user input before closing the program
    getchar();  // To handle the console window if necessary
    return 0;
}

void dfs(int v) {
    printf("%d ", v + 1); // Print the current vertex (Add 1 for 1-based indexing)
    vis[v] = 1; // Mark the vertex as visited

    // Visit adjacent vertices
    for (j = 0; j < n; j++) {
        if (a[v][j] == 1 && vis[j] == 0) { // If adjacent and not visited
            dfs(j); // Recursively visit adjacent vertices
        }
    }
}
