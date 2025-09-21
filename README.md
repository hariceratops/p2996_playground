
# p2996-playground

## Requirements
Requires the experimental clang compiler from Bloomberg which
implements paper p2996

The compiler has to built from source. Below commands builts clang, clangd
and libcxx

The built clangd can be used with LSP clients in text editors like Neovim

```bash
# from the llvm-project root
cmake -S llvm -B build -DLLVM_ENABLE_ASSERTIONS=ON -DLLVM_UNREACHABLE_OPTIMIZE=ON -DCLANG_DEFAULT_CXX_STDLIB=libc++ -DLLVM_ENABLE_PROJECTS="clang;clang-tools-extra" -DLLVM_ENABLE_RUNTIMES="libcxx;libcxxabi;libunwind" -DCMAKE_BUILD_TYPE=Release
sudo cmake --install build --prefix /usr/local/clang/21.0.0
```

## Building
```bash
cmake .. -DCMAKE_CXX_COMPILER=/usr/local/clang/21.0.0/bin/clang++ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
```

Required flags and setup to build against the custom libcxx 
with our built-out-of source clang is taken care by the CMakeLists.txt
