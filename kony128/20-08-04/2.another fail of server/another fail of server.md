# another fail of server

## 时间

08点53分

## 内容

### master所有的服务又挂了

docker挂了

nginx挂了

不禁怀疑是不是被DDOS了

![image-20200804085354783](another%20fail%20of%20server.assets/image-20200804085354783.png)



### 先恢复docker服务

![image-20200804085405786](another%20fail%20of%20server.assets/image-20200804085405786.png)



sudo systemctl daemon-reload

sudo systemctl restart docker.service



### 恢复nginx

![image-20200804085548802](another%20fail%20of%20server.assets/image-20200804085548802.png)

挂了。。

![image-20200804085607782](another%20fail%20of%20server.assets/image-20200804085607782.png)



### Jenkins没挂

![image-20200804085634183](another%20fail%20of%20server.assets/image-20200804085634183.png)

怪了

### 启动前后端镜像

![image-20200804085749857](another%20fail%20of%20server.assets/image-20200804085749857.png)

镜像只是挂了，但还在ps里

![image-20200804085804681](another%20fail%20of%20server.assets/image-20200804085804681.png)

看来需要恢复启动才行

![image-20200804085828010](another%20fail%20of%20server.assets/image-20200804085828010.png)

十六分钟之前挂掉的？！

docker start dolo-back-end

docker start dolo-front-end

### 总结与查找原因

先看看cloudflare，看看流量状态

![image-20200804090042241](another%20fail%20of%20server.assets/image-20200804090042241.png)

今早居然有98个请求

![image-20200804090116540](another%20fail%20of%20server.assets/image-20200804090116540.png)

8月2日似乎被请求了大量流量

7月31日似乎是他们再做压测，请求多但流量不多

而前天似乎是有大量的静态资源请求

奇怪

先观察几天看看，再挂掉就明确说明有人恶意攻击，考虑换掉elastic IP或者在cloudflare上设立防火墙