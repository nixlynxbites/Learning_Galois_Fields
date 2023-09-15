# Group Theory

## Clock Arithmetic Exercise

- Work through some examples and convince yourself of these facts. Internalizing these ideas is critical to keeping your sanity as things get more abstract.

| a | b | -b | a+b | a-b | a+(-b) |
|---|---|----|-----|-----|--------|
| 5 | 7 | 5  | 0   | 10  | 10     |
| 3 | 3 | 9  | 6   | 0   | 0      |
| 7 | 8 | 4  | 3   | 11  | 11     |

Note: Column (a-b) and (a+(-b)) will always be the same

## Group Definition Exercise

- Convince yourself that our clock is a group according to these definitions.
0. These aren't gonna be proofs, just some examples
1. Associativity
    - (7+8)+9 = 0
    - 7+(8+9) = 0
2. Identity
    - 0 is the additive Identity
    - 1+0=0
3. Inverse
    - 5+7=0
    - 1+11=0
    - 6+6=0

## Modular Arithmetic Exercise

- Play around with the modular arithmetic where n=5 (a) what are the numbers? (b) which number acts as an identity? (c) what is the "additive inverse" of 3? (d) which integers are "equivalent" to 1?
- a) 0; 1; 2; 3; 4
- b) 5 (should be the modulo identity, unsure about this one)
- c) 2
- d) 1; 6; 11; 16; In general 1+k*5

## Modular Arithmetic: Multiplication Exercise

- Does this form a Group? Justify each required property or give a counter-example.
1. Associativity
    - Skipped for now, as assumed to work
2. Identity
    - The Multiplication identity is 1 as a*1 = a
3. Inverse
    - a*b = 1
    - assuming a to be 2, no matter how we multiply, we will always get an even number
    - which means we won't be able to multiply to get the identity

4. Exercise 2)
    - Since Multiplication with a single even number will always result in an even number
    - AND: An even number modulo an even number will also always result in an even number
    - So it is not possible to get an odd number such as our Multiplication identity

## Proof Exercises

- Explore n=5 modular-arithmetic over multiplication using the set {1, 2, 3, 4}: (a) draw the multiplication table (it should have 16 squares), (b) draw the inverse table (it should have 4 squares)

Multiplication Table:

| * | 1 | 2 | 3 | 4 |
|---|---|---|---|---|
| 1 | 1 | 2 | 3 | 4 |
| 2 | 2 | 4 | 1 | 3 |
| 3 | 3 | 1 | 4 | 2 |
| 4 | 4 | 3 | 2 | 1 |

Inverse Table: 

| b | 1 | 2 | 3 | 4 |
|---|---|---|---|---|
|-b | 1 | 3 | 2 | 4 |

- Explore n=4 modular-arithmetic over multiplication using the set {1, 2, 3}: (a) give a counter-example for why this is not a Group

n=4:

| * | 1 | 2 | 3 |
|---|---|---|---|
| 1 | 1 | 2 | 3 |
| 2 | 2 | 0 | 2 |
| 3 | 3 | 2 | 1 |

-> 2 doesn't have an inverse, violating the rule