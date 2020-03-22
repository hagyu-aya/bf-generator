# bf-generator

## 概要

簡単な記法で書かれたコードをbrainfuckのコードに変換します。

## 記法

### 数字

数字を書くと、その直前の文字が書かれた数のぶんだけ繰り返されます。例えば、```+10```は```++++++++++```に変換されます。brainfuckの命令セットでないものでも繰り返されます。

### \による文字コードの挿入

\\(文字)と書くと、その文字の文字コードが挿入されます。挿入された文字コードは、先程の数字の変換によって更に変換されます。例えば、```+\A```は```+65```に変換され、最終的に```+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++```(+が65個)に変換されます。  
この変換は、上記の数字の変換より常に先に行われます。例えば、```+\2```は```+50```と変換されます。```+\\```とは変換されません。

## サンプルコード

```
+\H.>+\e.>+\l..>+\o.>+\,.>+\ .>+\w.<3.>4+\r.>+\l.>+\d.>+\..
```

実行結果

```
Hello, world.
```