
#include <stdio.h>
#include <stdlib.h>

struct qNode {
    int data;
    struct qNode *next;
};

struct Queue{
    struct qNode *front;
    struct qNode *rear;
};

struct Queue *createQueue()
{
 struct Queue * q = (struct Queue*)malloc(sizeof(struct Queue)); 
 q->front = NULL;
 q->rear = NULL;
 return q;
}

int isEmpty(struct Queue *q)
{
    return (q->front == NULL);
}

void  Enqueue(struct Queue *q, int val)
{
 struct qNode * newNode = (struct qNode *)malloc(sizeof(struct qNode));
 newNode->data = val;
 newNode->next = NULL;
 
 if (q->rear == NULL)
 {
     q->front =q->rear =newNode;
 }
 else 
 {
     q->rear->next =newNode;
     q->rear = newNode;
 }
}

int Dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return 0;
    }
    struct qNode * temp = q->front;
    int val =temp->data;
    q->front = q->front ->next;
    
    if (q->front == NULL)
    {
        q->rear =NULL;
    }
    free (temp);
    return val;
}

void printQueue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty!\n");
        return;
    }
     struct qNode * temp = q->front;
     while(temp)
     {
         printf("%d ", temp->data);
             temp =temp->next;
     }
     printf("\n");
    
}

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;

};

struct Node* createNode(int vertex) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    for (int i = 0; i < vertices; i++)
      {  graph->adjLists[i] = NULL;
      }
    return graph;
}




void createEdge(struct Graph* graph, int i, int j) {
    struct Node* newNode1 = createNode(j);
    if (graph->adjLists[i] == NULL) {
        graph->adjLists[i] = newNode1;
    } else {
        struct Node* temp = graph->adjLists[i];
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode1;
    }
    
    struct Node* newNode2 = createNode(i);
    if (graph->adjLists[j] == NULL) {
        graph->adjLists[j] = newNode2;
    } else {
        struct Node* temp = graph->adjLists[j];
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode2;
    }
}

void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjLists[v];
        printf("Vertex %d:\n", v);
        while (temp) {
            printf("%d  -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}



int main() {
    struct Graph* graph = createGraph(5);
    createEdge(graph, 0, 1);
    createEdge(graph, 0, 2);
    createEdge(graph, 1, 3);
    createEdge(graph, 2, 4);

    printGraph(graph);

}