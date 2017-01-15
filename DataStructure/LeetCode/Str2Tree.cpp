#include <iostream>
#include <string>
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

TreeNode* Str2Tree(string s){
    //先把s中的元素抽取出来，存放在一个vector<string>中。
    vector<string> vec;
    for(int i=1;i<s.size()-1;i++) {
        string buffer="";
        while(i<s.size()-1 && s[i]!=','){
            buffer += s[i];
            i++;
        }
        vec.push_back(buffer);
    }
    //然后把vector<string>中的这些结点，读入树中，由于s是层次遍历的结果，所以用广度优先遍历的逆过程就行了
    TreeNode* root = new TreeNode(stoi(vec[0]));
    queue<TreeNode*> q;
    q.push(root);
    for(int i=1;i<vec.size();i++){
        while(q.front()==NULL && !q.empty()){
            q.pop();
        }
        if(!q.empty()){
            TreeNode* new_node = new TreeNode(0);
            if(vec[i]=="null")
                new_node = NULL;
            else
                new_node->val = stoi(vec[i]);
            q.front()->left = new_node;
            q.push(new_node);
            i++;
            if(i<vec.size()){
                TreeNode* new_node1 = new TreeNode(0);
                if(vec[i]=="null")
                    new_node1 = NULL;
                else
                    new_node1->val = stoi(vec[i]);
                q.front()->right = new_node1;
                q.push(new_node1);
            }
            q.pop();
        }
    }
    return root;
}

string Tree2Str(TreeNode* root){
    string s="[";
    s += to_string(root->val)+",";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        while(q.front()==NULL && !q.empty())
            q.pop();
        if(q.front()!=NULL){
            q.push(q.front()->left);
            if(q.front()->left==NULL){
                s += "null,";
            }
            else{
                s += to_string(q.front()->left->val)+",";
            }
            q.push(q.front()->right);
            if(q.front()->right==NULL){
                s += "null,";
            }
            else{
                s += to_string(q.front()->right->val)+",";
            }
            q.pop();
        }

    }
    return s;
}


void isSameNode(TreeNode* p, TreeNode* q, bool& flag){
    if(p==NULL && q==NULL)
        return ;
    if((p==NULL && q!=NULL) || (p!=NULL && q==NULL)){
        flag=false;
        return ;
    }
    if(p->val==q->val){
        if(p->left && q->left){
            isSameNode(p->left, q->left, flag);
        }
        if((p->left&&!q->left) || (!p->right&&q->right)){
            flag=false;
            return ;
        }
        if(p->right && q->right){
            isSameNode(p->right, q->right, flag);
        }
        if((p->right&&!q->right) || (!p->right&&q->right)){
            flag=false;
            return ;
        }

    }else{
        flag=false;
        return ;
    }
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    bool flag = true;
    isSameNode(p, q, flag);
    return flag;
}

int main() {
    string s1 = "[5,4,7,null,null,2,5,-1,null,9]";
    string s2 = "[5,4,7,null,null,3,5,-1,null,9]";
    bool i = isSameTree(vec2tree(str2vec(s1)), vec2tree(str2vec(s2)));

}
