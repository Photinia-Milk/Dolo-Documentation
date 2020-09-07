# Invalid .gitignore

## 内容

发现.gitignore不起作用

原来是已经托管到git中的，就会忽视.gitignore规则

服了

https://www.cnblogs.com/sloong/p/5523244.html

![image-20200729044740423](Invalid%20.gitignore.assets/image-20200729044740423.png)



git rm -r --cached . 

git add . 

git commit -m 'update .gitignore'

我就说怎么application.properties老是被改

明天给他们说一声