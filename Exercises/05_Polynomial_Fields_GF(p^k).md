# Polynomial Fields GF(p^k)

## Coefficients from an arbitrary Field Exercises

- Using GF(7) for coefficients, compute (2x^2 + 3) + (4x^2 + 2x + 2)
    - = 6x^2 + 2x + 5
- If we use GF(2) for coefficients, how would we compute (2x^2 + 3) + (4x^2 + 2x + 2)? Notice that 2, 3, 4 are not elements of GF(2). But 2 == 0 (mod 2), 3 == 1 (mod 2), 4 == 0 (mod 2). Convince yourself the answer would be 1.
    - Since 4 == 0(mod 2) we can simplify to
        - (2x^2 + 3) + (0x^2 + 2x +2)
    - Since 2 == 0(mod 2) we can simplify to
        - 3 + 0
    - Since 3 == 1(mod 2) we can simplify to
        - 1
        - I'm convinced
- Using GF(2) for coefficients, compute (x^2 + 1) + (x^2 + x + 1)
    - = 0x^2 + x + 0
    - = x
- Using GF(5) for coefficients, compute (2x^2 + 1) * (2x^2 + 3)
    - = 4x^4 + 1x^2 + 2x^2 + 3
    - = 4x^4 + 3x^2 + 3
- Using GF(2) for coefficients, compute (x + 1) * (x)
    - = x^2 + x

## More Notation Exercise

- List the polynomials in GF(2)[x] with order < 3. How many does the theory predict?
    - 0; 1; x; x+1; x^2; x^2+1; x^2+x; x^2+x+1;
    - 2^3 = 8 polynomials

## More representations Exercises

- Complete the above table for order < 3

| Polynomial    | Vector    | Number    |
|---------------|-----------|-----------|
| 0             | [0, 0, 0] | 0         |
| 1             | [0, 0, 1] | 1         |
| 2             | [0, 0, 2] | 2         |
| x             | [0, 1, 0] | 3         |
| x + 1         | [0, 1, 1] | 4         |
| x + 2         | [0, 1, 2] | 5         |
| 2x            | [0, 2, 0] | 6         |
| 2x + 1        | [0, 2, 1] | 7         |
| 2x + 2        | [0, 2, 2] | 8         |
| x^2           | [1, 0, 0] | 9         |
| x^2 + 1       | [1, 0, 1] | 10        |
| x^2 + 2       | [1, 0, 2] | 11        |
| x^2 + x       | [1, 1, 0] | 12        |
| x^2 + x + 1   | [1, 1, 1] | 13        |
| x^2 + x + 2   | [1, 1, 2] | 14        |
| x^2 + 2x      | [1, 2, 0] | 15        |
| x^2 + 2x + 1  | [1, 2, 1] | 16        |
| x^2 + 2x + 2  | [1, 2, 2] | 17        |
| 2x^2          | [2, 0, 0] | 18        |
| 2x^2 + 1      | [2, 0, 1] | 19        |
| 2x^2 + 2      | [2, 0, 2] | 20        |
| 2x^2 + x      | [2, 1, 0] | 21        |
| 2x^2 + x + 1  | [2, 1, 1] | 22        |
| 2x^2 + x + 2  | [2, 1, 2] | 23        |
| 2x^2 + 2x     | [2, 2, 0] | 24        |
| 2x^2 + 2x + 1 | [2, 2, 1] | 25        |
| 2x^2 + 2x + 2 | [2, 2, 2] | 26        |

- Build a similar comparison table for GF(2)[x] where order < 4. What's the largest number (in all representations)? Why?
    - The largest number is 26, or 2* 3^2 + 2* 3 + 2
    - or 3^3-1
    - or p^k-1
    - Because we have p^k different Values, and since 0 is part of these values the biggest number can only be p^k-1

