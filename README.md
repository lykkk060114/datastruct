[TOC]

# 数据结构

## 食用方法
- 单击右边绿色框“code”
- 下载代码（推荐git clone $(ssh)，直接下载压缩包也行）
Linux:
- 在build中

  ```cmake
  cmake ..
  make
  ```

- 在主目录中

  ```
  cmake -B build -S src //反正可执行文件在build，不如直接进入build再cmake
  ```
windows:
 今天在windows发现编译真的变得麻烦了，还得更改powershell到UTF-8,麻烦
 
 不过还是说一下编译方法：
 	得有MinGW这个编译器（带有gcc)
 	powershell执行 gcc $(文件的相对目录/绝对目录 ) -o $(文件的输出目录)
 	运行： ./$(exe文件名)	tab补全
 	当然cmake可以使用的话还是推荐cmake，无风险一键安装
  

