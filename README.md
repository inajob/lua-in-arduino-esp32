# lua in arduino-esp32

arduino-esp32環境でLuaを実行するデモです。
platformioを使うことを前提にしています。

## submodule更新

```
$ git submodule update --init --recursive
```

## ビルド

```
$ platformio run
```

## ビルド+書き込み

```
$ platformio run --target="upload"
```
