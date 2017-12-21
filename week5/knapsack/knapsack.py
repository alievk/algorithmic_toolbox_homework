# Uses python3
import sys
import numpy as np

def optimal_weight(W, w):
    """
    >>> optimal_weight(10, [1, 4, 8])
    9
    """
    n = len(w)
    V = np.zeros((n + 1, W + 1), dtype=int)

    for i in range(1, n + 1):
        wi = w[i - 1]
        for w_cur in range(1, W + 1):
            V[i, w_cur] = V[i - 1, w_cur]
            if w_cur >= wi:
                V[i, w_cur] = max(V[i, w_cur], V[i - 1, w_cur - wi] + wi)

    return V[n][W]


if __name__ == '__main__':
    input = sys.stdin.read()
    W, n, *w = list(map(int, input.split()))
    print(optimal_weight(W, w))
