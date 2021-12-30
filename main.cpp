#include <iostream>
#include "Graph.cpp"
#include "Array/ArrSeq.cpp"

int main() {
    Graph<int> graph(3);
    graph.AddEdge(0, 1, 10);
    graph.AddEdge(1, 2, 20);
    graph.AddEdge(0, 2, 30);
//    std::cout << graph.Linked(1, 2) << graph.GetWeight(0, 2);
//    ArrSeq<int> arr;
//    arr.Append(3);
//    arr.Append(3);
//    arr.Append(3);
//    arr.Append(3);
//    std::cout << arr;
    return 0;
}
