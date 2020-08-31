# Exception

From: [https://en.cppreference.com/w/cpp/language/exceptions](https://en.cppreference.com/w/cpp/language/exceptions)

## Introduction

Exception handling provides a way of transferring control and information from some point in the execution of a program to a handler associated with a point previously passed by the execution.

    In other words, exception handling transfers control up the call stack.

In order for an exception to be caught, the throw-expression has to be:

1. inside a try-block (or)
2. inside a function called from a try-block

and there has to be:

1. a catch clause that matches the type of the exception object.

### Insights about possibility for a function to throw exception

can be provided either through

1. **exception specifications** (or)
2. **noexcept** specifiers

These limit the types of the exceptions a function may throw.

### Errors that arise during exception handling

are handled either by

1. **std::terminate** (or)
2. **std::unexpected** (until C++17).

## Uses of Exception

Throwing an exception is used to signal **"Errors"** from functions.

**Errors** are typically limited to only the following

    1. Failures to meet the postconditions, such as failing to produce a valid return value object
    2. Failures to meet the preconditions of another function that must be called
    3. Failures to (re)establish a class invariant (for non-private member functions)

### Exceptions in Constructors

In particular, this implies that:

    The failures of constructors (see also RAII) and most operators should be reported by throwing exceptions.

### Exceptions in Wide-Contract Functions

    Wide contract functions use exceptions to indicate unacceptable inputs;

For example, _std::string::at_ has no preconditions, but throws an exception to indicate index out of range.

## Exception safety

After the error condition is reported by a function, additional guarantees may be provided with regards to the state of the program. This is called as **Exception Safety**.

The following four levels of exception guarantee are generally recognized. They are **strict supersets of each other**:

1. **Nothrow (or nofail) exception guarantee** -- the function never throws exceptions.

    1. Such functions always succeed.
    2. In this case, errors are reported by other means or concealed.
    3. Nothrow is expected of destructors and other functions that may be called during stack unwinding.
    4. **The destructors are noexcept by default**.
    5. (since C++11) Nofail is expected of swaps, move constructors, and other functions used by those that provide strong exception guarantee.

2. **Strong exception guarantee** -- If the function throws an exception, the state of the program is rolled back to the state just before the function call.

    1. for example, std::vector::push_back

3. **Basic exception guarantee** -- If the function throws an exception, the program is in a valid state.

    1. No resources are leaked, and all objects' invariants are intact.

4. **No exception guarantee** -- If the function throws an exception, the program may not be in a valid state.

    1. resource leaks, memory corruption, or other invariant-destroying errors may have occurred.

5. **Exception-neutral guarantee** (Provided by Generic components) -- if an exception is thrown from a template parameter, it is propagated, unchanged, to the caller.

    1. e.g. from the Compare function object of std::sort or from the constructor of T in std::make_shared

## Exception objects

Objects that may be thrown as exception are:

    0. (Idealy anything - Refer **What should I throw**)
    1. Objects of any complete type
    2. cv pointers to void may be
    3. anonymous temporary objects by value (Thrown by all standard library functions)

**Note:**

1. The types of those objects are derived (directly or indirectly) from std::exception.
2. To avoid unnecessary copying of the exception object and object slicing, the best practice for catch clauses is to catch by reference.

## What should I throw

From: [https://isocpp.org/wiki/faq/exceptions#what-to-throw](https://isocpp.org/wiki/faq/exceptions#what-to-throw)

C++, unlike just about every other language with exceptions, is very accomodating when it comes to what you can throw. In fact, you can throw anything you like. That begs the question then, what should you throw?

Generally, it’s best to throw objects, not built-ins. If possible, you should throw instances of classes that derive (ultimately) from the std::exception class. By making your exception class inherit (ultimately) from the standard exception base-class, you are making life easier for your users (they have the option of catching most things via std::exception), plus you are probably providing them with more information (such as the fact that your particular exception might be a refinement of std::runtime_error or whatever).

## Rethrowing

Captured exceptions can be rethrown using **throw** inside the catch block.

Avoid modifying and rethrowing, since it could lead to **Object Splicing** (down casting to parent type, which may cause the loss of original objects attributes).

    try {
        std::string("abc").substr(10); // throws std::length_error
    } catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    //  throw e; // Wrong: copy-initializes a new exception object of type std::exception
        throw;   // rethrows the exception object of type std::length_error
    }
