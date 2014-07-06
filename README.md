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

使い方 (spec4) 
------
以下のコマンドで実行できます。
```
$ git clone https://github.com/amiq11/amiq11-sezemi-2014-readable-code-2.git
$ cd amiq11-sezemi-2014-readable-code-2
$ gcc -std=gnu99 -o recipe.bin recipe.c
$ ./recipe.bin recipe_sample.txt
```

レシピファイルはテキスト形式で、一行に一つのレシピを記述してください。  
今回はその全てのレシピ、及び一意に振られたIDが表示されます。
IDは、先に記述されたものから順に0から連番で振られます。

メモはmemo.mdにspecごとに記述しています。
