# minitalk

![minitalk](https://github.com/yoshiddddd/minitalk/assets/83491254/7daa40ed-b2e4-44d3-8932-325d1af23a3b)  
42 Challenges  

## Overview
２つのプロセスを使用してシグナル通信を行います。

## Requirement
-MacOS  
-bash/zsh

## Usage
./serverを実行したのち、server側のPIDが表示されます。  
そのPIDをclient側のプロセスで./client `[PID]` `[send_msg]` という形で引数として渡し、実行します。  
client側で送信した[send_msg]がserver側で表示されます。  

## Features
client側ではkill関数を使用し、`SIGUSR1`,`SIGUSR2`シグナルを使用し、`[send_msg]`を1bitずつserver側に送信します。  
| シグナル名 | 対応bit |
|:---:|:---:|
| SIGUSR1 | 1 |
| SIGUSR2 | 0 |


server側ではclientから送られてきたシグナルに対してsigaction関数を使用して0か1かを判定し、8bit溜まり次第標準出力へ出力します。  
この一連の流れを繰り返します。  
`[send_msg]`はマルチバイトにも対応しており、unicodeにも対応しています。要するに日本語や絵文字なども送信可能です。

#### 以下の行為はエラーを返します
- client側でPIDをlong_max以上指定した時
- clientの引数が不足している又は過剰である時
- serverに引数を渡している時。
