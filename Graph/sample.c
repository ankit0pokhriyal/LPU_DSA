#include <stdio.h>
#include <stdlib.h>


// Create the datatype of single Link  
struct Node {
  // Create integer datatype for vertex
  // Use Self refrencing pointer to create address for next element
};

// Create the datatype of graph
struct Graph {
    // Create intger datatype for index of Linked List 
    // Using  refrencing pointerSingle Linke(Node) create 2d matrix
    // consisting of No.of Linked List in 1d and address of Liked List in another
};

// Create single LinkList
struct Node* createNode(int V) {
  // Create a pointer variable of Single Link type to create data of single Linked list
  // store other arguments
  // return the variable
}

// Create  Graph
struct Graph* createGraph(int vertices) {
    // Create a pointer variable of Graph type to create data of Graph (USE graph as varaiable Name)
    struct Graph* graph = malloc(sizeof(struct Graph));
    // store No. of Liked List
    graph->numVertex = vertices;
    // Store List of Linked List in graph(NOTE size 2d i.e. n* LinkedLists)
    // return the variable
    return graph;
}

void createEdge(struct Graph* graph, int i, int j) {
    // Create variable storing Node
    // make it store/insert last element of graphList
}

void printGraph(struct Graph* graph) {
    // print  the index of graph list from 0 to last vertex of graph
    // till data inside the vertex available print data of SingleNode


}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Graph* graph = createGraph(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        createEdge(graph, u, v);
    }

    printGraph(graph);
    return 0;
}
