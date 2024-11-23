# Chromatic_number

The program calculates the chromatic number of given graph (https://en.wikipedia.org/wiki/Graph_coloring), using greedy coloring algorithm. 
The program builds a sequence for this algorithm, that gives a graph coloring (https://en.wikipedia.org/wiki/Greedy_coloring).

The program is created as part of the "Discrete analysis" course by A.M. Raigorodskiy at Moscow Institute of Physics and Technology.

Algorithmic complexity is O(n^2 * n!)

## Input format

The program takes as input a graph without loops and multiple edges.
First you enter the number of vertices. In the k-th string after that you enter the number of adjacent vertices to k-th vertex and then their numbers.

Vertices numbers lie in [0, n-1], where n is the number of vertices.
If the input is incorrect, the program returns an error.

## Output format

The program result is the chromatic number and the coloring of graph for this chromatic number.

## Examples 

### Input 1
4

2 1 2

3 0 2 3

3 0 1 3

2 1 2

### Output 1

Chromatic number: 3

Graph colors: 0 1 2 0

### Input 2

5

4 1 2 3 4

4 0 2 3 4

4 1 0 3 4

4 1 2 0 4

4 1 2 3 0

### Output 2

Chromatic number: 5

Graph colors: 0 1 2 3 4
