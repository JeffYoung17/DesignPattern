/**
 * 工厂模式和原型模式的区分在于:工厂方法模式通过简单的步骤就可以创建对象
 * 而原型模式需要考虑一个复杂对象的中间状态并进行保留
 */
//抽象类
class ISplitter{
public:
    virtual void split()=0;
    virtual ISplitter* clone()=0; //通过克隆自己来创建对象
    
    virtual ~ISplitter(){}

};

/**
// 相当于把工厂基类的创建对象的抽象接口放到product的类体里面,变成clone
class SplitterFactory{
public:
    virtual ISplitter* CreateSplitter()=0;
    virtual ~SplitterFactory(){}
};
*/
