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

function levelOrder(root: TreeNode | null): number[][] {
    const levelOrderTraversal: number[][] = []
    if (!root) {
        return levelOrderTraversal
    }
    
    const queue = new MyDeque<TreeNode>(5);
    queue.push(root)
    levelOrderTraversal.push([root.val])

    while (queue.length > 0) {
        const currentLayerNodes: TreeNode[] = []
        const nextLayerNumbers: number[] = []

        while (queue.length > 0) {
            currentLayerNodes.push(queue.shift())
        }

        for (const currentLayerNode of currentLayerNodes) {
            if (currentLayerNode.left) {
                queue.push(currentLayerNode.left)
                nextLayerNumbers.push(currentLayerNode.left.val)
            }

            if (currentLayerNode.right) {
                queue.push(currentLayerNode.right)
                nextLayerNumbers.push(currentLayerNode.right.val)
            }
        }

        if (nextLayerNumbers.length > 0) {
            levelOrderTraversal.push(nextLayerNumbers)
        }
    }

    return levelOrderTraversal
};

class MyDeque<T> {
    private data: (T | undefined)[];
    private head: number;
    private tail: number;
    private _size: number;
    private capacity: number;

    constructor(initialCapacity: number = 16) {
        this.capacity = initialCapacity;
        this.data = new Array(this.capacity);
        this.head = 0;
        this.tail = 0;
        this._size = 0;
    }

    private grow(): void {
        const newCapacity = this.capacity * 2;
        const newData = new Array<T | undefined>(newCapacity);

        for (let i = 0; i < this._size; i++) {
            newData[i] = this.data[(this.head + i) % this.capacity];
        }

        this.data = newData;
        this.head = 0;
        this.tail = this._size;
        this.capacity = newCapacity;
    }

    get length(): number {
        return this._size;
    }

    isEmpty(): boolean {
        return this._size === 0;
    }

    push(value: T): void {
        if (this._size === this.capacity) this.grow();
        this.data[this.tail] = value;
        this.tail = (this.tail + 1) % this.capacity;
        this._size++;
    }

    pop(): T | undefined {
        if (this._size === 0) return undefined;
        this.tail = (this.tail - 1 + this.capacity) % this.capacity;
        const value = this.data[this.tail];
        this.data[this.tail] = undefined;
        this._size--;
        return value;
    }

    unshift(value: T): void {
        if (this._size === this.capacity) this.grow();
        this.head = (this.head - 1 + this.capacity) % this.capacity;
        this.data[this.head] = value;
        this._size++;
    }

    shift(): T | undefined {
        if (this._size === 0) return undefined;
        const value = this.data[this.head];
        this.data[this.head] = undefined;
        this.head = (this.head + 1) % this.capacity;
        this._size--;
        return value;
    }

    peekFront(): T | undefined {
        return this._size > 0 ? this.data[this.head] : undefined;
    }

    peekBack(): T | undefined {
        if (this._size === 0) return undefined;
        const lastIndex = (this.tail - 1 + this.capacity) % this.capacity;
        return this.data[lastIndex];
    }
}
