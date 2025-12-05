import x_blossom

# Dummy CSR just to sanity-check that the call works
row_offsets = [0, 1, 2]       # 2 vertices, each with 1 neighbor (fake example)
column_indices = [1, 0]       # 0<->1

M = x_blossom.max_matching_csr(
    row_offsets,
    column_indices,
    num_threads=1
)

print("mate array M:", M)

