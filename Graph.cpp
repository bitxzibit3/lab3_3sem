//
// Created by Timur on 27.12.2021.
//

#include "Graph.h"

template<class EdgeType>
Graph<EdgeType>::Graph(ArrSeq<ArrSeq<EdgeType>> edge) {
    int size = edge.GetSize();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++) {
            if (edge[i][j] == (EdgeType) 0.)
                edges[i][j] = (EdgeType) (9999999.);
            else
                edges[i][j] = edge[i][j];
        }
    }
}

template<class EdgeType>
void Graph<EdgeType>::AddEdge(int first, int second, EdgeType weight) {
    if ((first < 0) || (second < 0) || (first >= edges.GetSize()) || (second >= edges.GetSize()))
    {
        std::cout << "Edge cant be added!" << std::endl;
        return;
    }
    edges[first][second] = weight;
    edges[second][first] = weight;
}

template<class EdgeType>
EdgeType Graph<EdgeType>::GetWeight(int first, int second) {
    return edges[first][second];
}

template<class EdgeType>
bool Graph<EdgeType>::Linked(int first, int second) {
    return (GetWeight(first, second) != (EdgeType)9999999.);
}

template<class EdgeType>
Graph<EdgeType>::Graph(int verts) {
    edges.Resize(verts);
    for (int i = 0; i < verts; i++)
        edges[i] = ArrSeq<EdgeType> (verts, (EdgeType)(9999999.));
}

template<class EdgeType>
ArrSeq<EdgeType> Graph<EdgeType>::Dijsktra(int start) {
    int Size = edges.GetSize();
    ArrSeq<EdgeType> ans (Size, (EdgeType)(9999999.));
    ArrSeq<bool> used (Size, false);
    ans[start] = 0;
    int min_vert_idx = start;
    for (int i = 0; i < Size; i++)
    {
        for (int v = 0; v < Size; v++)
            if (!used[v])
            {
                min_vert_idx = v;
                break;
            }
        for (int v = 0; v < Size; v++) // Поиск вершины.
        {
            if (!used[v])
                if (ans[v] < ans[min_vert_idx])
                    min_vert_idx = v;
        }
        used[min_vert_idx] = true;
        EdgeType min_length = (EdgeType)(9999999.);
        int next_min_vert;
        for (int i = 0; i < Size; i++) {
            if (Linked (min_vert_idx, i)) {
                if (ans[i] > ans[min_vert_idx] + GetWeight(min_vert_idx, i))
                    ans[i] = ans[min_vert_idx] + GetWeight(min_vert_idx, i);
                if (ans[i] < min_length) {
                    min_length = ans[i];
                    next_min_vert = i;
                }
            }
        }
        min_vert_idx = next_min_vert;
    }
    return ans;
}


template<class EdgeType>
int Graph<EdgeType>::Component() {
    ArrSeq<EdgeType> dij = Dijsktra(0);
    int counter = 1;
    int size = dij.GetSize();
    for (int i = 0; i < size; i++)
        if (dij[i] == (EdgeType)(9999999.))
            counter++;
    return counter;
}

template<class EdgeType>
ArrSeq<int> Graph<EdgeType>::BestWay(int start, int end) {
    int Size = edges.GetSize();
    ArrSeq<EdgeType> ans (Size, (EdgeType)(9999999.));
    ArrSeq<bool> used (Size, false);
    ArrSeq<int> parents (0, Size);
    ans[start] = 0;
    int min_vert_idx = start;
    for (int i = 0; i < Size; i++)
    {
        for (int v = 0; v < Size; v++)
            if (!used[v])
            {
                min_vert_idx = v;
                break;
            }
        for (int v = 0; v < Size; v++) // Поиск вершины.
        {
            if (!used[v])
                if (ans[v] < ans[min_vert_idx])
                    min_vert_idx = v;
        }
        used[min_vert_idx] = true;
        EdgeType min_length = (EdgeType)(9999999.);
        int next_min_vert;
        for (int i = 0; i < Size; i++) {
            if (Linked (min_vert_idx, i)) {
                if (ans[i] > ans[min_vert_idx] + GetWeight(min_vert_idx, i))
                {
                    ans[i] = ans[min_vert_idx] + GetWeight(min_vert_idx, i);
                    parents[i] = min_vert_idx;
                }
                if (ans[i] < min_length) {
                    min_length = ans[i];
                    next_min_vert = i;
                }
            }
        }
        min_vert_idx = next_min_vert;
    }
    int p = end;
    ArrSeq<int> path;
    path.Append (p);
    while (p != start)
    {
        path.Append(parents[p]);
        p = parents[p];
    }
    return path;
}

template<class EdgeType>
int Graph<EdgeType>::GetVertexes() {
    return edges.GetSize();
}

template<class EdgeType>
void Graph<EdgeType>::Print() {
    int v = GetVertexes();
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (Linked(i, j))
                std::cout << GetWeight(i, j) << " ";
            else
                std::cout << " - " << " ";
        }
        std::cout << std::endl;
    }
}


