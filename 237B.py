def main():
    import sys
    data = sys.stdin.read().strip().split()
    # First number is n (number of rows)
    n = int(data[0])
    idx = 1
    table = []
    for _ in range(n):
        c = int(data[idx]); idx += 1
        row = []
        for _ in range(c):
            row.append(int(data[idx]))
            idx += 1
        table.append(row)
    # We need to count pairs (i, j): some cell & some “finish cell” such that values <= finish cell
    # Actually editorial: number of ways to choose finish cell = total number of cells.
    # And number of ways to choose obstacle cell = total number of cells minus number of cells in last row.
    # So answer = total_cells - cells_in_last_row + 1
    total = 0
    for row in table:
        total += len(row)
    last_row_cells = len(table[-1]) if table else 0
    print(total - last_row_cells + 1)

if __name__ == "__main__":
    main()
