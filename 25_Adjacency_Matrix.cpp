#include <iostream>
using namespace std;

class Graph
{
    bool **adjMatrix;
    int numVertex;

public:
    Graph(int numVertex)
    {
        cout << "Constructor is called !" << endl;
        this->numVertex = numVertex;
        adjMatrix = new bool *[numVertex];
        for (int i = 0; i < numVertex; i++)
        {
            adjMatrix[i] = new bool[numVertex];
            for (int j = 0; j < numVertex; j++)
                adjMatrix[i][j] = false;
        }
    }

    void addEdge(int i, int j)
    {
        cout << "Addition is called !" << endl;
        adjMatrix[i][j] = adjMatrix[j][i] = true;
    }

    void deleteEdge(int i, int j)
    {
        cout << "Deletion is called !" << endl;
        adjMatrix[i][j] = adjMatrix[j][i] = false;
    }

    void print()
    {
        cout << "Print is called !" << endl;

        for (int i = 0; i < numVertex; i++)
        {
            cout << i << " : ";
            for (int j = 0; j < numVertex; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }

    ~Graph()
    {
        cout << "Destructor is called !" << endl;
        for (int i = 0; i < numVertex; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};

int main()
{
    Graph G(4);

    G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(0, 3);
    G.addEdge(1, 0);
    G.addEdge(1, 2);
    G.addEdge(1, 3);
    G.addEdge(2, 0);
    G.addEdge(2, 3);
    // G.addEdge();

    G.print();

    return 0;
}