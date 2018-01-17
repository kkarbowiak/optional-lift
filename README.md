# Optional lift #

This code illustrates how to 'lift' functions in C++. Lifting is the process of transforming a function into a corresponding function in a different (usually more general) setting. The term comes from functional programming and is used in that domain extensively, but can also be useful in C++.

This particular example transforms functions of signature `T (U)` into functions of signature `optional<T> (optional<U>)`. That is, if for example you have a function that takes an `int` and returns a `std::string` (like `std::to_string`), you can turn it into a function that takes an `optional<int>` and returns an `optional<std::string>`. An empty optional on input produces an empty optional on output. A non-empty optional on input produces a non-empty optional on output and the original function is used to transform the wrapped value.

## License ##

This project is released under **MIT/X11** license, so feel free to do anything you like with it.

