### 初期化について
- C++ではグローバル変数の値は初期化されるがローカル変数はされない（不定になる）
  - グローバル変数のデフォルトの初期値
    - int: 0
    - char: '\0'
    - bool: false
- vectorの初期化について
  - vector<int> vec; // 要素0個のvectorになる
  - vector<int> vec(3); // [0, 0, 0]
  - vector<int> vec(3, 5); // [5, 5, 5]
  - vector<bool> vec(3); // [false, false, false]
- 二次元配列の初期化
  - long long array[2][3]; // 全ての要素が0で初期化される
  - fill((long long*) array, (long long*) (array + N), 1e18); // 全ての要素が1e18で埋められる
    - fill((long long*) array, (long long*) array + N, 1e18); // これはNG(array + Nにかっこは必要)
- 最大値の取得
  - *max_element(begin(array), end(array))
  - *max_element(vec.begin(), vec.end())

### その他
- vector::resize関数が使えそう
```
vector<int> vec(3); // [0, 0, 0]
vec.resize(5); // [0, 0, 0, 0, 0]
```
- sort関数の第3引数の関数は引数a,bの「デフォルトはa<bとなるけどそれをどうずらすか」というイメージ
- dequeのインデックスアクセスは遅くない(vectorと同一と考えて良い)
- ポインタは*pointer = value;で代入が可能
  - lower_boundの戻り値はポインタを返す
- lower_boundは同一の値が続く場合一番左の位置のポインタを返す
  - A = { 1, 2, 2, 3 }; で2を検索する場合A[1]が返る
- map::contains(x)ですでにxがキーの値が格納されているかをチェックできる