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

## SQLite CLI usage

Use `.load` command:

```
sqlite> .load dist/sqlite3-stats.so;
```

Then use library functions:

```sql
with tbl as (
    select value from generate_series(1, 99, 1)
)

select 'count' as metric, count(value) as value
from tbl
union all

select 'median' as metric, median(value)
from tbl
union all

select 'percentile_25' as metric, percentile_25(value)
from tbl
union all

select 'percentile_75' as metric, percentile_75(value)
from tbl
union all

select 'percentile_90' as metric, percentile_90(value)
from tbl
union all

select 'percentile_95' as metric, percentile_95(value)
from tbl;
```

```
┌───────────────┬───────┐
│    metric     │ value │
├───────────────┼───────┤
│ count         │ 99    │
│ median        │ 50    │
│ percentile_25 │ 25    │
│ percentile_75 │ 75    │
│ percentile_90 │ 90    │
│ percentile_95 │ 95    │
└───────────────┴───────┘
```

## In-app usage

In your application, call `sqlite3_enable_load_extension(db, 1)`
to allow loading external libraries. Then load the library
using `sqlite3_load_extension()`, the third argument should be 0.
See <https://sqlite.org/loadext.html> for details.

Select statements may now use stat functions, as in
`SELECT median(val) FROM table;`

## Building from source

Linux:

```
gcc -fPIC -lm -shared src/stats.c -o dist/sqlite3-stats.so
```

Mac OS X:

```
gcc -fno-common -dynamiclib src/stats.c -o dist/sqlite3-stats.dylib
```

Windows:

```
gcc -shared -I ./src src/stats.c -o dist/sqlite3-stats.dll
```
