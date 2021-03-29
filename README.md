# DesignPattern

设计模式: 在变化和稳定中间寻找隔离点,分离它们,来管理变化

- 稳定是相对的,就如同没有绝对的静止
- 使变化带来的结果是扩展(复用),而不是更改

## Menu

组件协作模式:通过晚绑定,实现框架和应用程序之间的松耦合
|  组件协作模式    |  定义   |  特点    |
| :-: | :-: | :-: |
|模板方法:dp-03|定义一个操作中的算法骨架(稳定的),而将一些步骤(变化的)延迟到子类中|稳定框架流程中带有变化的子步骤|
|策略模式:dp-04|定义一系列算法并进行封装,使它们可以互相替换(变化的),使得算法可以独立于使用它的客户程序(稳定的)而进行扩展和变化|用继承来消除容易变化的条件判断|
|观察者模式:dp-05|定义对象间的一对多的依赖关系,当一个对象(subject)的状态发生改变,所有依赖它的对象(观察者)都能得到通知并自动更新|一对多|

单一职责模式:
|  单一职责模式    |  定义   |  特点    |
| :-: | :-: | :-: |
|装饰模式:dp-06|通过**组合的方式**给一个对象增加一些额外的职责,而**不是过度使用继承**来扩展对象的功能,避免了代码的过度冗余和子类的膨胀|装饰类在接口上表现为继承,在实现上表现为组合|
|桥模式:dp-07|通过**组合的方式**,将抽象部分(业务功能)和实现部分(平台实现)两种维度的变化进行分离|在抽象基类中放平台实现的抽象类指针|


"对象创建"模式:
|  "对象创建"模式    |  定义   |  特点    |
| :-: | :-: | :-: |
|工厂方法模式:dp-08|定义创建对象的接口,使得一个类的实例化延迟到子类(手段:虚函数;目的:解耦)|子类的对象创建方法要求相同(比如都通过默认构造)|
|抽象(家族)工厂模式:dp-09|定义接口,负责创建一系列相互依赖或作用的对象|应对"新系列"的需求变动,难以应对"新对象"的变动|
|原型模式:dp-10|使用原型的实例指定创建对象的种类,然后通过拷贝的方法创建新的对象|工厂方法模式通过简单的步骤就可以创建对象,而原型模式需要考虑一个复杂对象的中间状态并进行保留|
|构建器模式:dp-11|将一个对象的创建和它的表示相分离,使得同样的构建过程(稳定的)可以创建不同的表示(变化的)|x|

"对象性能"模式:
|  "对象性能"模式    |  定义   |  特点    |
| :-: | :-: | :-: |
|单例模式:dp-12|保证一个类仅有一个实例,并提供一个该实例的全局访问点|x|
|享元模式:dp-13|运用共享技术有效地支持大量细粒度的对象|x|

接口隔离模式:
|  接口隔离模式    |  定义   |  特点    |
| :-: | :-: | :-: |
|Facade门面模式|x|x|
|Proxy代理模式:dp-15|x|x|
|Adapter适配器模式:dp-16|x|x|
|Mediator中介模式|x|x|

"状态变化"模式
|  "状态变化"模式    |  定义   |  特点    |
| :-: | :-: | :-: |
|状态模式:dp-18|x|x|
|备忘录模式:dp-19|x|x|

"数据结构"模式
|  "状态变化"模式    |  定义   |  特点    |
| :-: | :-: | :-: |
|组合模式:dp-20|x|x|

## Reference
[C++设计模式](https://www.bilibili.com/video/BV1kW411P7KS?p=3)