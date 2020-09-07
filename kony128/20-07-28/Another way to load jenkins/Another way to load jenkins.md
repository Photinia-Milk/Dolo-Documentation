# Another way to load jenkins

## 时间

06点38分

## 内容

我们用子域名不就解决之前nginx 无法简单代理proxy_pass到nginx的尴尬处境了吗！

![image-20200728063946989](Another%20way%20to%20load%20jenkins.assets/image-20200728063946989.png)

现在cloudflare上面申请一个A记录

嘿嘿





突然发现，之前申请证书没想到开jenkins子域名，只认证了www二级域名和顶级域名

我们还需要为子域名单独申请SSL证书，裂开了

https://www.youtube.com/watch?v=8huMBHx-TKY

![image-20200728063924262](Another%20way%20to%20load%20jenkins.assets/image-20200728063924262.png)

申请了个子域名解析



![image-20200728064101290](Another%20way%20to%20load%20jenkins.assets/image-20200728064101290.png)

ok

稍微搞点花活，开个server

![image-20200728064327211](Another%20way%20to%20load%20jenkins.assets/image-20200728064327211.png)



![image-20200728064339400](Another%20way%20to%20load%20jenkins.assets/image-20200728064339400.png)

注意80 server也要加个jenkins.dolo.club监听，嘿嘿



![image-20200728064425887](Another%20way%20to%20load%20jenkins.assets/image-20200728064425887.png)

子域名访问，成功！

