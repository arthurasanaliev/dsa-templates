# String Notes

## Reading tokens until EOF
`cin >> s` skips any spaces and line breaks.
```cpp
string s;
while (cin >> s) a.push_back(stoll(s));
```

## Reading lines until EOF
`getline` returns false only at true end-of-input; empty lines are fine.
```cpp
string s;
while (getline(cin, s)) { /* parse s */ }
```

## Mixing cin >> with getline
`cin >> x` leaves `\n` in the buffer — the next `getline` reads an empty string. Skip it first:
```cpp
cin >> n;
cin.ignore();
getline(cin, s);
```
