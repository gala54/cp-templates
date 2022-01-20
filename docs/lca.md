### Overview

> A class for computing the least common ancestor (LCA) of two nodes in a tree using euler tour techinque and range minimum queries

### Usage

- `LCA(int _)`: Constructs a `LCA` object on a tree with `_` nodes and `0` edges
- `LCA(vector<vector<int>>& _)`: Constructs a `LCA` object on a tree represented by adjacency list `_`
- `addEdge(int u, int v)`: Adds an undirected edge between `u` and `v`
- `gen(int root)`: Roots the current tree at `root`
- `get(int u, int v)`: Returns the LCA of `u` and `v`

**NOTE:** `gen(int root)` must be called before `get(int u, int v)`

### Example
