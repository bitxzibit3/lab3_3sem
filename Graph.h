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
    void AddEdge (int, int, EdgeType);
    EdgeType GetWeight (int, int);
    bool Linked (int, int);
    int Component ();
    ArrSeq<EdgeType> Dijsktra (int);
    ArrSeq<int> BestWay (int, int);
    int GetVertexes ();
    void Print();
};



#endif //LAB3_GRAPH_H
