/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

// thinking notes
// if we are at a node r, and when recursively checking its left and right children, if one side returns p, and another q, then r is the lowest common ancestor

// 3 -> 5 (yes)
// 5 -> 6 -> x
// 5 -> 2
// 2 -> 7 -> x
// 2 - > 4 (yes)

function lowestCommonAncestor(root: TreeNode | null, p: TreeNode | null, q: TreeNode | null): TreeNode | null {
    if (!root) return null

    if (root === p || root === q) {
        return root
    }

    const left = lowestCommonAncestor(root.left, p, q)
    const right = lowestCommonAncestor(root.right, p, q)

    if (left && right) {
        return root
    }

    return left || right
};