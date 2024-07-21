def is_safe(board, row, col, N):
    # Kiểm tra hàng trước đó cùng cột
    for i in range(row):
        if board[i] == col:
            return False

    # Kiểm tra đường chéo chính
    for i in range(row):
        if board[i] - i == col - row:
            return False

    # Kiểm tra đường chéo phụ
    for i in range(row):
        if board[i] + i == col + row:
            return False

    return True

def solve_n_queens(board, row, N):
    if row == N:
        return 1

    count = 0
    for col in range(N):
        if is_safe(board, row, col, N):
            board[row] = col
            count += solve_n_queens(board, row + 1, N)
            board[row] = -1  # Quay lui
    return count

def count_n_queens_solutions(N):
    board = [-1] * N
    return solve_n_queens(board, 0, N)

# Ví dụ: Đếm số cách xếp 8 quân hậu lên bàn cờ 8x8
N = 13
print("Số cách xếp", N, "quân hậu lên bàn cờ", N, "x", N, "là:", count_n_queens_solutions(N))
