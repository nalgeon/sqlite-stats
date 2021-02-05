# SQLite statistical functions

This library provides common statistical functions for SQLite.
Adapted from [extension-functions.c](https://sqlite.org/contrib/) by Liam Healy.

Provides following functions:

-   `stddev`,
-   `variance`,
-   `mode`,
-   `median`,
-   `percentile_25`,
-   `percentile_75`,
-   `percentile_90`,
-   `percentile_95`,
-   `percentile_99`.

## Building from source

Linux:

```
gcc -fPIC -lm -shared src/stats.c -o dist/sqlite3-stats-linux.so
```

Mac OS X:

```
gcc -fno-common -dynamiclib src/stats.c -o dist/sqlite3-stats-osx.dylib
```

Windows:

```
gcc -shared -I ./src src/stats.c -o dist/sqlite3-stats-win32.so
```

## SQLite CLI usage

Use `.load` command:

```
sqlite> .load dist/sqlite3-stats.so;
sqlite> SELECT median(val) FROM table;
```

## In-app usage

In your application, call `sqlite3_enable_load_extension(db, 1)`
to allow loading external libraries. Then load the library
using `sqlite3_load_extension()`, the third argument should be 0.
See <https://sqlite.org/loadext.html> for details.

Select statements may now use stat functions, as in
`SELECT median(val) FROM table;`