| Polynomial        | Vector        | Number    |
|-------------------|---------------|-----------|
| 0                 | [0, 0, 0, 0]  | 0         |
| 1                 | [0, 0, 0, 1]  | 1         |
| x                 | [0, 0, 1, 0]  | 2         |
| x + 1             | [0, 0, 1, 1]  | 3         |
| x^2               | [0, 1, 0, 0]  | 4         |
| x^2 + 1           | [0, 1, 0, 1]  | 5         |
| x^2 + x           | [0, 1, 1, 0]  | 6         |
| x^2 + x + 1       | [0, 1, 1, 1]  | 7         |
| x^3               | [1, 0, 0, 0]  | 8         |
| x^3 + 1           | [1, 0, 0, 1]  | 9         |
| x^3 + x           | [1, 0, 1, 0]  | 10        |
| x^3 + x + 1       | [1, 0, 1, 1]  | 11        |
| x^3 + x^2         | [1, 1, 0, 0]  | 12        |
| x^3 + x^2 + 1     | [1, 1, 0, 1]  | 13        |
| x^3 + x^2 + x     | [1, 1, 1, 0]  | 14        |
| x^3 + x^2 + x + 1 | [1, 1, 1, 1]  | 15        |

- From 56, determine the coefficients for the corresponding polynomial in GF(2)[x]. This is a very important skill to have for later sections. What common operation in computing are you doing in this exercise?
    - 56/2 = 28 R0
    - 28/2 = 14 R0
    - 14/2 = 7  R0
    - 7/2  = 3  R1
    - 3/2  = 1  R1
    - 1/2  = 0  R1
    - The coefficients are [1, 1, 1, 0, 0, 0]
    - The common operation done here is bit shifts
- Convert x^6 + x + 1 from GF(2)[x] into the decimal number representation.
    - = 2^6 + 2 + 1
    - = 64 + 2 + 1
    - = 67

## Irreducible Polynomials Exercises

- Is x^2 + 1 an irreducible polynomial in GF(2)[x]? Why or why not?
    - No
    - (x^2 + 1)/(x + 1) = x + 1
- Is x^2 + x + 1 an irreducible polynomial in GF(2)[x]? Why or why not?
    - Yes
    - (x^2 + x + 1) / (x + 1) = x R1
    - (x^2 + x + 1) / (x) = x + 1 R1
- Is x^2 + x be an irreducible polynomial for some F[x]? Why or why not?
    - No
    - (x^2 + x) / x = x + 1

## GF(3^2) by example Exercises

- Check this calculation yourself. (C % Q = (2x^2 + x) % (x^2 + 1))
    - (2x^2 + x) / (x^2 +1) = 2 Rx+1
    - -> (2x^2 + x) % (x^2 +1) = x+1
- Compute x * x in our GF(9) field using the irreducible polynomial x^2 + 1
    - = x^2
- Determine the inverse of x in our GF(9) field using the irreducible polynomial x^2 + 1
    - (x * inv(x))%(x^2+1) = 1
    - (x * inv(x)) = 2x^2
    - -> inv(x) = 2x = 6
    - Proof:
    - (x*2x)/(x^2+1) = 2 R1
    - -> (x*2x)/(x^2+1) = 1
- Build a multiplication table for GF(2^3) using the irreducible polynomial x^3 + x + 1

| * | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
| 2 | 0 | 2 | 4 | 6 | 3 | 1 | 7 | 5 |
| 3 | 0 | 3 | 6 | 5 | 7 | 4 | 1 | 2 |
| 4 | 0 | 4 | 3 | 7 | 6 | 2 | 5 | 1 |
| 5 | 0 | 5 | 1 | 4 | 2 | 7 | 3 | 6 |
| 6 | 0 | 6 | 7 | 1 | 5 | 3 | 2 | 4 |
| 7 | 0 | 7 | 5 | 2 | 1 | 6 | 4 | 3 |

|           | 0 | 1 | 2 | 3     | 4     | 5         | 6         | 7         |
|-----------|---|---|---|-------|-------|-----------|-----------|-----------|
| Stands for| 0 | 1 | x | x+1   | x^2   | x^2 +1    | x^2 +x    | x^2 +x +1 |

## Operation tables for GF(3^2) Exercise

- Check as many additions and multiplications as you need to until you fully understand where this table comes from. If the above table still feels like magic, you haven't done enough exercises. (Q = x^2 + 1)
    - Multiplications have been checked, by calculating the multiplication table in the previous exercises entirely by hand
    - Addition
        - 4+6 = 1
            - (x+1) + (2x) = 1
        - 2+7 = 6
            - (2) + (2x+1) = 2x
        - 7+1 = 8
            - (2x+1) +1 = 2x+2
        - 3+5 = 8
            - (x) + (x+2) = 2x+2
        - 4+8 = 0
            - (x+1) + (2x+2) = 0
            