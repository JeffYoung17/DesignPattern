/**
 * brief: =decorator_1.5.cpp
 * 还可以进一步优化
 */
//业务操作
class Stream{

public：
    virtual char Read(int number)=0;
    virtual void Seek(int position)=0;
    virtual void Write(char data)=0;
    
    virtual ~Stream(){}
};

//主体类
class FileStream: public Stream{
public:
    virtual char Read(int number){
        //读文件流
    }
    virtual void Seek(int position){
        //定位文件流
    }
    virtual void Write(char data){
        //写文件流
    }

};

class NetworkStream :public Stream{
public:
    virtual char Read(int number){
        //读网络流
    }
    virtual void Seek(int position){
        //定位网络流
    }
    virtual void Write(char data){
        //写网络流
    }
};

class MemoryStream :public Stream{
public:
    virtual char Read(int number){
        //读内存流
    }
    virtual void Seek(int position){
        //定位内存流
    }
    virtual void Write(char data){
        //写内存流
    }
};

// Opt: 发现Crypto和Buffered这些"二级功能"的类中有相同的Stream* stream
// 因此把相同的内容"往上提",设计一个中间类, 即装饰类
class DecoratorStream: public Stream {
protected: 
    Stream* stream;
public:
    DecoratorStream(Stream* stm):stream(stm) {}
    virtual char Read(int number);
    virtual void Seek(int position);
    virtual void Write(byte data);
}

//扩展操作
class CryptoStream: public DecoratorStream { // Opt: public Stream {
    // Opt: Stream* stream;//...
public:
    // Opt: CryptoStream(Stream* stm):stream(stm){
    CryptoStream(Stream* stm):DecoratorStream(stm){ // 调用上一级基类的构造器
    
    }
    
    virtual char Read(int number){
       
        //额外的加密操作...
        stream->Read(number);//读文件流 // 通过组合实现的动态特质
    }
    virtual void Seek(int position){
        //额外的加密操作...
        stream->Seek(position);//定位文件流
        //额外的加密操作...
    }
    virtual void Write(byte data){
        //额外的加密操作...
        stream->Write(data);//写文件流
        //额外的加密操作...
    }
};

// 同理
class BufferedStream : public Stream{
    Stream* stream;//...
public:
    BufferedStream(Stream* stm):stream(stm){
        
    }
    //...
};

void Process(){

    //运行时装配
    FileStream* s1=new FileStream();
    CryptoStream* s2=new CryptoStream(s1);
    
    BufferedStream* s3=new BufferedStream(s1);
    
    BufferedStream* s4=new BufferedStream(s2);

}