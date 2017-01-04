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

void vec2vec(vector<int>& v1, vector<int>& v2){
    for(auto i:v1){
        v2.push_back(i);
    }
}

void printvec(vector<int> vec){
    cout << "[";
    for(int i=0;i<vec.size();i++){
        if(i==vec.size()-1)
            cout << to_string(vec[i]);
        else
            cout << to_string(vec[i]) << ",";
    }
    cout << "]" << endl;
}

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

string vec2str(const vector<int>& vec){
    string buffer="";
    buffer += '[';
    for(int i=0;i<vec.size();i++){
        if(i==vec.size()-1)
            buffer += to_string(vec[i]);
        else
            buffer += to_string(vec[i])+',';
    }
    buffer += ']';
    return buffer;
}

TreeNode* vec2tree(const vector<int>& vec){
    TreeNode* root = new TreeNode(vec[0]);
    queue<TreeNode*> q;
    q.push(root);
    for(int i=1;i<vec.size();i++){
        while(q.front()->val==0 && !q.empty()){
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

vector<int> tree2vec(TreeNode* root){
    queue<TreeNode*> q;
    vector<int> vec;
    if(root)
        q.push(root);
    while(!q.empty()){
        if(q.front()){
            if(q.front()->val==0){
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
        }else
            break;
    }
    return vec;
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
    if(i==true)
        cout << "hello world" << endl;
    if(i==false)
        cout << "shibai" << endl;
}

