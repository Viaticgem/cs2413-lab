/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int checkAVL(struct TreeNode* node, long long min, long long max) {
    if (node == NULL) {return 0;}
    
    if (node->val <= min || node->val >= max) {return -1;}

    int left = checkAVL(node->left, min, node->val);
    if (left == -1) return -1;

    int right = checkAVL(node->right, node->val, max);
    if (right == -1) return -1;

    int diff = left - right;
    if (diff < -1 || diff > 1) {return -1;}

    return (left > right ? left : right) + 1;
}

bool isAVL(struct TreeNode* root) {
    return checkAVL(root, LLONG_MIN, LLONG_MAX) != -1;
}
