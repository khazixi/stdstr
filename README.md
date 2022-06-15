# Standard String Library

## Why

I created this library because I wanted to take my own attempt at a string library.
I wanted to start small with my first C library and possibly use this within other projects.


## Information

I plan to have 2 string types based on the owning and non-owning model for strings:
- `str_view` is the non-owned (Allocated on the stack) version of a string
- `str_dynamic` is the owned (Allocated on the Heap) version of the string

For the non-owning strings I plan to have the constructor written as such `str_view a = str_view_create("John")`.
`str_view_create` returns the struct on the stack so no memmory allocators should be needed.
`str_view_from_dynamic` functions as a conversion from the `str_dynamic` type to the `str_view` type.
`str_view_compare` allows `str_view` objects to be compared byte by byte.


`str_dynamic` returns a pointer to the struct on the heap made using malloc (I don't know how to make a custom allocator).
`str_dynamic` like `str_view` has the similar comparison, and conversion functions.
`str_dynamic` has various helper functions as well such as `str_dynamic_reverse`, `str_dynamic_upper`, `str_dynamic_lower` and many more.
Because `str_dynamic` is allocated it must be deallocated with `str_dynamic_destroy`.
