//Ӧ�ó��򿪷���Ա
class Application : public Library {
protected:
	virtual bool Step2(){
		//... ������дʵ��
    }

    virtual void Step4() {
		//... ������дʵ��
    }
};

int main()
	{
		// new Application()ͨ��Ĭ�Ϲ��캯�����붯̬�ڴ�,�����������ָ��
		// �������ָ���������ת��Ϊ�����ָ��
	    Library* pLib=new Application();
	    lib->Run();

		delete pLib;
	}
}
