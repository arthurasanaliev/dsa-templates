# Number Theory Notes

## The number of factors of an integer
- For n <= $10^4$, max f(n) <= 64
- For n <= $10^5$, max f(n) <= 128
- For n <= $10^6$, max f(n) <= 240
- For n <= $10^7$, max f(n) <= 448

## Don't use pow()
Avoid `pow()` because it uses floating-point approximations that can cause off-by-one errors.

## Set precision
Set precision before outputting floating-point values.
```cpp
cout << fixed << setprecision(4);

for (int i = (int)a.size() - 1; i >= 0; i--) {
    long double x = sqrtl(a[i]);
    cout << x << '\n';
}
```
