# Polynomial Arithmetic

## Addition and Subtraction Exercises

- Compute (x^4 + 1) + (3x^4 + x^2)
    - =4x^4 + x^2 +1
- Compute (5) + (x^2 - 4)
    - =x^2 + 1
- Compute (-x^2 + 3) - (-x^2 + 3)
    - =0

## Vector Notation Exercises

- Convert x^4 + 1 to vector notation
    - ->[1; 0; 0; 0; 1]
- Convert 3x^4 + x^2 to vector notation
    - ->[3; 0; 1; 0; 0]
- Sum the previous two answers (vectors) and convert to polynomial representation. This should be the same as your answer to (x^4 + 1) + (3x^4 + x^2)
    - [1; 0; 0; 0; 1] + [3; 0; 1; 0; 0] = [4: 0; 1; 0; 1]
    - -> 4x^4+x^2+1

## Multiplication Exercises

- Compute (x^4 + 2x) * (3x^2 + x + 4). What is the order of the result? How many terms contribute to the resulting x^2 term?
    - (x^4 + 2x) * (3x^2 + x + 4) = 3x^6 + x^5 + 4x^4 + 6x^3 + 2x^2 + 8x
    - The result is a 6th Order Polynominal
    - Two terms contribute (2x and x) (We don't have any x^2 or x^0 terms that can contribute in this formula)

## Multiplication is a Convolution Exercises

-  Check the multiplication above using the ordinary term-by-term, non-convolution approach. ((2x + 3) * (3x + 1))
    - = 6x^2 + 9x + 2x + 3 = 6x^2 + 11x + 3



