
#include <iostream>
#include "Graph.h"
#include "ResearchSession.h"

using namespace std;

int main() {
    Graph graph;
    ResearchSession session;

    graph.addTopic("Trees");
    graph.addTopic("BST");
    graph.addTopic("Heap");
    graph.addTopic("AVL");
    graph.addTopic("Rotations");

    graph.addConnection("Trees", "BST");
    graph.addConnection("Trees", "Heap");
    graph.addConnection("BST", "AVL");
    graph.addConnection("AVL", "Rotations");

    graph.displayGraph();
    graph.BFS("Trees");
    graph.DFS("Trees");

    cout << "\nSearch BST: "
         << (graph.searchTopic("BST") ? "Found" : "Not Found")
         << endl;

    cout << "Search Trie: "
         << (graph.searchTopic("Trie") ? "Found" : "Not Found")
         << endl;
         session.addEvent(
    ResearchEvent(
        "10:00",
        "Trees",
        "GeeksForGeeks",
        {"tree", "data structure"}
    )
);

session.addEvent(
    ResearchEvent(
        "10:10",
        "BST",
        "YouTube",
        {"BST", "search", "tree"}
    )
);

session.addEvent(
    ResearchEvent(
        "10:20",
        "AVL",
        "GeeksForGeeks",
        {"AVL", "rotation"}
    )
);

session.addEvent(
    ResearchEvent(
        "10:30",
        "BST",
        "Google",
        {"BST", "search"}
    )
);

session.addEvent(
    ResearchEvent(
        "10:40",
        "Rotations",
        "YouTube",
        {"rotation", "AVL"}
    )
);
session.displayHistory();

cout << "\nTotal Research Events: "
     << session.getTotalEvents() << endl;

cout << "Unique Topics: "
     << session.getUniqueTopics() << endl;

     session.displayTopicFrequency();

     
     cout << "\nRepetition Count: "
     << session.getRepetitionCount() << endl;
      

 cout << "\nResearch Depth from Trees: "
     << graph.getResearchDepth("Trees") << endl;

    return 0;
}