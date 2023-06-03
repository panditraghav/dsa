export class Heap {
    private heap: number[]

    constructor(elements: number[]) {
        this.heap = [...elements]
        this.heapify()
    }

    add(element: number) {
        this.heap.push(element)
        this.heapify()
    }

    remove(): number | undefined {
        const num = this.heap.shift()
        this.heapify()
        return num;
    }

    getHeapArray(): number[] {
        return this.heap
    }

    private heapify() {
        for (let i = this.heap.length - 1; i >= 0; i--) {
            this.heapifySubTree(i)
        }
    }

    private heapifySubTree(index: number) {
        const len = this.heap.length
        const element = this.heap[index]
        if (!element) return;
        const lChildIndex = index * 2 + 1
        const rChildIndex = index * 2 + 2

        if (lChildIndex < len && rChildIndex <= len) {
            const lChild = this.heap[lChildIndex]
            const rChild = this.heap[rChildIndex]


            if (lChild == rChild) return;

            if (lChild > rChild && element < lChild) {
                this.swap(lChildIndex, index)
                this.heapifySubTree(lChildIndex)
            } else {
                if (element < rChild) {
                    this.swap(rChildIndex, index)
                    this.heapifySubTree(rChildIndex)
                }
            }
        }
    }
    private swap(a: number, b: number) {
        const temp = this.heap[a]
        this.heap[a] = this.heap[b]
        this.heap[b] = temp
    }
}

export function heapSort(arr: number[]) {
    const heap = new Heap(arr)
    const sortedArr = []

    for (let i = 0; i < arr.length; i++) {
        const element = heap.remove()
        if (element) {
            sortedArr.push(element)
        }
    }
    return sortedArr
}
