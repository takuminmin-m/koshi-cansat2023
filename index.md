# 高校生のためのCanSat開発キット
CanSat for High School Students  
高校生のためのCanSat開発キット

## 概要
+ 高校生向け缶サット開発キット
+ Arduino Nanoを想定

<img src="./Structure/overview_in_bottle.jpg" width="30%"> <img src="./Structure/overview.jpg" width="30%">
<img src="./Structure/board_side.jpg" width="50%">

本資料の活用については制限しておりませんが，その際には以下までご一報いただければ幸いです．
+ melting.rabbit.mr[at]gmail.com


## 搭載機器
機器の詳細な型番などは[パーツリスト](./Structure/PartsList)を参照のこと．

### センサ
+ GPS
+ 9軸センサ
+ 高度計（気圧計）
+ 光センサ
+ カメラ

### アクチュエータ
+ サーボモータ

### ストレージ
+ SDカード


## 資料一覧
+ `./Arduino` ：サンプルコードとその設定など
	- 機器のテストコード（動作試験）
		* [GPSの単体テスト](./Arduino/Test_GPS)
		* [9軸センサの単体テスト](./Arduino/Test_IMU)
		* [高度計（気圧計）の単体テスト](./Arduino/Test_Barometer)
		* [光センサの単体テスト](./Arduino/Test_Light)
		* [カメラの単体テスト](./Arduino/Test_Camera)
		* [サーボモータの単体テスト](./Arduino/Test_Servo)
		* [SDカードの単体テスト](./Arduino/Test_SD)
		* [XBee（無線通信機）の単体テスト](./Arduino/Test_XBee)
	- 機器のテストコード（複数使用）
		* [全機器の統合状態のテスト](./Arduino/Test)
		* [光センサを４並列にした光方向センサ](./Arduino/Test_Light4)
		* [サーボモータの２並列版](./Arduino/Test_Servo2)
	- プログラミング講習
		* [00. 事前準備](./Arduino/ProgrammingTutorial00_Preparation)
		* [01. HelloWorld](./Arduino/ProgrammingTutorial01_HelloWorld)
		* [02. Variable](./Arduino/ProgrammingTutorial02_Variable)
		* [03. Operator](./Arduino/ProgrammingTutorial03_Operator)
		* [04. If Else](./Arduino/ProgrammingTutorial04_IfElse)
		* [05. Loop](./Arduino/ProgrammingTutorial05_Loop)
		* [06. Function](./Arduino/ProgrammingTutorial06_Function)
		* [07. Device1](./Arduino/ProgrammingTutorial07_Device1)
		* [08. Device2](./Arduino/ProgrammingTutorial08_Device2)
		* [09. Application](./Arduino/ProgrammingTutorial09_Application)
	- 実装例
		* [明るさ計](./Arduino/App_LightMeter)
+ `./Schematic` ：[回路図](./Schematic)
+ `./Structure` ：[構造など](./Structure)
	- [パーツリスト](./Structure/PartsList)
	- [ユニ基板詳細](./Structure/board)
	- [電源スイッチ](./Structure/switch)
	- [テスタ](./Structure/tester)
+ `./Archives` ：アーカイブ
	- [2020年02月22～23日 缶サットHigh School 「缶サット電子系講座」](./Archives/2020-02-22_Fukui)

## ブログ
+ [【CanSat】缶サット甲子園を目指す高校生向け電子工作講座 @福井 [2020/02/23]](https://meltingrabbit.com/blog/article/2020022301/)