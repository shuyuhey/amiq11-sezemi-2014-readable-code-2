amiq11-sezemi-2014-readable-code-2
==================================

「SEゼミ2014 リーダブルコード勉強会」（2014/07/06）のためのリポジトリ

開発言語
--------
```
    CCCCCC
  CCC    CCC
 CCC
 CCC      
  CCC    CCC
    CCCCCC
```

使い方 (spec3) 
------
以下のコマンドで実行できます。
```
$ git clone https://github.com/amiq11/amiq11-sezemi-2014-readable-code-2.git
$ cd amiq11-sezemi-2014-readable-code-2
$ gcc -o recipe.bin recipe.c -std=gnu99
$ ./recipe.bin recipe_sample.txt
```

レシピファイルはテキスト形式で、一行に一つのレシピを記述してください。  
今回はそのうちの一番先頭に記述したレシピのみが表示されます。

メモはmemo.mdにspecごとに記述しています。
