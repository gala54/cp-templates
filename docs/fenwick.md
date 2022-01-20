### Overview

> A data structure that supports point updates and range queries on an array efficiently

### Usage

- `Fenwick(int n)`: Constructs a `Fenwick` object on an array of length `n` with all elements initialized to `0`
- `add(int x, int v)`: Increments the value of index `x` by `v`
- `sum(int x)`: Returns the sum of all elements with indices in the range `[0...x]`
- `sum(int l, int r)`: Returns the sum of all elements with indices in the range `[l...r]`

### Example
