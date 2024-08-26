#include <vector>
#include <iostream>
#include <map>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }
        return dfs(node);
    }
private:
    map<Node*, Node*> oldToNew;
    Node* dfs(Node* node){
        if(oldToNew.find(node) != oldToNew.end()){
            return oldToNew[node];
        }
        Node* copy = new Node(node->val);
        oldToNew[node] = copy;
        for(Node* neighbor : node->neighbors){
            copy->neighbors.push_back(dfs(neighbor));
        }
        return copy;
    }
};


int main(){
    cout << "Input: " << endl;
    cout << "Output: " << endl;
    return 0;
}