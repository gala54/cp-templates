### Overview

> A data structure that supports range updates and range queries on an array efficiently using lazy propagation

### Usage

- `SegTree(int _)`: Constructs a `SegTree` object on an array of length `_` with all elements initialized to `0`
- `SegTree(const vector<int>& _)`: Constructs a `SegTree` object on the array `_`
- `modify(int a, int b, int val)`: Increases all elements with indices in the range `[a...b]` by `val`
- `query(int a, int b)`: Returns the sum of all elements with indices in the range `[a...b]` 	

### Example
