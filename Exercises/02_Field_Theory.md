# Field Theory

## Exploring GF(5) Exercises

- Convince yourself these tables are correct. Hint: they might not be ;-)
    - The Multiplication Table isn't correct 3*3 should result in 4
- What's an easy method to sanity-check a multiplication table? Hint: think about what multiplicative inverses imply about uniqueness.
    - An easy method to check is to take the column of the inverse and flip it


- Explore GF(2). Does it still work? What common computer operation is addition? What common computer operation is multiplication?

GF(2) Tables:

| + | 0 | 1 |
|---|---|---|
| 0 | 0 | 1 |
| 1 | 1 | 0 |

| * | 0 | 1 |
|---|---|---|
| 0 | 0 | 0 |
| 1 | 0 | 1 |

- Addition is equivalent to XOR
- Multiplication is equivalent to AND


- Does GF(4) work if you construct it the same way as above? Why or why not?
    - It doesn't, as doing it like that, two has no inverse


## Definition Exercises

- Are the infinite set of integers {..., -2, -1, 0, 1, 2, ...} a Field using normal addition and multiplication? Why or why not?
    - They aren't since there is no way to multiply (for example 2) to get the Multiplicative Identity, so not every number has an inverse
- (Tricky) Find GF(4). Hint: let a + a = 0 always. Then use the properties of a field to deduce the rest of the addition and multiplication tables. Check that all properties are satisfied.
    - Tried for an hour and failed, might try again at a later time