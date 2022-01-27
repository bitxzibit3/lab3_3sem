//
// Created by Timur on 27.01.2022.
//

#include "Menu.h"

std::string MSGS[] = {"0. Quit", "1. Dijkstra algorithm", "2. Find the best way", "3. Add edge", "4. Print graph matrix"};

int MSGS_SIZE = sizeof(MSGS)/sizeof(MSGS[0]);

void dialog() {
    int choice = 1, vertexes = 0;
    while (vertexes <= 0)
    {
        std::cout << "Enter vertexes count: ";
        std::cin >> vertexes;
        if (vertexes <= 0)
            std::cout << "You entered a wrong number!" << std::endl;
    }
    Graph<int> graph (vertexes);
    int edges = -1;
    while (edges < 0)
    {
        std::cout << "Enter count of edges: ";
        std::cin >> edges;
        if (edges < 0)
            std::cout << "You entered a wrong number!" << std::endl;
    }
    std::cout << "Enter edges like: 1 3 20 (first vertex, second vertex, edge weight):" << std::endl;
    for (int i = 0; i < edges; i++)
    {
        int first, second, weight;
        std::cin >> first >> second >> weight;
        graph.AddEdge(first, second, weight);
    }
    while (true)
    {
        std::cout << "Make your choice:" << std::endl;
        for (int i = 0; i < MSGS_SIZE; i++)
            std::cout << MSGS[i] << std::endl;
        std::cin >> choice;
        switch (choice)
        {
            case (0):
                return;
            case(1):
            {
                int start = -1;
                while ((start < 0) || (start >= vertexes))
                {
                    std::cout << "Enter the start vertex from 0 to " << vertexes - 1 << std::endl;
                    std::cin >> start;
                    if ((start < 0) || (start >= vertexes))
                        std::cout << "You entered a wrong number!" << std::endl;
                }
                std::cout << graph.Dijsktra(start) << std::endl;
                break;
            }
            case (2):
            {
                int start = -1, end = -1;
                while ((start < 0) || (end < 0) || (start >= vertexes) || (end >= vertexes))
                {
                    std::cout << "Enter start and end vertexes from 0 to " << vertexes - 1 << std::endl;
                    std::cin >> start >> end;
                    if ((start < 0) || (end < 0) || (start >= vertexes) || (end >= vertexes))
                        std::cout << "You entered a wrong number!" << std::endl;
                }
                ArrSeq<int> ans = graph.BestWay(start, end);
                std::cout << "The best way from " << start << " to " << end << "is: ";
                for (int i = ans.GetSize() - 1; i >= 0; i--)
                    std::cout << ans[i] << " ";
                std::cout << std::endl;
                break;
            }
            case (3):
            {
                std::cout << "Enter edges like: 1 3 20 (first vertex, second vertex, edge weight):" << std::endl;
                int first, second, weight;
                std::cin >> first >> second >> weight;
                graph.AddEdge(first, second, weight);
                break;
            }
            case (4):
            {
                graph.Print();
                break;
            }
            default:
            {
                std::cout << "You made a wrong choice!" << std::endl;
                break;
            }
        }
    }
}
