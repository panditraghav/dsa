/** 
* Creates a graph using adjacency list (A Map)
 */
export function createListGraph() {
    return new Map()
}

export function insertEdgeListGraph(graph, src, dest) {
    if (
        !graph.get(src)?.push(dest)
    ) {
        graph.set(src, [dest])
    }
}

export function BFSListGraph(graph, start, value) {
    const queue = [start]
    const visited = new Set < T > ([start])
    let level = 0

    while (queue.length > 0) {
        const head = queue.shift()
        level++;
        console.log(head)
        if (head == undefined) throw Error("Queue is empty but inside loop??");
        if (head === value) {
            console.log(`${value} found it!, level: ${level}`)
        }
        const children = graph.get(head)

        if (children) {
            for (const val of children) {
                if (val === value) {
                    console.log(`${value} found it!, level: ${level}`)
                    return;
                }
                if (!visited.has(val)) {
                    visited.add(val)
                    queue.push(val)
                }

            }
        }
    }
}

export function DFSListGraph(graph, start, value, visited = new Set()) {
    visited.add(start)
    if (start === value) {
        console.log(start + ' Found it!')
    } else
        console.log(start)
    const children = graph.get(start)
    if (children) {
        for (const c of children) {
            if (!visited.has(c)) {
                DFSListGraph(graph, c, value, visited)
            }
        }
    }
}

export default function graph() {
    const myGraph = createListGraph()
    insertEdgeListGraph(myGraph, 0, 1);
    insertEdgeListGraph(myGraph, 0, 2);
    insertEdgeListGraph(myGraph, 1, 3);
    insertEdgeListGraph(myGraph, 2, 4);

    console.log(myGraph)
    BFSListGraph(myGraph, 0)
    console.log("-------")
    BFSListGraph(myGraph, 0, 3)
}
