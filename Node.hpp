//
//  Node.hpp
//  RouteBetweenNodes
//
//  Created by Steven Povlitz on 11/7/16.
//  Copyright © 2016 Steven Povlitz. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <vector>

class Node {
private:
    std::vector<Node*> paths;
    int index; // for debugging and setup
public:
    Node(int index){
        this->index = index;
    }
    
    void pushNodePointer(Node * newNode) {
        paths.push_back(newNode);
    }
    
    int getPathsSize() {
        return int(paths.size());
    }
    
    Node* getPathAtIndex(int index) {
        return paths[index];
    }
    int getIndex(){
        return index; // for debugging and setup
    }
};

#endif /* Node_hpp */
