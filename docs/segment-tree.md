### Overview

> A data structure that supports point updates and range queries on an array efficiently

### Usage

- `SegTree(int _)`: Constructs a `SegTree` object on an array of length `_` with all elements initialized to `0`
- `SegTree(const vector<int>& _)`: Constructs a `SegTree` object on the array `_`
- `modify(int p, int val)`: Sets value of index `p` to `val`
- `query(int a, int b)`: Returns the sum of all elements with indices in the range `[a...b]` 	

### Example
