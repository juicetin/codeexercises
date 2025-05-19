// https://leetcode.com/problems/clone-graph

/**
 * Definition for _Node.
 * class _Node {
 *     val: number
 *     neighbors: _Node[]
 * 
 *     constructor(val?: number, neighbors?: _Node[]) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.neighbors = (neighbors===undefined ? [] : neighbors)
 *     }
 * }
 * 
 */

 class _Node {
     val: number
     neighbors: _Node[]
 
     constructor(val?: number, neighbors?: _Node[]) {
         this.val = (val===undefined ? 0 : val)
         this.neighbors = (neighbors===undefined ? [] : neighbors)
     }
 }

function cloneGraph(node: _Node | null): _Node | null {
    if (!node) {
        return null
    }

    const visited = new Map<_Node, _Node>();

    const dfs = (node: _Node | null): _Node | null => {
        if (!node) {
            return null
        }

        if (node && visited.has(node)) {
            return visited.get(node) || null
        }

        const clonedNode = new _Node(node?.val)
        visited.set(node, clonedNode)

        for (const neighbor of node.neighbors) {
            const clonedNeighbhor = dfs(neighbor)
            if (clonedNeighbhor) {
                clonedNode.neighbors.push(clonedNeighbhor)
            }
        }

        return clonedNode
    }

    return dfs(node)   
};
