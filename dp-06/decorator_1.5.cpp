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

//扩展操作
// Optx代表优化的步骤x
// 通过Opt1和Opt2以后发现几个类的类体完全相同
// 则Opt3为: 
class CryptoStream : public Stream {
    Stream* stream;
}
/**
 * 相当于File,Network和Memory三个流类是通过组合的方式
 * 放到了Crypto,Buffered两种功能的流类里面
 * 同时这两个流类还是需要继承Stream基类,保留流类本身的接口规范

 */

class CryptoFileStream { //Opt1 :public FileStream{
public:
    // !!!用组合替代继承
    // Opt2: FileStream* stream;
    // !!! 编译时一样, 运行时(未来)不一样
    Stream* stream; // 未来: =new FileStream();
    virtual char Read(int number){
       
        //额外的加密操作...
        // Opt1: FileStream::Read(number);//读文件流
        stream->Read(number);
        
    }
    virtual void Seek(int position){
        //额外的加密操作...
        // Opt1: FileStream::Seek(position);//定位文件流
        //额外的加密操作...
        stream->Seek(position);
    }
    virtual void Write(byte data){
        //额外的加密操作...
        // Opt1: FileStream::Write(data);//写文件流
        //额外的加密操作...
        stream->Write(data);
    }
};

class CryptoNetworkStream { // Opt1: public NetworkStream{
public:

    // !!!用组合替代继承
    // Opt2: NetworkStream* stream;
    Stream* stream; // = new NetworkStream();
    virtual char Read(int number){
        
        //额外的加密操作...
        // Opt1: NetworkStream::Read(number);//读网络流
        stream->Read(number);
    }
    virtual void Seek(int position){
        //额外的加密操作...
        // Opt1: NetworkStream::Seek(position);//定位网络流
        //额外的加密操作...
        stream->Seek(position);
    }
    virtual void Write(byte data){
        //额外的加密操作...
        // Opt1: NetworkStream::Write(data);//写网络流
        //额外的加密操作...
        stream->Write(data);
    }
};

class CryptoMemoryStream { // Opt1: public MemoryStream{
public:
    // Opt2: MemoryStream* stream;
    Stream* stream; // = new MemoryStream();
    virtual char Read(int number){
        
        //额外的加密操作...
        // Opt1: MemoryStream::Read(number);//读内存流
        stream->Read(number);
    }
    virtual void Seek(int position){
        //额外的加密操作...
        // Opt1: MemoryStream::Seek(position);//定位内存流
        //额外的加密操作...
        stream->Seek(position);
    }
    virtual void Write(byte data){
        //额外的加密操作...
        // Opt1: MemoryStream::Write(data);//写内存流
        //额外的加密操作...
        stream->Write(data);
    }
};

class BufferedFileStream : public FileStream{
    //...
};

class BufferedNetworkStream : public NetworkStream{
    //...
};

class BufferedMemoryStream : public MemoryStream{
    //...
}




class CryptoBufferedFileStream :public FileStream{
public:
    virtual char Read(int number){
        
        //额外的加密操作...
        //额外的缓冲操作...
        FileStream::Read(number);//读文件流
    }
    virtual void Seek(int position){
        //额外的加密操作...
        //额外的缓冲操作...
        FileStream::Seek(position);//定位文件流
        //额外的加密操作...
        //额外的缓冲操作...
    }
    virtual void Write(byte data){
        //额外的加密操作...
        //额外的缓冲操作...
        FileStream::Write(data);//写文件流
        //额外的加密操作...
        //额外的缓冲操作...
    }
};



void Process(){

    // 运行时装配
    // CryptoFileStream *fs1 = new CryptoFileStream();

    // 需要构造器去初始化CryptoStream中的"多态"Stream* stream
    FileStream* s1 = new FileStream();
    CryptoStream* s2 = new CryptoStream(s1); 

    // BufferedFileStream *fs2 = new BufferedFileStream();
    BufferedStream* s3 = new BufferStream(s1); 
    
    // CryptoBufferedFileStream *fs3 =new CryptoBufferedFileStream();
    // 套娃: 此处传入的s2是一个加密文件流对象,再传给BufferedStream的Stream,功能叠加!!!
    BufferedStream* s4 = new BufferedStream(s2);

    // 编译时不存在加密文件流,缓存文件流,而是在运行时通过组合的方式进行装配
}