export class Heap {
    #heap

    constructor(elements) {
        this.#heap = [...elements]
        this.#heapify()
    }

    add(element) {
        this.#heap.push(element)
        this.#heapify()
    }

    remove() {
        const num = this.#heap.shift()
        this.#heapify()
        return num;
    }

    getHeapArray() {
        return this.#heap
    }

    #heapify() {
        for (let i = this.#heap.length - 1; i >= 0; i--) {
            this.#heapifySubtree(i)
        }
    }

    #heapifySubtree(index) {
        const len = this.#heap.length
        const element = this.#heap[index]
        if (!element) return;
        const lChildIndex = index * 2 + 1
        const rChildIndex = index * 2 + 2

        if (lChildIndex < len && rChildIndex <= len) {
            const lChild = this.#heap[lChildIndex]
            const rChild = this.#heap[rChildIndex]


            if (lChild == rChild) return;

            if (lChild > rChild && element < lChild) {
                this.#swap(lChildIndex, index)
                this.#heapifySubtree(lChildIndex)
            } else {
                if (element < rChild) {
                    this.#swap(rChildIndex, index)
                    this.#heapifySubtree(rChildIndex)
                }
            }
        }
    }
    #swap(a, b) {
        const temp = this.#heap[a]
        this.#heap[a] = this.#heap[b]
        this.#heap[b] = temp
    }
}
