题目1：三种算法的同步演示

 需求：

  1、基于下图构造图；

  2、分别使用深度优先遍历(DFS)、Prim、Dijkstra算法从任意用户输入的节点开始对图进行遍历、求MST及最短路径；

  3、三个算法同时动态显示构造过程（非节点动态打印）；

  4、每一步都要求显示/打印所有试探的路径(见下一张ppt)；

  5、不能把算法一次运行完并记录中间过程，然后基于中间变量画图。
![image](https://user-images.githubusercontent.com/71956094/145662742-a2b9c6b6-160e-4051-8f2d-d299f8f40551.png)


没有实现A*算法，只实现了prim，dfs，dijkstra三个

主要是还实现了一个能够在算法中途暂停的功能以及三种算法同步演示的功能。
