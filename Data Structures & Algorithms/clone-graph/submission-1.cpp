class Solution {

    Node* DFS(Node* node, unordered_map<Node*,Node*>& mp){
        Node* clone_node = new Node(node->val);
        mp[node] = clone_node;
        for(auto it : node->neighbors){
            if(mp.find(it) == mp.end()){
                clone_node->neighbors.push_back(DFS(it,mp));
            }
            else{
                clone_node->neighbors.push_back(mp[it]);
            }
        }
        return clone_node;
    }

public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*,Node*> mp;
        return DFS(node,mp);
    }
};
