//
// Created by Timur on 27.12.2021.
//

#include "Graph.h"

template<class EdgeType>
Graph<EdgeType>::Graph(ArrSeq<ArrSeq<EdgeType>> edge) {
    int size = edge.GetSize();
    for (int i = 0; i < size; i++)
        edges[i] = edge[i];
}

template<class EdgeType>
void Graph<EdgeType>::AddVerticle() {
    edges.Append(ArrSeq<EdgeType>());
    for (auto it = edges.begin(); it != edges.end(); ++it)
        (*it).Append ((EdgeType)0);
}

template<class EdgeType>
void Graph<EdgeType>::AddEdge(int first, int second, EdgeType weight) {
    if ((first >= edges.GetSize()) || (second >= edges.GetSize()))
        return;
    edges[first][second] = weight;
    edges[second][first] = weight;
}

template<class EdgeType>
EdgeType Graph<EdgeType>::GetWeight(int first, int second) {
    return edges[first][second];
}

template<class EdgeType>
bool Graph<EdgeType>::Linked(int first, int second) {
    return (GetWeight(first, second) == (EdgeType)0);
}

template<class EdgeType>
Graph<EdgeType>::Graph(int verts) {
    edges.Resize(verts);
    for (int i = 0; i < verts; i++)
        edges[i].Resize(verts);
}

template<class EdgeType>
ArrSeq<EdgeType> Graph<EdgeType>::Dijsktra(int start) {
    int Size = edges.GetSize();
    ArrSeq<EdgeType> ans (Size, (EdgeType)(0.));
    ArrSeq<bool> used (Size, false);

}


