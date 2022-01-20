### Overview

> A data structure maintained on a graph that can efficiently
> - Merge two components
> - Query if two nodes are in the same component
> - Query the size of a node's component

### Usage

- `dsu(int n)`: Constructs a `dsu` object on a graph with `n` nodes and `0` edges
- `find(int x)`: Returns the leader of the component containing node `x`
- `same(int x, int y)`: Returns `true` if `x` and `y` belong to the same component, returns `false` otherwise
- `merge(int x, int y)`: Merges the components containing `x` and `y`; returns `false` if `x` and `y` are already in the same component, `true` otherwise
- `size(int x)`: Returns the size of the component containing `x`

### Example
