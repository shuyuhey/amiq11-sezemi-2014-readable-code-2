# 見つけたコード BLThunder1991

## 1つ目
### コード
https://github.com/amiq11/amiq11-sezemi-2014-readable-code-2/blob/master/recipe.c#L111 - 113

```C
    const char *recipe_path = argv[1];
    recipe_list_t *recipe_list = read_recipe_from_file(recipe_path);
    print_recipes(recipe_list);
```

### いいところ
* main関数の中に、最低限の呼び出ししか置いていないことが良い。全体を通して、何をやりたいかが明確にわかる。

### 見つけたきっかけ
* 全体の処理の流れを見るために、main関数を参照した。

## 2つ目
### コード
https://github.com/amiq11/amiq11-sezemi-2014-readable-code-2/blob/master/recipe.c#L76 - 77

```C
    FILE *fp = fopen(path, "r");
    if (fp == NULL) { perror("fopen"); exit(EXIT_FAILURE); }
```

### いいところ
* 僕だったら、``if (( fp = fopen ( path, "r")) == NULL)`` と書いてしまうと思うけど、ポインタの生成ロジックと成否判定ロジックは別の処理なので、一行ずつ分けるほうがわかりやすいと思った。

### 見つけたきっかけ
* 実装前のコードリーディング

## 3つ目
### コード
https://github.com/amiq11/amiq11-sezemi-2014-readable-code-2/blob/master/recipe.c#L107
```C
    print_usage(argv[0]);
```

### いいところ
どんなふうにコンパイルしても、自分が生成したバイナリでUsageを表示するのがわかりやすくて良い。

### 見つけたきっかけ
* 実装前のコードリーティング

## 4つ目
### コード
https://github.com/BLThunder1991/amiq11-sezemi-2014-readable-code-2/blob/master/recipe.h#L5

```C
    typedef struct _recipe
    {
        recipe_id_t id;
        char *name;
    } recipe_t;
```

### いいところ
* レシピがどんな情報を持っているかすぐわかる。
* 新しい情報を追加しやすい

### 見つけたきっかけ
* 仕様7を実装するとき
    * URLの追加を行う際に、どこに追加すればよいかすぐ思いついた。

## つ目
### コード

### いいところ

### 見つけたきっかけ
