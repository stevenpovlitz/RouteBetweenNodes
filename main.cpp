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

int main(int argc, const char * argv[]) {
    int vecsize = 10;
    std::vector<Node> nodes;
    for (int i = 0; i < vecsize; i++){
        nodes.push_back(Node(i));
    }
    
    setup_nodes(nodes);
    
    displayNodes(nodes);

    return 0;
}
