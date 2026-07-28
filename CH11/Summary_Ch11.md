# Namespaces and Separate Compilation in C++

## 1. The Problem Namespaces Solve

Two independent pieces of code may want to use the same natural name for a
type or function (e.g., two libraries both defining something called
`speed`). Without any mechanism to separate these, the names would collide
and the compiler couldn't tell them apart.

A **namespace** wraps a group of declarations under a named scope, so the
same identifier can exist in multiple namespaces without conflict. The full
identity of a name declared this way is its _qualified name_:

```cpp
namespace A
{
    void f();
}
```

Outside the namespace, this function must be referred to as `A::f()` unless
you bring it into scope with a `using` declaration or directive.

- `using std::cout;` — a **local using declaration**: brings in just `cout`
  from `std`, nothing else.
- `using namespace std;` — a **using directive**: brings in _everything_
  from `std`. Safe inside a small block/function; risky at global file
  scope in large projects because it defeats the purpose of namespaces
  (reintroduces the collision problem) and can quietly resolve names to
  the wrong overload.

The `::` operator is the **scope resolution operator** — it says "get this
name specifically from that namespace/scope."

## 2. Declarations vs. Definitions

This distinction is the backbone of separate compilation:

| Term                        | What it is                                         | Example            | Where it lives       |
| --------------------------- | -------------------------------------------------- | ------------------ | -------------------- |
| **Declaration** (prototype) | Tells the compiler a name exists and its signature | `void f();`        | Header file (`.h`)   |
| **Definition**              | The actual implementation/body                     | `void f() { ... }` | Source file (`.cpp`) |

The compiler only needs a **declaration** to check that calls to a function
are well-formed (right name, right argument types). It does **not** need
the definition at that point — that's resolved later, by the linker.

## 3. Header Files (`.h`)

A header file is the **interface**: it declares what exists, without
saying how it works internally. Example, `f.h`:

```cpp
#ifndef F_H
#define F_H

namespace A
{
    void f();
}

#endif
```

### Include guards

`#ifndef F_H` / `#define F_H` / `#endif` is an **include guard**. It
prevents the same header's contents from being processed more than once
within a single translation unit (a single `.cpp` file plus everything it
pulls in via `#include`, expanded by the preprocessor).

Why this matters: if a header gets `#include`d twice (directly, or
indirectly through a chain of other headers), the compiler would otherwise
see the same declaration twice and — depending on what's being declared —
could throw a redefinition error. The guard's logic:

1. First inclusion: `F_H` is not yet defined → `#ifndef` succeeds →
   `#define F_H` runs (marking it as now defined) → the rest of the file
   is processed.
2. Any subsequent inclusion in the same translation unit: `F_H` is already
   defined → `#ifndef` fails → the preprocessor skips straight to
   `#endif`, so the contents are never processed twice.

Macro names conventionally use the file name in uppercase
(`F_H`, `SPEED_H`, etc.) — this is a style convention (macros aren't
case-sensitive in meaning, but the convention flags "this is a
preprocessor macro").

`#pragma once` is a common non-standard alternative that achieves the same
effect with one line, supported by essentially all modern compilers.

## 4. Source Files (`.cpp`)

Each header's corresponding `.cpp` file holds the actual **definition**,
and includes its own header (so the compiler can cross-check the
definition matches the declared signature):

```cpp
// f.cpp
#include <iostream>
#include "f.h"

using std::cout;
using std::endl;

namespace A
{
    void f()
    {
        cout << "Called function f" << endl;
    }
}
```

Note the include style difference:

- `#include <iostream>` — angle brackets, for standard library / system
  headers. The compiler searches its standard include paths.
- `#include "f.h"` — quotes, for your own project headers. The compiler
  checks the local project directory first, then falls back to system
  paths if not found there.

## 5. Tying It Together: main.cpp

The file with `main` includes only the headers it actually needs — the
"interfaces" — not the `.cpp` files:

```cpp
// main.cpp
#include "f.h"
#include "g.h"

int main()
{
    A::f();
    A::g();
    return 0;
}
```

This compiles fine on its own, because `f.h`/`g.h` give the compiler
enough information (declarations) to validate the calls to `A::f()` and
`A::g()`.

## 6. Why You Still Need Every `.cpp` File at Link Time

Compilation happens in two conceptual stages:

1. **Compiling**: each `.cpp` file is compiled independently into an
   object file (`.o`/`.obj`). At this stage, the compiler is satisfied by
   _declarations_ alone (from headers) — it doesn't need to see other
   `.cpp` files.
2. **Linking**: the linker stitches all the object files together into one
   executable, resolving every function call to its actual definition
   somewhere in the object files it was given.

If you compile/link with only `main.cpp`:

```
g++ main.cpp -o main
```

the compiler succeeds (it has declarations from the headers), but the
**linker** fails with errors like:

```
undefined reference to `A::f()'
undefined reference to `A::g()'
```

This is because `main.cpp`'s object file _calls_ `A::f()` and `A::g()`,
but their actual bodies live in `f.cpp` and `g.cpp`, which were never
compiled or handed to the linker. The fix is to include every `.cpp` file
that contributes a needed definition:

```
g++ main.cpp f.cpp g.cpp -o main
```

Header files (`.h`) are **never** passed directly to the compiler on the
command line — they're pulled in automatically via `#include` when each
`.cpp` file is compiled.

## 7. Building in VS Code Without Typing Shell Commands

Instead of typing the `g++` command by hand every time, you can configure
`.vscode/tasks.json` to do it for you:

1. `Ctrl+Shift+P` → "Tasks: Configure Default Build Task" (creates
   `tasks.json` if it doesn't exist).
2. In the `"args"` array, replace the default `"${file}"` (which only
   builds the currently open file) with a list of every `.cpp` file in the
   project, e.g. `"main.cpp", "f.cpp", "g.cpp"`.
3. `Ctrl+Shift+B` builds using that task.
4. `F5` (Run and Debug) will build (if `launch.json`'s `preLaunchTask`
   points at your build task) and immediately run the resulting
   executable.

## 8. Summary Cheat Sheet

- `.h` file = **interface** (declarations only), wrapped in an include
  guard, wrapped in the relevant `namespace`.
- `.cpp` file = **implementation** (definitions), includes its own `.h`.
- `main.cpp` includes only the headers it needs, and calls functions
  either fully qualified (`A::f()`) or via a local `using` inside a block.
- Compiler needs declarations (headers) to check calls are valid.
- Linker needs definitions (every relevant `.cpp` file) to actually
  produce a working executable — this is why the build command must list
  _all_ contributing `.cpp` files, not just the one with `main`.
