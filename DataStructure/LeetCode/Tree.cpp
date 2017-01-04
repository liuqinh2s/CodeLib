#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

vector<int> str2vec(string s){
    vector<int> vec;
    for(int i=1;i<s.size()-1;i++){
        string buffer="";
        while(i<s.size()-1 && s.at(i)!=','){
            buffer += s.at(i);
            i++;
        }
        stringstream ss;
        ss << buffer;
        int n;
        ss >> n;
        vec.push_back(n);
    }
    return vec;
}

TreeNode* createTree(vector<int>& vec){
    TreeNode* root = new TreeNode(vec[0]);
    queue<TreeNode*> q;
    q.push(root);
    for(int i=1;i<vec.size();i++){
        while(!q.front()->val && !q.empty()){
            q.pop();
        }
        if(!q.empty()){
            TreeNode* new_node = new TreeNode(vec[i]);
            q.front()->left = new_node;
            q.push(new_node);
            i++;
            if(i<vec.size()){
                TreeNode* new_node = new TreeNode(vec[i]);
                cout << vec[i];
                q.front()->right = new_node;
                q.push(new_node);
            }
            q.pop();
        }
    }
    return root;
}

void printVector(vector<int> vec){
    cout << "{";
    for(int i=0;i<vec.size();i++){
        if(i==vec.size()-1)
            cout << vec[i];
        else
            cout << vec[i] << ",";
    }
    cout << "}";
}

vector<int> printTree(TreeNode* root){
    queue<TreeNode*> q;
    vector<int> vec;
    if(root)
        q.push(root);
    while(!q.empty()){
        if(q.front()){
            if(q.front()->val){
                vec.push_back(NULL);
                q.pop();
                continue;
            }
            vec.push_back(q.front()->val);
            if(q.front()->val){
                q.push(q.front()->left);
                q.push(q.front()->right);
                q.pop();
            }
        }
    }
    return vec;
}

int main() {
//    vector<int> vec1 = {"2",NULL,"4","6","3","9",NULL,NULL,"6","3"};
    string s = "[5,4,7,3,null,2,null,-1,null,9]";
    vector<int> vec = str2vec(s);
    printVector(vec);
    vector<int> vec2 = {2,3,4};
    vector<int> vec3;
//    printVector(vec1);
//    TreeNode* root = createTree(vec1);
//    vec3 = printTree(root);
//    printVector(vec3);
}
