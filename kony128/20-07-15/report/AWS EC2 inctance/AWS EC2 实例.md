# AWS EC2 实例

## 时间

09点25分

## 负责

kony

## 内容

### EC2 的集群、分区、分布的群组策略

https://docs.aws.amazon.com/zh_cn/AWSEC2/latest/UserGuide/placement-groups.html



![image-20200715101233894](AWS%20EC2%20%E5%AE%9E%E4%BE%8B.assets/image-20200715101233894.png)

使用T2/T3可以增加性能（要收费

### 可突增性能实例的无限模式

https://docs.aws.amazon.com/zh_cn/AWSEC2/latest/UserGuide/burstable-performance-instances-unlimited-mode.html?icmpid=docs_ec2_console

### 使用SSH密钥登陆

### 如何使用XShell登录亚马逊EC2云服务器

https://jingyan.baidu.com/article/a3a3f811d5fc338da2eb8a00.html

### Linux 实例的 Amazon EC2 安全组

https://docs.aws.amazon.com/zh_cn/AWSEC2/latest/UserGuide/ec2-security-groups.html

### 【AWS】如何彻底清除EC2实例

https://www.jianshu.com/p/e0647967b10d

### 在更改 EC2 Linux 实例的实例类型之前，我需要采取哪些步骤？

https://aws.amazon.com/cn/premiumsupport/knowledge-center/resize-instance/

### EC2增加 CPU 或内存资源

https://docs.github.com/cn/enterprise/2.17/admin/installation/increasing-cpu-or-memory-resources

## 连接方法

![image-20200715105912801](AWS%20EC2%20%E5%AE%9E%E4%BE%8B.assets/image-20200715105912801.png)

拿到pem（很重要，一定需要）

![image-20200715105941830](AWS%20EC2%20%E5%AE%9E%E4%BE%8B.assets/image-20200715105941830.png)

配置好主机和端口号

![image-20200715110010623](AWS%20EC2%20%E5%AE%9E%E4%BE%8B.assets/image-20200715110010623.png)

如果是ubuntu系统，一般用户名就是ubutnu

方法记得选择Public Key

用户密钥就选择刚才下载下来的.pem文件