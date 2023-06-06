export function merge(arrA, arrB) {
    const mergedArr = new Array(arrA.length + arrB.length)
    let i = 0;
    let j = 0;
    let k = 0;

    while (i < arrA.length && j < arrB.length) {
        const eleA = arrA[i]
        const eleB = arrB[j]

        if (eleA < eleB) {
            mergedArr[k] = eleA
            i++;
            k++;
        } else {
            mergedArr[k] = eleB
            j++;
            k++;
        }
    }

    for (; i < arrA.length; i++) {
        mergedArr[k++] = arrA[i]
    }

    for (; j < arrB.length; j++) {
        mergedArr[k++] = arrB[j]
    }
    return mergedArr
}

export default function mergeSort() {

}
