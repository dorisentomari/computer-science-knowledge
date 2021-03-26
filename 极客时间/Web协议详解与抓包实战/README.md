# 1. 课程模块

以 TCP/IP 协议栈为依托，从上至下，从应用层至基础设施介绍协议

## 1.1 应用层
+ 第 1 部分: HTTP/1.1
+ 第 2 部分: WebSocket
+ 第 3 部分: HTTP/2.0

## 1.2 应用层的安全基础设施
+ 第 4 部分: TCP/SSL

## 1.3 传输层
+ 第 5 部分: TCP

## 1.4 网络层及数据链路层
+ 第 6 部分: IP 层和以太网

# 2. 主要涉及工具
+ Chrome 浏览器 Network 面板
+ WireShark
+ tcpdump

# 3. 课程安排

## 3.1 自顶向下、由业务到逻辑
+ HTTP/1 协议为什么会如此设计
  + 网络分层原理，REST 架构
+ 协议的通用规则
  + 协议格式、URI、方法与响应码概览
+ 连接与消息的路由
+ 内容协商与传输
+ cookie 的设计与问题
+ 缓存的控制

## 3.2 HTTP/1 的协议升级
+ 支持服务器推送消息的 WebSocket 协议
  + 建立会话
  + 消息传输
  + 心跳
  + 关闭会话
+ 全面优化后的 HTTP/2.0 协议
+ HTTP/2.0 必须开启的 TLS/SSL 协议

## 3.3 TCP/IP 协议
+ 传输层的 TCP 协议
  + 建立连接
  + 传输数据
  + 拥塞控制
  + 关闭连接
+ 网络层的 IP 协议
  + IP 报文与路由
  + 网络层其他常用协议: ICMP、ARP、RARP
  + IPv6 的区别

# 扩展学习资料
+ [WebSocket 协议深入探究](https://www.infoq.cn/article/deep-in-websocket-protocol)
+ [TCP/IP协议基础](https://akaedu.github.io/book/ch36s02.html)
