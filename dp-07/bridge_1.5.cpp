class Messager{
public:
    virtual void Login(string username, string password)=0;
    virtual void SendMessage(string message)=0;
    virtual void SendPicture(Image image)=0;

    virtual void PlaySound()=0;
    virtual void DrawShape()=0;
    virtual void WriteText()=0;
    virtual void Connect()=0;
    
    virtual ~Messager(){}
};

//平台实现
class PCMessagerBase : public Messager{
public:
    virtual void PlaySound(){
        //**********
    }
    virtual void DrawShape(){
        //**********
    }
    virtual void WriteText(){
        //**********
    }
    virtual void Connect(){
        //**********
    }
};

class MobileMessagerBase : public Messager{
public:
    virtual void PlaySound(){
        //==========
    }
    virtual void DrawShape(){
        //==========
    }
    virtual void WriteText(){
        //==========
    }
    virtual void Connect(){
        //==========
    }
};

class MessagerLite : public Messager {

};

// Opt3: PCMessagerLite/MobileMessagerLite经过Opt1/2以后类体相同

//业务抽象
class PCMessagerLite { // Opt1: public PCMessagerBase {
    // Opt2: PCMessagerBase* messager;
    Messager* messager; // = new PCMessagerBase();
    // 但是new PCMessagerBase()不成立,
    // 因为这个基类只override了部分的虚函数,它还是抽象类,不能实例化!!!
public:
    virtual void Login(string username, string password){
        // Opt1: PCMessagerBase::Connect();
        messager->Connect();
        //........
    }
    virtual void SendMessage(string message){
        // PCMessagerBase::WriteText();
        messager->WriteText();
        //........
    }
    virtual void SendPicture(Image image){
        // PCMessagerBase::DrawShape();
        messager->DrawShape();
        //........
    }
};

// 移动端简化版
class MobileMessagerLite {// Opt1: public MobileMessagerBase {
    // MobileMessagerBase* messager;
    Messager* messager; // = new MobileMessagerBase();
public:
    
    virtual void Login(string username, string password){
        
        // Opt1: MobileMessagerBase::Connect();
        messager->Connect();
        //........
    }
    virtual void SendMessage(string message){
        
        // Opt1: MobileMessagerBase::WriteText();
        messager->WriteText();
        //........
    }
    virtual void SendPicture(Image image){
        // Opt1: MobileMessagerBase::DrawShape();
        messager->DrawShape();
        //........
    }
};

class PCMessagerPerfect : public PCMessagerBase {
public:
    virtual void Login(string username, string password){
        PCMessagerBase::PlaySound(); // 例如完美版要求比简化版在登录时播放声音
        //********
        PCMessagerBase::Connect();
        //........
    }
    virtual void SendMessage(string message){
        PCMessagerBase::PlaySound();
        //********
        PCMessagerBase::WriteText();
        //........
    }
    virtual void SendPicture(Image image){
        PCMessagerBase::PlaySound();
        //********
        PCMessagerBase::DrawShape();
        //........
    }
};

class MobileMessagerPerfect : public MobileMessagerBase {
public:
    
    virtual void Login(string username, string password){
        MobileMessagerBase::PlaySound();
        //********
        MobileMessagerBase::Connect();
        //........
    }
    virtual void SendMessage(string message){
        MobileMessagerBase::PlaySound();
        //********
        MobileMessagerBase::WriteText();
        //........
    }
    virtual void SendPicture(Image image){
        MobileMessagerBase::PlaySound();
        //********
        MobileMessagerBase::DrawShape();
        //........
    }
};

void Process(){
        //编译时装配
        Messager *m =
            new MobileMessagerPerfect();
}
