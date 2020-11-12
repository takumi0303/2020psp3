# 課題2 レポート
学籍番号　35319012 氏名　大木拓海


## 課題
長崎県にある市町村別人口データを読み込み、リスト構造にするプログラムを作成する。

1. 使用するデータ  
長崎県の人口データは、nagasaki.csvに保存されている。
nagasaki.csvには、csv形式で以下のデータが含まれる
- ID
- 県名
- 市町村名
- 人口
- 男性人口
- 女性人口

長崎県の市町村別人口データは、下記に構造体に読み込まれる。
```
typedef struct {
    int id;
    char pref[13];  // UTF-8対応
    char name[19];  // UTF-8対応
    int population;
    int m_population;
    int f_population;
} City;
```

英語版のデータを用意しました。名称は、nagasaki2.csvです。チャレンジ問題2で、一致する文字列が見つからない場合、こちらを利用してください。その場合、main関数内にあるfopenの引数を下記のように変更してください。
```    
fp = fopen("nagasaki2.csv","r");
```


1. 必須問題：実装する関数  
(1) InsertNewNode：必要なメモリを確保し、リストの先頭に新しいデータを挿入する。  
    [入力]
    - City newCity: リストに挿入する市町村のデータ
    - Node* pNext: リストの先頭アドレス  

    [出力]  
    - return値: (リストの先頭に新しいデータを挿入した後の)リストの先頭アドレス

    (2) SearchCityByID: IDをキーとし、リストを検索する。  
    [入力]  
    - Node* pList: リストの先頭アドレス
    - int ID: 検索する市町村のID 
    
    [出力]  
    - return値: IDが合致した場所(先頭を0とする)。IDが一致するデータがない場合は-1。  
    - City* pCity: IDが合致した市町村のデータを入れる

3. 補助関数  
以下の関数はすでに実装されており、利用することができる。  
- PrintCity: 市町村データを出力する
- ReleaseList: リストで確保したメモリを解放する
- PrintList: リストの内容を出力する。

4. チャレンジ問題  
(1) DeleteNodeAt: 任意のノードをリストから削除する(10点)  
CHALLENGE2を有効にしてください。  
    [入力]  
    - Node** ppNode: リストの先頭を指すポインタ変数のアドレス(ポインタのポインタ)  
    - int cn: ノードの位置(先頭のノードを0とする)  
    [出力]  
    - return値: 削除に成功したらSUCCESS、失敗したらERRR  

    (2) SearchCityByName: 市町村を名称で検索する(5点)  
    CHALLENGE1を有効にしてください。  
    [入力]
    - Node* pList: リストの先頭アドレス
    - char* cityName: 検索する市町村の名称

    [出力]  
    - return値: cityNameが合致した場所(先頭を0とする)。cityNameが一致するデータがない場合は-1。
    - City* pCity: IDが合致した市町村のデータを入れる

## ソースコードの説明
78 Nodeの先頭であるpNodeを確保する
79 pNodeのを分けたうちのdataにnewCityのデータを代入する
81 topにpNodeを代入し、returnさせる
108 pNodeにpListを代入する
110 IDとpNodeが一致するまで比較し、その工程の回数を記録する


## 出力結果

```
42411, NagasakiKen, ShinKamigoto, 19718, 9197, 10521
42391, NagasakiKen, Sasa, 13626, 6426, 7200
42383, NagasakiKen, Ojika, 2560, 1172, 1388
42323, NagasakiKen, Hasami, 14891, 7079, 7812
42322, NagasakiKen, Kawatana, 14067, 6656, 7411
42321, NagasakiKen, HigashiSonogi, 8298, 3886, 4412
42308, NagasakiKen, Togitsu, 29804, 14326, 15478
42307, NagasakiKen, Nagayo, 42548, 20090, 22458
42214, NagasakiKen, MinamiShimabara, 46535, 21574, 24961
42213, NagasakiKen, Unzen, 44115, 20847, 23268
42212, NagasakiKen, Saikai, 28691, 14032, 14659
42211, NagasakiKen, Goto, 37327, 17339, 19988
42210, NagasakiKen, Iki, 27103, 12860, 14243
42209, NagasakiKen, Tsushima, 31457, 15361, 16096
42208, NagasakiKen, Matsuura, 23309, 11164, 12145
42207, NagasakiKen, Hirado, 31920, 14874, 17046
42205, NagasakiKen, Omura, 92757, 43938, 48819
42204, NagasakiKen, Isahaya, 138078, 65029, 73049
42203, NagasakiKen, Shimabara, 45436, 20999, 24437
42202, NagasakiKen, Sasebo, 255439, 120198, 135241
42201, NagasakiKen, Nagasaki, 429508, 198716, 230792
print list. items = 21
===== Print End =====
City ID?42209
the city was found at 13
42209, NagasakiKen, Tsushima, 31457, 15361, 16096
free list. items = 21

```

## 修正履歴

