### Overview

> A class that supports arithmetic operations under mod

### Usage

* Constants:
    - `P`: Desired modulus; change accordingly
* Class functions:
    - `inv()`: Returns the modular inverse of the current object
* Utility:
    - `init(int n)`: Computes the factorial `fac[i]` and inverse factorial `iFac[i]` for all integers `i` from `[0...n]`; **must be called before** `fac`, `iFac`, **and** `C(int n, int k)` **can be used**
    - `fac[i]`: Stores the factorial of `i` modulo `P`
	- `iFac[i]`: Stores the inverse factorial of `i` modulo `P`
    - `C(int n, int k)`: Returns `n` choose `k` modulo `P`
    - `power(T a, int b)`: Returns an `a` ^ `b`; if this value is large, make sure to cast `a` as an object of type `Z`
    

**NOTE**: operations work under the assumption that `P` is prime

### Example
