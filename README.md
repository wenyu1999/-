这是操作系统实验之初识Linux的实验0
本实验的目的是帮助学员熟悉Linux下基本命令行使用、gcc编译器的使用等操作。
要求学员使用C语言进行代码实现下面的题目。
数据说明：
总共包括3个数据文件：customer.txt, lineitem.txt和orders.txt。分别行数为100，1000和4000，列和列之间使用|来分隔。所有文件均为文本文件。
每一个顾客在customer表中有一个唯一的顾客编号c_custkey，和对应的某个市场部门c_mkgsegment。每个顾客可能会有任意多个历史订单，每个订单在orders表中有一行，它有一个唯一的订单号o_orderkey和下单顾客编号o_custkey和一个下单时间c_orderdate。每个订单又由多件商品组成，每件商品在lineitem中有一行，记录了它所属的订单号l_orderkey、价格l_extendedprice及发货时间l_shipdate。
目标是找出每个订单延迟发货的商品的总销售额，以供销售方有针对性地分析优化。如下图所示，我们将该问题抽象为以下的一个计算问题：每张表看作一个multi-set，对customer、orders和lineitem三张表建立笛卡尔集合，得到一个mnl行的一个集合（其中m,n,l分别是三张表的行数），然后对该集合按以下条件做过滤：
c_mktsegment = ？ and c_custkey=o_custkey and o_orderkey=l_orderkey and o_orderdate < ? and l_shipdate > ? ：其中？是动态变参
对满足过滤条件的结果，按照l_orderkey列的值进行分组，并对l_orderkey相同的记录的l_extendedprice做求和，最后结果按照l_extendedprice求和值排序，并返回topn的结果，其中topn值也是动态变参。
提交要求：
需要提供5个文件（夹）
Readme.txt：编译和运行方式
Compile.sh：编译脚本
Run.sh: 执行脚本
Sourcecode 文件夹：包括所有source code和配置文件
可执行文件：可执行文件

程序执行方式：
选手需要提前将3个数据文件放到run.sh 相同目录，提交的程序将会以如下格式的命令运行、进行评测。
./run.sh customer.txt orders.txt lineitem.txt n n4个参数
