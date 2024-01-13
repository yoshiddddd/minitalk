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
そのPIDをclient側のプロセスで./client [PID] [send_msg] という形で引数として渡し、実行します。  
client側で送信した[send_msg]がserver側で表示されます。  

## Features
