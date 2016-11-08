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
        
        path[startIndex].pushNodePointer(&path[endIndex]);
    }
    
}

void testSystem(std::vector<Node> &path) {
    for (int i = 0; i < path.size(); i++){
        std::cout << "Node " << i << "\nPoints to: " << std::endl;
        for (int j = 0; j < path[i].getPathsSize(); j++){
            std::cout << path[i].getPathAtIndex(j)
        }
        
    }
}

int main(int argc, const char * argv[]) {
    int vecsize = 10;
    std::vector<Node> nodes;
    for (int i = 0; i < vecsize; i++){
        nodes.push_back(Node(i));
    }
    
    
    
    setup_nodes(nodes);
    
    std::cout << "Hello, World!\n";
    return 0;
}
