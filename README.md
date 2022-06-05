# Standard String Library

## Why

I created this library because I wanted to take my own attempt at a string library.
I wanted to start small with my first C library and possibly use this within other projects.


## Information

I plan to have 2 string types based on the owning and non-owning model for strings:
- `str_view` is the non-owned version of a string
- `str_dynamic` is the owned version of the string

For the non-owning strings I plan to have the constructor written as such `str_view a = str_view_create("John")`
`str_view_create` returns the struct on the stack so no memmory allocators should be needed.
`str_view_from_dynamic` functions as a conversion from the `str_dynamic` type to the `str_view` type
