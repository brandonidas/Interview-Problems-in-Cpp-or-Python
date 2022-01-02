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
    bool zig = true;
    while(!dq.empty()) {
      int levelSize = dq.size();
      int n = levelSize;
      vector<int> thisLevel(levelSize);
      while(levelSize > 0) {
        TreeNode *current = dq.back();
        dq.pop_back();
        if (current->left != nullptr) {
          dq.push_front(current->left);
        }
        if (current->right != nullptr) {
          dq.push_front(current->right);
        }
        levelSize--;
        if (zig) {
          thisLevel[n - levelSize - 1] = current->val;
        } else {
          thisLevel[levelSize] = current->val;
        }
      }
      zig = !zig;
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
