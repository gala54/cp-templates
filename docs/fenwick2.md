### Overview

> A data structure that supports point updates and subrectangle queries on a 2D array

### Usage

- `Fenwick2(int x, int y)`: Constructs a `Fenwick2` object on a 2D array with dimensions `x` by `y` with all elements initialized to `0`
- `add(int x, int y, int v)`: Increments the value of position `(x, y)` by `v`
- `sum(int x, int y)`: Returns the sum of all elements in the subrectangle `[0, x] x [0, y]`
- `sum(int a, int b, int c, int d)`: Returns the sum of all elements in the subrectangle `[a, b] x [c, d]`

### Example
