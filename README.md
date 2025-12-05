# X-Blossom

This is the code repository for compiling X-Blossom Python package


---

## Download the code repository for X-Blossom

Firstly, use the command line below to download this repository.

```
$ git clone https://github.com/Davis-Fan/X-Blossom_Python_Package.git
$ cd X-Blossom_Python_Package
```

---

## Compile X-Blossom Python Package


1) Create a new folder to contain the complied file

```
$ mkdir test
$ cd test
```

2) Complie code

```
$ cmake ..
$ cmake --build . --target x_blossom --config Release
```

3) You should see a Python file ending with ".so" (such as: x_blossom.cpython-313-darwin.so). This can be directly use in your Python program. To use this, you have to set the Python path so that the Python can find it.



4) The usage of Python package is the same as C++ version. Here you can only input "rowOffset.txt" and "columnIndices.txt", and two test Python programs has been provided (/test/test_1.py and /test/test2.py).


