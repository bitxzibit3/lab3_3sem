//
// Created by Timur on 27.12.2021.
//

#ifndef LAB3_GRAPH_H
#define LAB3_GRAPH_H

#include <cstdlib>
#include "./Array/ArrSeq.h"

template <class EdgeType>
class Graph
{
protected:
    ArrSeq<ArrSeq<EdgeType>> edges;
public:
    Graph (int);
    Graph(ArrSeq<ArrSeq<EdgeType>>);
    void AddVerticle();
    void AddEdge (int, int, EdgeType);
    EdgeType GetWeight (int, int);
    bool Linked (int, int);
    ArrSeq<EdgeType> Dijsktra (int);
};



#endif //LAB3_GRAPH_H
