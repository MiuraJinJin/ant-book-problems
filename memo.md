### 初期化について
- C++ではグローバル変数の値は初期化されるがローカル変数はされない（不定になる）
  - グローバル変数のデフォルトの初期値
    - int: 0
    - char: ""
    - bool: false
- vectorの初期化について
  - vector<int> vec; // 要素3個のvectorになる
  - vector<int> vec(3); // [0, 0, 0]
  - vector<int> vec(3, 5); // [5, 5, 5]
  - vector<bool> vec(3); // [false, false, false]
- 二次元配列の初期化
  - long long array[2][3]; // 全ての要素が0で初期化される
  - fill((long long*) array, (long long*) (array + N), 1e18); // 全ての要素が1e18で初期化される

### その他
- vector::resize関数が使えそう
```
vector<int> vec(3); // [0, 0, 0]
vec.resize(5); // [0, 0, 0, 0, 0]
```
