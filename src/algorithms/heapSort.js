import { Heap } from "../dataStructures/index.js"

export function heapSort(arr) {
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
