## WINTAB32Safe
WINTAB32.dllのラッパーdll (32ビット版のみ)

## アップデートログ
2016/10/09 AzPainter2/AzDrawing2のバグ対策追加

## 効能
 - PTB-STRP1＋Flashが時々強制終了するバグを抑える。
 - AzPainter2/AzDrawing2のバグ対策（WINTAB32のlcOutExtXとlcInExtXが違うタブレット（Huionなど）で何も描けないバグ）

#### 各種原因
 - FlashがWTPacketsPeek (WINTAB32.dll) のhCtxをNULLのまま呼び出すバグ
 - PTB-STRP1のWINTAB32.dllがhCtxのNULLチェックをしていないバグ。hCtxがNULLのまま呼び出すとアプリごと強制終了

## 対策詳細
 - WTPacketsPeekのhCtxをNULLのまま呼び出された場合、このラッパーdllから即エラーを返す(処理したパケット0)
 - AzPainter2/AzDrawing2からWTOpenAが呼び出された場合、lcOutExtX(Y)=lcInExtX(Y);

## 使い方

#### 32ビット版Windowsを使っている人
 - C:\Windows\System32フォルダを開く

#### 64ビット版Windowsを使っている人
 - C:\Windows\SysWow64フォルダを開く

#### ここから共通
 - WINTAB32.dllをWINTAB32_.dllに名前変更
 - ダウンロードしたWINTAB32.dllをコピペ

#### アンインストール方法 / インストールに失敗した場合の復旧方法
 - タブレットのドライバを再インストール
