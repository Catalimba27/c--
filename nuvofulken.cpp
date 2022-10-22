// C++ programa creado con la implementacion del algoritmo ford fulkerson

#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;
 
// Numero de vertices en el grafico dado
#define V 7
 
/* Devuelve verdadero si hay una ruta desde la fuente 's' hasta el sumidero
  't' en gráfico residual. También llena parent[] para almacenar el
  sendero*/
bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    // Crea una matriz visitada y marca todos los vértices como no
    // visitado
    bool visited[V];
    memset(visited, 0, sizeof(visited));
 
   // Crear una cola, poner en cola el vértice de origen y marcar el origen
    //  como vértice visitado
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
 
    // Standard BFS Loop
    while (!q.empty()) {
        int u = q.front();
        q.pop();
 
        for (int v = 0; v < V; v++) {
            if (visited[v] == false && rGraph[u][v] > 0) {
                // Si encontramos una conexión con el nodo sumidero,
                // entonces ya no tiene sentido que usemos BFS solo
                // tenemos  que establecer su parent y puede regresar a
                // true o verdadero
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
 
    // No alcanzamos el sumidero en BFS a partir de la fuente, por lo que
    // falso retorno
    return false;
}
 
// retornar el flujo maximo  desde "s" hasta "t" en el grafico dado
int fordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;
 
// Crear un gráfico residual y llenar el gráfico residual
    // con capacidades dadas en el gráfico original como
    // capacidades residuales en gráfico residual
    int rGraph[V]
              [V]; // Gráfico de residuos donde rGraph[i][j]
                   // indica la capacidad residual del borde
                   // de i a j (si hay un borde. Si
                   // rGraph[i][j] es 0, entonces no lo hay)

    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];
 
    int parent[V]; // Esta matriz se llena con BFS y para                 
                   // store path
 
    int max_flow = 0; // No hay flujo inicial
 
    // Aumente el flujo mientras haya un camino desde la fuente hasta
    //en sink o "pileta"

    while (bfs(rGraph, s, t, parent)) {
       // Encontrar la capacidad residual mínima de los bordes a lo largo de
        // la ruta completada por BFS. O podemos decir encontrar el
        // flujo máximo a través del camino encontrado.
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
 
        // actualizar las capacidades residuales de los bordes y
        // bordes inversos a lo largo de la ruta
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
 
        // Agregar flujo de ruta al flujo general
        max_flow += path_flow;
    }
 
    // Devolver el flujo general
    return max_flow;
}
 
// Controlador de programa para probar o testear la funciones anteriores
int main()
{
    // Se crea un grafico acontinuacion como ejemplo
    int graph[V][V]
        = { { 0 ,5 , 3,  1 ,0 , 0, 0 },  
            { 0 ,0 , 0 , 0 ,3 , 0, 0 },  
            { 0 ,0 , 0 , 0 ,1 , 3, 0 },  
            { 0 ,0 , 0 , 0 ,0 , 3, 0 },
            { 0 ,0 , 0 , 0 ,0 , 0, 3 },
            { 0 ,0 , 0 , 0 ,0 , 0, 8 },
            { 0 ,0 , 0 , 0 ,0 , 0 ,0 }

                                             
            };
 
    cout << "El flujo maximo posible es "
         << fordFulkerson(graph, 0, 6);
 
    return 0;
}