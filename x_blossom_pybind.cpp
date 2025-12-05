#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "graph.h"
#include "blossom.h"   // or blossom_api.h, wherever x_blossom_maximum_matching is declared

namespace py = pybind11;

// Thin wrapper: take CSR from Python, build Graph, call C++ API, return matching.
std::vector<int> max_matching_csr(const std::vector<int>& rowOffsets,
                                  const std::vector<int>& columnIndices,
                                  int num_threads) {
    // Construct Graph
    Graph G(rowOffsets, columnIndices);

    // Call C++ API
    std::vector<int> M(G.num_of_nodes, -1);
    x_blossom_maximum_matching(G, M, num_threads);

    // Return matching vector to Python
    return M;
}

PYBIND11_MODULE(x_blossom, m) {
m.doc() = "Python bindings for the X-Blossom maximum matching algorithm";

m.def("max_matching_csr", &max_matching_csr,
py::arg("row_offsets"),
py::arg("column_indices"),
py::arg("num_threads") = 8,
R"pbdoc(
Compute a maximum matching on a general graph given in CSR format.

Parameters
----------
row_offsets : List[int]
    CSR row offset array of length n+1.
column_indices : List[int]
    CSR column index array.
num_threads : int, optional
    Number of worker threads to use (default: 8).

Returns
-------
List[int]
    Matching vector M of length n, where M[v] is the mate of v, or -1 if unmatched.
)pbdoc");
}