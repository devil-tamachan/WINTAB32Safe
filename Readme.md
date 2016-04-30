## WINTAB32Safe
WINTAB32.dllのラッパーdll (32ビット版のみ)

## 目的
PTB-STRP1＋Flashが時々強制終了するバグを抑える。
原因は
 - FlashがWTPacketsPeek (WINTAB32.dll) のhCtxをNULLのまま呼び出すバグ
 - PTB-STRP1のWINTAB32.dllがhCtxのNULLチェックをしていないバグ。hCtxがNULLのまま呼び出すとアプリごと強制終了

## 効能
WTPacketsPeekのhCtxがNULLの場合、このラッパーdllから即エラーを返す(処理したパケット0)

## 使い方

#### 32ビット版Windowsを使っている人
 - C:\Windows\System32に移動

#### 64ビット版Windowsを使っている人
 - C:\Windows\SysWow64に移動

#### ここから共通
 - WINTAB32.dllをWINTAB32_.dllに名前変更
 - ダウンロードしたWINTAB32.dllをコピペ

#### アンインストール方法
 - タブレットのドライバを再インストール
