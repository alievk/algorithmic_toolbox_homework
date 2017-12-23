# Uses python3
import sys


def optimal_sequence(n):
  sequence = []
  while n >= 1:
    sequence.append(n)
    if n % 3 == 0:
      n = n // 3
    elif n % 2 == 0:
      n = n // 2
    else:
      n = n - 1
  return reversed(sequence)


def optimal_sequence_fast(n):
  """
  >>> len(optimal_sequence_fast(1)) - 1
  0
  >>> len(optimal_sequence_fast(5)) - 1
  3
  >>> len(optimal_sequence_fast(96234)) - 1
  14
  """
  P = [0] * (n + 1)

  for i in range(2, n + 1):
    P[i] = P[i - 1] + 1
    if i % 2 == 0:
      P[i] = min(P[i], P[i // 2] + 1)
    if i % 3 == 0:
      P[i] = min(P[i], P[i // 3] + 1)

  seq = []
  k = n
  while k > 1:
    seq.append(k)
    next_k = k - 1
    min_op = P[next_k]
    if k % 2 == 0 and P[k // 2] < min_op:
      next_k = k // 2
      min_op = P[next_k]
    if k % 3 == 0 and P[k // 3] < min_op:
      next_k = k // 3
    k = next_k

  seq.append(1)

  return seq[::-1]


input = sys.stdin.read()
n = int(input)
sequence = list(optimal_sequence_fast(n))
print(len(sequence) - 1)
for x in sequence:
  print(x, end=' ')
