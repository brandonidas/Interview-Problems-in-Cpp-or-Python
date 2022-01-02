using namespace std;
/*
base: return [val]
complete 2 levels: return [root],[left,right]
complete 3 levels: return [root],[left,right], [left-left,left-right,right-left,right-right]

This is a still a BFS but we must order children carefully.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <stack>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class ZigzagTraversal {
 public:
  static vector<vector<int> > traverse(TreeNode *root) {
    vector<vector<int> > result;
    deque<TreeNode *> dq;

    dq.push_front(root);
    vector<int> rootLevel;
    rootLevel.push_back(root->val);
    result.push_back(rootLevel);
    bool zig = true;
    while(!dq.empty()) {
      int levelSize = dq.size();
      vector<int> thisLevel;
      deque<TreeNode *> levelDQ;
      while(levelSize > 0) {
        TreeNode *current = dq.back();
        dq.pop_back();
        if (zig) {
          if (current->right != nullptr) {
            levelDQ.push_back(current->right);
          }
          if (current->left != nullptr) {
            levelDQ.push_back(current->left);
          }
        } else {
          if (current->left != nullptr) {
            levelDQ.push_back(current->left);
          }
          if (current->right != nullptr) {
            levelDQ.push_back(current->right);
          }
        }
        levelSize--;
      }
      zig = !zig;

      while(!levelDQ.empty()) {
        TreeNode * current = levelDQ.front();
        levelDQ.pop_front();
        thisLevel.push_back(current->val);
        dq.push_back(current);
      }
      result.push_back(thisLevel);
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  root->right->left->left = new TreeNode(20);
  root->right->left->right = new TreeNode(17);
  vector<vector<int> > result = ZigzagTraversal::traverse(root);
  cout << "Zigzag traversal: ";
  for (auto vec : result) {
    printf("--- ");
    for (auto num : vec) {
      cout << num << " ";
    }
  }
}
