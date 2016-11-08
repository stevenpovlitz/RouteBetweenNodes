//
//  main.cpp
//  RouteBetweenNodes
//
//  Created by Steven Povlitz on 11/7/16.
//  Copyright © 2016 Steven Povlitz. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Node.hpp"



// initialize vecsize number nodes, each of which neccessarily points to at least one
// other node
void setup_nodes(std::vector<Node> &path){
    for (int i = 0; i < path.size() * 2; i++) {
        int startIndex = rand() % path.size();
        int endIndex = rand() % path.size();
        if (!path[startIndex].pushNodePointer(&path[endIndex]))
            i--; // means we tried to push a pointer twice onto the same node, redo the loop run
    }
    
}

void displayNodes(std::vector<Node> &path) {
    for (int i = 0; i < path.size(); i++){
        std::cout << "Node " << i << "\nPoints to: " << std::endl;
        for (int j = 0; j < path[i].getPathsSize(); j++){
            std::cout << path[i].getPathAtIndex(j)->getIndex() << ", ";
        }
        std::cout << std::endl << std::endl;
        
    }
    std::cout << std::endl;
}

// returns false if either node is stuck on an "island"
bool solveSingleCircle(std::vector<Node*> *beenHere, Node *currentNode, Node *startingNode, Node *endingNode){
    bool successfulSolve = false;
    beenHere->push_back(currentNode);
    
    if (currentNode == endingNode) {
        std::cout << currentNode->getIndex() << ", ";
        return true;
    }
    
    for (int i = 0; i < beenHere->size(); i++) {
        if (currentNode == beenHere->at(i)){
            return false;
        }
    }
    
    for (int i = 0; i < currentNode->getPathsSize(); i++) {
        if(solveSingleCircle(beenHere, currentNode->getPathAtIndex(i), startingNode, endingNode)){
            std::cout << currentNode->getIndex() << ", ";
        }
    }
    
    return successfulSolve;
}

int main(int argc, const char * argv[]) {
    int vecsize = 5;
    std::vector<Node> nodes;
    for (int i = 0; i < vecsize; i++)
        nodes.push_back(Node(i));
    setup_nodes(nodes);
    std::vector<Node*> beenHere;
    
    // chose a start and an end node
    Node *startingNode = &nodes[rand() % nodes.size()];
    Node *endingNode = &nodes[rand() % nodes.size()];
    
    while (startingNode == endingNode){
        endingNode = &nodes[rand() % nodes.size()];
    }

    std::cout << "starting index is: " << startingNode->getIndex() << ". Ending index is: " << endingNode->getIndex() << std::endl;
    
    displayNodes(nodes);
    
    if (!solveSingleCircle(&beenHere, &nodes[0], startingNode, endingNode)) {
        //std::cout << "On an island" << std::endl;
    }
    
    for (int i = 0; i < beenHere.size(); i++){
        std::cout << beenHere[i]->getIndex() << ", ";
    }
    

    return 0;
}
