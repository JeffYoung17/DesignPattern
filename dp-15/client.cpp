class ISubject{
public:
    virtual void process();
};


class RealSubject: public ISubject{
public:
    virtual void process(){
        //....
    }
};

class ClientApp{
    
    ISubject* subject;
    
public:
    
    ClientApp(){
      // 这里简化,实际上创建对象应该用工厂之类的模式
        subject=new RealSubject();
    }
    
    void DoTask(){
        //...
        subject->process();
        
        //....
    }
};