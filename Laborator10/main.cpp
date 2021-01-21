#include <iostream>
#include <string.h>
#include <time.h>
#include "Profiler.h"

Profiler p("dfs");
typedef struct _Node{
    int key;
    char *color;
    int nrVecini;
    int d;
    int f;
    struct _Node** next;
    struct _Node* parent;
}Node;
typedef struct
{
    int nrNodes;
    Node **nodes;
}Graf;
typedef struct _NodeLista
{
    int key;
    struct _NodeLista *next;
}NodeLista;
NodeLista *lista=NULL;
int low[8]={0};

Node* alocaNod(int i, int n)
{
    Node *p=(Node*)calloc(1,sizeof(Node));
    if(p==NULL)
    {
        printf("Not enough memory\n");
        exit(-1);
    }
    p->key=i;
    p->color=(char*)calloc(10,sizeof(char));
    if(p->color==NULL)
    {
        printf("Not enough memory\n");
        exit(-1);
    }
    strcpy(p->color,"WHITE");
    p->next=(Node**)calloc(n,sizeof(Node*));
    if(p->next==NULL)
    {
        printf("Not enough memory\n");
        exit(-1);
    }
    p->nrVecini=0;
    p->parent=NULL;
    p->d=0;
    p->f=0;
    return p;
}
Graf* alocaGraf(int n)
{
    Graf *g=(Graf*)calloc(1,sizeof(Graf));
    if(g==NULL)
    {
        printf("Not enough memory\n");
        exit(-1);
    }
    g->nrNodes=n;
    g->nodes=(Node**)calloc(g->nrNodes+1,sizeof(Node*));
    if(g->nrNodes==NULL) {
        printf("Not enough memory\n");
        exit(-1);
    }
    for(int i=1;i<=g->nrNodes;i++)
        g->nodes[i]=alocaNod(i,g->nrNodes);
    return g;
}
void leagaNoduri(Graf* graf, int i, int j)
{
    graf->nodes[i]->next[graf->nodes[i]->nrVecini++]=graf->nodes[j];

    for(int j=0;j<graf->nodes[i]->nrVecini-1;j++)
    {
        for(int k=j+1;k<graf->nodes[i]->nrVecini;k++)
            if(graf->nodes[i]->next[j]->key > graf->nodes[i]->next[k]->key)
            {
                Node *aux=graf->nodes[i]->next[j];
                graf->nodes[i]->next[j]=graf->nodes[i]->next[k];
                graf->nodes[i]->next[k]=aux;
            }
    }

}
NodeLista* alocaNodLista(Node* u)
{
    NodeLista *p=(NodeLista*)calloc(1,sizeof(NodeLista));
    if(p==NULL)
    {
        printf("Not neough memory\n");
        exit(-1);
    }
    p->key=u->key;
    p->next=NULL;
    return p;
}
void insertList( Node *u)
{
    if(lista==NULL)
        lista=alocaNodLista(u);
    else
    {
        NodeLista *p=lista;
        p=alocaNodLista(u);
        p->next=lista;
        lista=p;
    }
}
int mini(int a, int b)
{
    if(a<b)
        return a;
    return b;
}
void DFS_VISIT(Graf* graf, Node* u, int *time, int ok, Operation *op)
{
    (*time)++;
    u->d = (*time);
    strcpy(u->color, "GRAY");
    if(op!=NULL)
        op->count(2);
    printf("%d ", u->key);
    for (int i = 0; i < u->nrVecini; i++) {
        Node *v = u->next[i];
        if(op!=NULL)
            op->count();
        if (!strcmp(v->color, "WHITE")) {
            v->parent = u;
            DFS_VISIT(graf, v, time, ok, op);
        }
    }
    strcpy(u->color, "BALCK");
    (*time)++;
    u->f = (*time);
    if(op!=NULL)
        op->count();
    if (ok == 1)
        insertList(u);
}
void DFS(Graf* graf, int ok, Operation *op)
{
    for (int i = 1; i <= graf->nrNodes; i++) {
        strcpy(graf->nodes[i]->color, "WHITE");
        graf->nodes[i]->f = 0;
        graf->nodes[i]->d = 0;
        graf->nodes[i]->parent = NULL;
        if(op!=NULL)
            op->count(3);
    }
    int time = 0;
    for (int i = 1; i <= graf->nrNodes; i++) {
        if (strcmp(graf->nodes[i]->color, "WHITE")==0)
            DFS_VISIT(graf, graf->nodes[i], &time, ok, op);
    }
}
void DFS_TARJAN(Graf *graf, Node* u)
{
    strcpy(u->color,"GRAY");
    low[u->key]=u->key;

    for(int i=0;i<u->nrVecini;i++)
    {
        if(strcmp(u->next[i]->color,"WHITE")==0)
            DFS_TARJAN(graf,u->next[i]);
        if(strcmp(u->next[i]->color,"GRAY")==0)
            low[u->key]=mini(low[u->key],low[u->next[i]->key]);
    }

    if(u->key==low[u->key])
    {
        for(int i=1;i<=graf->nrNodes;i++)
        {
            if(low[i]==u->key && strcmp(graf->nodes[i]->color,"GRAY")==0)
            {
                strcpy(graf->nodes[i]->color,"BLACK");
                low[i]=u->key;
            }
        }
    }
}
void Tarjan(Graf* graf)
{
    int time=0;
    for (int i = 1; i <= graf->nrNodes; i++)
        strcpy(graf->nodes[i]->color, "WHITE");

    for(int i=1;i<=graf->nrNodes;i++)
        if(strcmp(graf->nodes[i]->color,"WHITE")==0)
            DFS_TARJAN(graf,graf->nodes[i]);
}
void printGraf(Graf *graf)
{
    for(int i=1;i<=graf->nrNodes;i++)
    {
        printf("\n%d:",i);
        for(int j=0;j<graf->nodes[i]->nrVecini;j++)
            printf(" %d",graf->nodes[i]->next[j]->key);
    }
    printf("\n");
}
void printList()
{
    NodeLista *p=lista;
    printf("\n");
    while(p!=NULL)
    {
        printf("%d ",p->key);
        p=p->next;
    }
}
void printTarjan(Graf* graf) {
    int *fv = (int *) calloc(graf->nrNodes+1, sizeof(int));
    int comp=0;
    for (int i = 1; i <= graf->nrNodes; i++)
    {
        if(fv[low[i]]==0)
        {
            comp++;
            fv[low[i]]=1;
        }
    }
    printf("Sunt %d componente tare conexe\n",comp);
    for(int i=1;i<=graf->nrNodes;i++)
        printf("%d ",low[i]);

}
void demo()
{
    Graf *graf=NULL;

    graf=alocaGraf(8);

    leagaNoduri(graf,1,2);
    leagaNoduri(graf,2,3);
    leagaNoduri(graf,3,1);
    leagaNoduri(graf,4,5);
    leagaNoduri(graf,4,8);
    leagaNoduri(graf,5,6);
    leagaNoduri(graf,6,1);
    leagaNoduri(graf,6,7);
    leagaNoduri(graf,7,1);
    leagaNoduri(graf,7,3);
    leagaNoduri(graf,7,5);
    leagaNoduri(graf,8,6);
    leagaNoduri(graf,8,4);

    printGraf(graf);

    /// 0 pentru DFS normal
    ///DFS(graf,0,NULL);
    printf("\n");

    ///1 pentruu DFS cu Sortare Topologica
    DFS(graf,1,NULL);

    printList();
    printf("\n");

    Tarjan(graf);

    printTarjan(graf);

    free(graf);

}
void perf()
{
    srand(time(0));
    ///variem numarul de muchii
    for(int n=1000; n<=4500;n+=100)
    {
        Operation opVert= p.createOperation("dfs-edges",n);
        Graf *graf=alocaGraf(100);

        int contor=0;
        while(contor<n)
        {
            int rand1=(rand()%99)+1;
            int rand2=(rand()%99)+1;

            if(rand1!=rand2 && graf->nodes[rand1]->nrVecini<100 && graf->nodes[rand2]->nrVecini<100)
            {
                int ok=1;
                for(int i=0;i<graf->nodes[rand1]->nrVecini && ok==1;i++)
                    if(graf->nodes[rand1]->next[i]->key==graf->nodes[rand2]->key)
                        ok=0;
                if(ok==1) {
                    leagaNoduri(graf, rand1, rand2);
                    contor++;
                }
            }
        }
        DFS(graf,0,&opVert);
        for(int i=0;i<=graf->nrNodes;i++)
            free(graf->nodes[i]);
        free(graf);
    }

    ///variem numarul de noduri
    for(int n=100;n<=200;n+=10)
    {
        Operation opEdges=p.createOperation("dfs-vertices",n);
        Graf *graf=alocaGraf(n+1);
        int contor=0;

        while(contor<=4500)
        {
            int rand1=(rand()%99)+1;
            int rand2=(rand()%99)+1;

            if(rand1!=rand2 && graf->nodes[rand1]->nrVecini<100 && graf->nodes[rand2]->nrVecini<99)
            {
                int ok=1;
                for(int i=0;i<graf->nodes[rand1]->nrVecini && ok==1;i++)
                    if(graf->nodes[rand1]->next[i]->key==graf->nodes[rand2]->key)
                        ok=0;
                if(ok==1) {
                    leagaNoduri(graf, rand1, rand2);
                    contor++;
                }
            }
        }
        DFS(graf,0,&opEdges);
        for(int i=0;i<=graf->nrNodes;i++)
            free(graf->nodes[i]);
        free(graf);
    }

    p.showReport();
}
int main() {
    demo();

    ///perf();

    return 0;
}

