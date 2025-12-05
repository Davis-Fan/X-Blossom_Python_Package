import x_blossom

def read_ints(path):
    with open(path) as f:
        return [int(x) for x in f.read().split()]

row_file = input("Enter rowOffsets file path: ")
col_file = input("Enter columnIndices file path: ")

row_offsets = read_ints(row_file)
column_indices = read_ints(col_file)

print("len(row_offsets) =", len(row_offsets))
print("len(column_indices) =", len(column_indices))

M = x_blossom.max_matching_csr(
    row_offsets,
    column_indices,
    num_threads=4
)

num_matched_vertices = sum(1 for x in M if x != -1)
matching_size = num_matched_vertices // 2
print("matching size (number of edges):", matching_size)
print("first 20 entries:", M[:20])

