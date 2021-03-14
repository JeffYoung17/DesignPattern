//应用程序开发人员
class Application : public Library {
protected:
	virtual bool Step2(){
		//... 子类重写实现
    }

    virtual void Step4() {
		//... 子类重写实现
    }
};

int main()
	{
		// new Application()通过默认构造函数申请动态内存,返回派生类的指针
		// 派生类的指针可以隐含转换为基类的指针
	    Library* pLib=new Application();
	    lib->Run();

		delete pLib;
	}
}
