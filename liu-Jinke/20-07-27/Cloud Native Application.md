# Cloud Native Application

### 设计理念

***Resiliency***

***Agility***

***Operability***

***Observability***

### Health reporting

##### 断路器

能够当一个服务挂掉时返回给其他服务断路信息，防止整个系统服务挂掉。

比如存在A->B->C,在B和C之间有断路器，如果C挂掉，当B向C发送请求的时候，断路器会直接返回给B断路信息，，然后一层层向上层传递。

##### SLO

### API First

API First or Rest First

### Dependency Management

Docker Container:最常用的镜像虚拟机

PrivateContainer

Light VM

Kata Container：重量级的，融合container和VM特性的虚拟机

### Design，Build，Release，Run

### Configuration，Credentials，Code

### Logs

需要在合适的地方打上log，用log监控业务进展，因为测试用例不可能覆盖所有的意外情况，需要log记录之前的实现。

##### ELK

ELK是Elasticsearch、Logstash、Kibana三大开源框架首字母大写简称，其中Elasticsearch是一个基于Lucene、分布式、通过Restful方式进行交互的近实时搜索平台框架。像类似百度、谷歌这种大数据全文搜索引擎的场景都可以使用Elasticsearch作为底层支持框架，可见Elasticsearch提供的搜索能力确实强大,市面上很多时候我们简称Elasticsearch为es。Logstash是ELK的中央数据流引擎，用于从不同目标（文件/数据存储/MQ）收集的不同格式数据，经过过滤后支持输出到不同目的地（文件/MQ/redis/elasticsearch/kafka等）。Kibana可以将elasticsearch的数据通过友好的页面展示出来，提供实时分析的功能。

Logs are not metrics

### Disposability

当APP流量达到一个阈值后，我们需要启动其他服务帮忙分流，但是如果服务启动过慢，开始时承担流量的服务可能已经承受不住流量压力，所以需要App尽可能的快速启动，但是对于Java项目，外部的container快速启动之后，内部的Tomcat还没有启动，就算Tomcat提前启动，Java代码也是冷启动的，没有服务进来的时候Java项目仍然不在缓存中。

阿里的大型购物节之前，会先用测试数据对服务器进行“热身”，先让Java代码进入到缓存中，然后当购物节开始时服务器已经开始提供服务。

